#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from action_msgs.msg import GoalStatus
from action_interface.action import Tag
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import numpy as np
import time


class TagSearchClient(Node):
    def __init__(self):
        super().__init__("tag_search_client")
        # Action client for tag finder
        self._tag_client = ActionClient(self, Tag, "tag_finder")
        # Navigator for Nav2: let client manage lifecycle
        self._navigator = BasicNavigator()
        self.get_logger().info("Starting Nav2 lifecycle via client...")
        self._navigator.lifecycleStartup()
        self.get_logger().info("Nav2 is active")
        # Build patrol waypoints
        self._waypoints = self._make_waypoints()
        super().__init__("tag_search_client")
        # Action client for tag finder
        self._tag_client = ActionClient(self, Tag, "tag_finder")
        # Navigator for Nav2 (assumes Nav2 is already active via launch)
        self._navigator = BasicNavigator()
        self.get_logger().info(
            "TagSearchClient initialized; assuming Nav2 stack is active"
        )
        # Build patrol waypoints
        self._waypoints = self._make_waypoints()

    def _make_waypoints(self):
        pixels = [
            [625, 1450, 0],
            [1000, 1450, 45],
            [1000, 1300, 90],
            [750, 1350, 180],
            [440, 1200, 90],
            [440, 1000, 45],
            [970, 800, 90],
            [970, 50, 45],
            [1100, 60, -90],
            [970, 180, -135],
            [750, 300, 135],
            [550, 50, 180],
            [720, 600, -90],
            [350, 750, -135],
            [440, 1000, -90],
            [500, 1350, 0],
        ]
        origin = [-5.0, -2.5]
        waypoints = []
        for x_px, y_px, deg in pixels:
            p = PoseStamped()
            p.header.frame_id = "map"
            p.pose.position.x = x_px * 0.01 + origin[0]
            p.pose.position.y = (1600 - y_px) * 0.01 + origin[1]
            th = np.radians(deg)
            p.pose.orientation.w = np.cos(0.5 * th)
            p.pose.orientation.z = np.sin(0.5 * th)
            waypoints.append(p)
        return waypoints

    def _detect_tag(self, timeout=0.5):
        # Non-blocking detection via tag_finder action
        if not self._tag_client.wait_for_server(timeout_sec=0.2):
            return None
        goal = Tag.Goal()
        goal.min_tag = 0
        goal.max_tag = 40
        send_goal = self._tag_client.send_goal_async(goal)
        t0 = self.get_clock().now().nanoseconds
        while not send_goal.done():
            rclpy.spin_once(self, timeout_sec=0.02)
            if (self.get_clock().now().nanoseconds - t0) > timeout * 1e9:
                return None
        goal_handle = send_goal.result()
        if not goal_handle.accepted:
            return None
        result_future = goal_handle.get_result_async()
        t0 = self.get_clock().now().nanoseconds
        while not result_future.done():
            rclpy.spin_once(self, timeout_sec=0.02)
            if (self.get_clock().now().nanoseconds - t0) > timeout * 1e9:
                return None
        status = result_future.result().status
        result = result_future.result().result
        if status == GoalStatus.STATUS_SUCCEEDED and result.tag != -1:
            return result
        return None

    def _approach_tag(self, x, y, theta):
        # Approach to 20cm in front of detected tag orientation
        dx = 0.2 * np.cos(theta)
        dy = 0.2 * np.sin(theta)
        target = PoseStamped()
        target.header.frame_id = "map"
        target.header.stamp = self._navigator.get_clock().now().to_msg()
        target.pose.position.x = x - dx
        target.pose.position.y = y - dy
        target.pose.orientation.w = np.cos(0.5 * theta)
        target.pose.orientation.z = np.sin(0.5 * theta)

        self.get_logger().info("Approaching tag at slow speed")
        self._navigator.goToPose(target)
        while not self._navigator.isTaskComplete():
            rclpy.spin_once(self, timeout_sec=0.05)
        self.get_logger().info("Arrived at tag")

    def run(self):
        idx = 0
        try:
            while rclpy.ok():
                # Patrol to next waypoint
                wp = self._waypoints[idx]
                wp.header.stamp = self._navigator.get_clock().now().to_msg()
                self.get_logger().info(f"Patrolling to waypoint {idx}")
                self._navigator.goToPose(wp)

                # While moving, check for tags
                while not self._navigator.isTaskComplete():
                    rclpy.spin_once(self, timeout_sec=0.05)
                    time.sleep(0.1)
                    tag_res = self._detect_tag()
                    if tag_res:
                        self.get_logger().info(f"Detected tag {tag_res.tag}")
                        self._navigator.cancelTask()
                        self._approach_tag(tag_res.x, tag_res.y, tag_res.orientation)
                        return
                idx = (idx + 1) % len(self._waypoints)
        except KeyboardInterrupt:
            pass
        finally:
            self.get_logger().info("Shutting down TagSearchClient")
            self.destroy_node()
            rclpy.shutdown()


if __name__ == "__main__":
    rclpy.init()
    client = TagSearchClient()
    client.run()
