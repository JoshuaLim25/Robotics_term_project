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

# The names of the arm joints.
ARM_JOINTS = ['shoulder_to_shoulder_joint', 'upper_arm_to_elbow']

class RobotClient(Node):
    def __init__(self):
        super().__init__('robot_client')
        # Create action clients for wheel and arm actions.
        self.wheel_client = ActionClient(self, Robot, 'robot')
        self.arm_client = ActionClient(self, FollowJointTrajectory,
                                       '/joint_trajectory_controller/follow_joint_trajectory')
        # Subscribe to joint states to obtain current arm positions.
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        self.current_arm_positions = {}

    def joint_state_callback(self, msg):
        for i, name in enumerate(msg.name):
            if name in ARM_JOINTS:
                self.current_arm_positions[name] = msg.position[i]

    def drive_turn_drive_and_move_arm(self, turn_angle, drive_duration, arm_offset1, arm_offset2):
        self.turn_angle = turn_angle
        self.drive_duration = drive_duration
        self.arm_offset1 = arm_offset1
        self.arm_offset2 = arm_offset2

        if abs(self.turn_angle) < 1e-3:
            self.get_logger().info("No turning required, driving straight.")
            self.send_drive_goal()
        else:
            self.get_logger().info("Starting turn action...")
            self.send_turn_goal()

    def send_turn_goal(self):
        goal_msg = Robot.Goal()
        # Compute turn parameters.
        angle_rad = self.turn_angle * math.pi / 180.0
        TURN_RATE = 0.5  # Fixed turning speed (rad/s)
        turn_duration = abs(angle_rad) / TURN_RATE  # Duration to complete the turn
        goal_msg.drive_time = turn_duration
        goal_msg.v_x = 0.0  # No forward motion while turning
        # Set angular velocity based on the sign of the turn angle.
        goal_msg.w_z = TURN_RATE if angle_rad >= 0 else -TURN_RATE

        self.wheel_client.wait_for_server()
        self.get_logger().info(f"Sending turn goal: turn_angle={self.turn_angle}°, "
                               f"duration={turn_duration:.2f}s, w_z={goal_msg.w_z:.3f} rad/s")
        turn_future = self.wheel_client.send_goal_async(goal_msg)
        turn_future.add_done_callback(self.on_turn_done)

    def on_turn_done(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info("Turn goal rejected")
            return
        self.get_logger().info("Turn goal accepted")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_turn_result)

    def on_turn_result(self, future):
        self.get_logger().info("Turn action complete. Now driving straight...")
        self.send_drive_goal()

    def send_drive_goal(self):
        goal_msg = Robot.Goal()
        goal_msg.drive_time = self.drive_duration
        goal_msg.v_x = 0.05  # Forward velocity
        goal_msg.w_z = 0.0   # Ensure no rotation while driving straight

        self.wheel_client.wait_for_server()
        self.get_logger().info(f"Sending drive goal: drive_duration={self.drive_duration}s, "
                               f"v_x={goal_msg.v_x}, w_z={goal_msg.w_z}")
        drive_future = self.wheel_client.send_goal_async(goal_msg)
        drive_future.add_done_callback(self.on_drive_done)

    def on_drive_done(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info("Drive goal rejected")
            return
        self.get_logger().info("Drive goal accepted")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_drive_result)

    def on_drive_result(self, future):
        self.get_logger().info("Drive action complete. Now sending arm goal...")
        self.send_arm_goal()

    def send_arm_goal(self):
        # Wait until valid joint states are available.
        if not all(joint in self.current_arm_positions for joint in ARM_JOINTS):
            self.get_logger().warn("Arm joint states not available yet. Waiting...")
            while not all(joint in self.current_arm_positions for joint in ARM_JOINTS):
                rclpy.spin_once(self, timeout_sec=0.1)

        # Retrieve current arm joint positions.
        current_positions = [self.current_arm_positions[j] for j in ARM_JOINTS]
        # Calculate target positions by adding the user-specified offsets.
        target_positions = [
            current_positions[0] + self.arm_offset1,
            current_positions[1] + self.arm_offset2
        ]
        # Build a two-point trajectory (start at current, then move to target).
        goal_msg = FollowJointTrajectory.Goal()
        traj = JointTrajectory()
        traj.header.stamp = self.get_clock().now().to_msg()
        traj.header.frame_id = 'base_link'
        traj.joint_names = ARM_JOINTS

        start_point = JointTrajectoryPoint()
        start_point.positions = current_positions
        start_point.time_from_start = Duration(sec=0, nanosec=0)

        target_point = JointTrajectoryPoint()
        target_point.positions = target_positions
        target_point.velocities = [0.0, 0.0]
        target_point.time_from_start = Duration(sec=2, nanosec=0)

        traj.points.append(start_point)
        traj.points.append(target_point)
        goal_msg.trajectory = traj

        self.arm_client.wait_for_server()
        self.get_logger().info(f"Sending arm goal: from {current_positions} to {target_positions}")
        arm_future = self.arm_client.send_goal_async(goal_msg)
        arm_future.add_done_callback(self.on_arm_done)

    def on_arm_done(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info("Arm goal rejected")
            return
        self.get_logger().info("Arm goal accepted")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.on_arm_result)

    def on_arm_result(self, future):
        self.get_logger().info("Arm action complete. Shutting down.")
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    robot_client = RobotClient()

    # Get user inputs.
    # Turn angle in degrees (negative for left turn, positive for right turn, up to ±90)
    turn_angle = float(input("Enter the turn angle (in degrees, -90 to 90): "))
    # Duration for driving straight (in seconds).
    drive_duration = float(input("Enter the drive duration (in seconds): "))
    arm_offset1 = float(input("Enter the arm displacement for joint 1: "))
    arm_offset2 = float(input("Enter the arm displacement for joint 2: "))

    robot_client.drive_turn_drive_and_move_arm(turn_angle, drive_duration, arm_offset1, arm_offset2)
    rclpy.spin(robot_client)

if __name__ == '__main__':
    main()

