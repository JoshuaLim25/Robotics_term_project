#!/usr/bin/env python3
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from action_interface.action import Robot
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from std_msgs.msg import Header
from builtin_interfaces.msg import Duration

from sensor_msgs.msg import JointState

# The arm joints to control.
ARM_JOINTS = ['shoulder_to_shoulder_joint', 'upper_arm_to_elbow']

class RobotClient(Node):
    def __init__(self):
        super().__init__('robot_client')
        # Create action clients for the wheel and arm actions.
        self.wheel_client = ActionClient(self, Robot, 'robot')
        self.arm_client = ActionClient(self, FollowJointTrajectory,
                                       '/joint_trajectory_controller/follow_joint_trajectory')
        # Storage for the latest joint state values for our arm joints.
        self.current_arm_positions = {}
        # Subscribe to joint states so we know where the arm is.
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)

    def joint_state_callback(self, msg):
        # Update our stored positions for the arm joints.
        for i, name in enumerate(msg.name):
            if name in ARM_JOINTS:
                self.current_arm_positions[name] = msg.position[i]

    def drive_and_move_arm(self, drive_time, offset1, offset2):
        # Save user-specified offsets.
        self.drive_time = drive_time
        self.arm_offset1 = offset1
        self.arm_offset2 = offset2
        self.get_logger().info("Starting wheel action...")
        self.send_wheel_goal()

    def send_wheel_goal(self):
        # Build and send the wheel goal.
        goal_msg = Robot.Goal()
        goal_msg.drive_time = self.drive_time
        # Speeds remain fixed.
        goal_msg.v_x = 0.02
        goal_msg.w_z = 0.0

        self.wheel_client.wait_for_server()
        self.get_logger().info("Sending wheel goal...")
        wheel_future = self.wheel_client.send_goal_async(goal_msg)
        wheel_future.add_done_callback(self.on_wheel_done)

    def on_wheel_done(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Wheel goal rejected')
            return

        self.get_logger().info('Wheel goal accepted')
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_wheel_result)

    def on_wheel_result(self, future):
        self.get_logger().info('Wheel motion complete. Now sending arm goal...')
        self.send_arm_goal()

    def send_arm_goal(self):
        # Ensure we have the current arm positions for all joints.
        if not all(joint in self.current_arm_positions for joint in ARM_JOINTS):
            self.get_logger().warn("Arm joint states not available yet. Waiting...")
            while not all(joint in self.current_arm_positions for joint in ARM_JOINTS):
                rclpy.spin_once(self, timeout_sec=0.1)

        # Retrieve current positions for the specified arm joints.
        current_positions = [self.current_arm_positions[j] for j in ARM_JOINTS]
        # Compute the target positions as the current positions plus the user-provided offsets.
        target_positions = [
            current_positions[0] + self.arm_offset1,
            current_positions[1] + self.arm_offset2
        ]

        # Build the trajectory message.
        goal_msg = FollowJointTrajectory.Goal()
        traj = JointTrajectory()
        traj.header.stamp = self.get_clock().now().to_msg()
        traj.header.frame_id = 'base_link'
        traj.joint_names = ARM_JOINTS

        # First point: starting at the current arm positions.
        start_point = JointTrajectoryPoint()
        start_point.positions = current_positions
        start_point.time_from_start = Duration(sec=0, nanosec=0)

        # Second point: move by the specified offsets (relative move).
        target_point = JointTrajectoryPoint()
        target_point.positions = target_positions
        target_point.velocities = [0.0, 0.0]
        # Adjust the duration if needed.
        target_point.time_from_start = Duration(sec=2, nanosec=0)

        traj.points.append(start_point)
        traj.points.append(target_point)
        goal_msg.trajectory = traj

        self.arm_client.wait_for_server()
        self.get_logger().info(f"Sending arm goal: moving from {current_positions} to {target_positions}")
        arm_future = self.arm_client.send_goal_async(goal_msg)
        arm_future.add_done_callback(self.on_arm_done)

    def on_arm_done(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Arm goal rejected')
            return

        self.get_logger().info('Arm goal accepted')
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_arm_result)

    def on_arm_result(self, future):
        self.get_logger().info('Arm motion complete. Shutting down.')
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    robot_client = RobotClient()

    # Request user input.
    drive_time = float(input("Enter the drive duration (in seconds): "))
    offset1 = float(input("Enter the arm displacement for joint 1: "))
    offset2 = float(input("Enter the arm displacement for joint 2: "))

    robot_client.drive_and_move_arm(drive_time, offset1, offset2)
    rclpy.spin(robot_client)


if __name__ == '__main__':
    main()

