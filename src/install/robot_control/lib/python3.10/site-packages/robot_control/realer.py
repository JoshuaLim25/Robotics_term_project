#!/usr/bin/env python3
import math
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from action_interface.action import Robot
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from std_msgs.msg import Header
from builtin_interfaces.msg import Duration
from sensor_msgs.msg import JointState


ARM_JOINTS = ['shoulder_to_shoulder_joint', 'upper_arm_to_elbow']


class RobotClient(Node):
    def __init__(self):
        super().__init__('robot_client')
        self.wheel_client = ActionClient(self, Robot, 'robot')
        self.arm_client = ActionClient(self, FollowJointTrajectory,
                                       '/joint_trajectory_controller/follow_joint_trajectory')
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        self.current_arm_positions = {}

    def joint_state_callback(self, msg):
        for i, name in enumerate(msg.name):
            if name in ARM_JOINTS:
                self.current_arm_positions[name] = msg.position[i]

    def execute(self, turn_angle, drive_duration, arm_offset1, arm_offset2):
        self.turn_angle = turn_angle
        self.drive_duration = drive_duration
        self.arm_offset1 = arm_offset1
        self.arm_offset2 = arm_offset2

        if abs(self.turn_angle) > 0.1:
            self.get_logger().info("Starting turn...")
            self.send_turn_goal()
        else:
            self.get_logger().info("No turn needed, proceeding to drive.")
            self.send_drive_goal()

    def send_turn_goal(self):
        angle_rad = self.turn_angle * math.pi / 180.0
        TURN_RATE = 0.5  # rad/s
        turn_duration = abs(angle_rad) / TURN_RATE

        goal_msg = Robot.Goal()
        goal_msg.drive_time = turn_duration
        goal_msg.v_x = 0.0
        goal_msg.w_z = TURN_RATE if angle_rad > 0 else -TURN_RATE

        self.wheel_client.wait_for_server()
        self.get_logger().info(f"Turning {self.turn_angle}° over {turn_duration:.2f}s")
        future = self.wheel_client.send_goal_async(goal_msg)
        future.add_done_callback(self.on_turn_complete)

    def on_turn_complete(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Turn goal rejected!")
            return
        self.get_logger().info("Turn complete, driving straight.")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_turn_result)

    def on_turn_result(self, future):
        self.send_drive_goal()

    def send_drive_goal(self):
        goal_msg = Robot.Goal()
        goal_msg.drive_time = self.drive_duration
        goal_msg.v_x = 0.05
        goal_msg.w_z = 0.0  # Force zero rotation

        self.wheel_client.wait_for_server()
        self.get_logger().info(f"Driving straight for {self.drive_duration}s")
        future = self.wheel_client.send_goal_async(goal_msg)
        future.add_done_callback(self.on_drive_complete)

    def on_drive_complete(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Drive goal rejected!")
            return
        self.get_logger().info("Drive complete, moving arm.")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_drive_result)

    def on_drive_result(self, future):
        self.send_arm_goal()

    def send_arm_goal(self):
        while not all(joint in self.current_arm_positions for joint in ARM_JOINTS):
            self.get_logger().warn("Waiting for joint states...")
            rclpy.spin_once(self, timeout_sec=0.1)

        current_positions = [self.current_arm_positions[j] for j in ARM_JOINTS]
        target_positions = [
            current_positions[0] + self.arm_offset1,
            current_positions[1] + self.arm_offset2
        ]

        goal_msg = FollowJointTrajectory.Goal()
        traj = JointTrajectory()
        traj.header.stamp = self.get_clock().now().to_msg()
        traj.header.frame_id = 'base_link'
        traj.joint_names = ARM_JOINTS

        start = JointTrajectoryPoint()
        start.positions = current_positions
        start.time_from_start = Duration(sec=0)

        target = JointTrajectoryPoint()
        target.positions = target_positions
        target.velocities = [0.0, 0.0]
        target.time_from_start = Duration(sec=2)

        traj.points = [start, target]
        goal_msg.trajectory = traj

        self.arm_client.wait_for_server()
        self.get_logger().info(f"Moving arm from {current_positions} to {target_positions}")
        future = self.arm_client.send_goal_async(goal_msg)
        future.add_done_callback(self.on_arm_complete)

    def on_arm_complete(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Arm goal rejected!")
            return
        self.get_logger().info("Arm motion complete.")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_arm_result)

    def on_arm_result(self, future):
        self.get_logger().info("Sequence complete. Shutting down.")
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    robot_client = RobotClient()

    turn_angle = float(input("Enter the turn angle (-90 to 90 degrees): "))
    drive_duration = float(input("Enter the drive duration (seconds): "))
    arm_offset1 = float(input("Enter arm displacement for joint 1: "))
    arm_offset2 = float(input("Enter arm displacement for joint 2: "))

    robot_client.execute(turn_angle, drive_duration, arm_offset1, arm_offset2)
    rclpy.spin(robot_client)


if __name__ == '__main__':
    main()

