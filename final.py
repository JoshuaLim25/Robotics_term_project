#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from apriltag_msgs.msg import AprilTagDetectionArray
from nav2_simple_commander.robot_navigator import BasicNavigator
import tf2_ros
import tf2_geometry_msgs
import numpy as np
import time

class GoalBoxFollower(Node):
    def __init__(self):
        super().__init__('goal_box_follower')
        # Initialize Nav2 and bring up lifecycle-managed nodes
        self.navigator = BasicNavigator()
        self.get_logger().info('Initializing Nav2 lifecycle...')
        self.navigator.lifecycleStartup()
        # self.navigator.waitUntilNav2Active()
        self.get_logger().info('Nav2 active. Starting patrol.')

        # Record home pose
        self.home_pose = PoseStamped()
        self.home_pose.header.frame_id = 'map'
        self.home_pose.pose.position.x = 1.25
        self.home_pose.pose.position.y = -1.0
        self.home_pose.pose.orientation.w = 1.0

        # TF buffer for transforms
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # Subscribe to AprilTag detections
        self.box_detection = None
        self.create_subscription(
            AprilTagDetectionArray,
            'detections',
            self._detections_callback,
            10)

        # Patrol waypoints in map frame
        self.waypoints = self._make_waypoints()

    def _make_waypoints(self):
        pixel_points = [
            [625,1450,0], [1000,1450,45], [1000,1300,90], [750,1350,180],
            [440,1200,90], [440,1000,45], [970,800,90],  [970,50,45]
        ]
        origin = [-5.0, -2.5]
        wps = []
        for x_px, y_px, deg in pixel_points:
            p = PoseStamped()
            p.header.frame_id = 'map'
            p.pose.position.x = x_px * 0.01 + origin[0]
            p.pose.position.y = (1600 - y_px) * 0.01 + origin[1]
            th = np.radians(deg)
            p.pose.orientation.w = np.cos(0.5 * th)
            p.pose.orientation.z = np.sin(0.5 * th)
            wps.append(p)
        return wps

    def _detections_callback(self, msg: AprilTagDetectionArray):
        # Process detections: ignore ids >30 (localization), detect ids 2-15 as goal boxes
        for det in msg.detections:
            if not det.id:
                continue
            tag_id = det.id[0]
            if 2 <= tag_id <= 15:
                self.box_detection = det.pose
                self.get_logger().info(f'Goal box tag {tag_id} detected')
                return
        # clear if none
        self.box_detection = None

    def _transform_to_map(self, pose_camera: PoseStamped) -> PoseStamped:
        try:
            trans = self.tf_buffer.lookup_transform(
                'map', pose_camera.header.frame_id, rclpy.time.Time())
            return tf2_geometry_msgs.do_transform_pose(pose_camera, trans)
        except Exception as e:
            self.get_logger().warn(f'TF transform error: {e}')
            return None

    def _navigate_to(self, pose: PoseStamped):
        pose.header.stamp = self.navigator.get_clock().now().to_msg()
        self.navigator.goToPose(pose)
        while not self.navigator.isTaskComplete():
            rclpy.spin_once(self, timeout_sec=0.1)

    def run(self):
        idx = 0
        try:
            while rclpy.ok():
                # Patrol
                wp = self.waypoints[idx]
                self.get_logger().info(f'Patrol to waypoint {idx}')
                self._navigate_to(wp)
                # During patrol, check for box
                while not self.navigator.isTaskComplete():
                    rclpy.spin_once(self, timeout_sec=0.1)
                    time.sleep(0.1)
                    if self.box_detection:
                        self.get_logger().info('Stopping patrol for box')
                        self.navigator.cancelTask()
                        # Transform detection to map frame
                        map_pose = self._transform_to_map(self.box_detection)
                        if map_pose:
                            # Approach box
                            self.get_logger().info('Approaching box')
                            # offset 0.2m back along yaw
                            q = map_pose.pose.orientation
                            yaw = np.arctan2(2*(q.w*q.z), 1-2*(q.z*q.z))
                            approach = PoseStamped()
                            approach.header.frame_id = 'map'
                            approach.pose.position.x = map_pose.pose.position.x - 0.2*np.cos(yaw)
                            approach.pose.position.y = map_pose.pose.position.y - 0.2*np.sin(yaw)
                            approach.pose.orientation = map_pose.pose.orientation
                            self._navigate_to(approach)
                            # Simulate pickup
                            self.get_logger().info('Picking up box')
                            time.sleep(2.0)
                            # Return home
                            self.get_logger().info('Returning home')
                            self._navigate_to(self.home_pose)
                            self.get_logger().info('Completed mission')
                        return
                # next waypoint
                idx = (idx + 1) % len(self.waypoints)
        except KeyboardInterrupt:
            pass
        finally:
            self.get_logger().info('Shutting down')
            self.navigator.lifecycleShutdown()
            self.destroy_node()
            rclpy.shutdown()

if __name__ == '__main__':
    rclpy.init()
    node = GoalBoxFollower()
    node.run()

