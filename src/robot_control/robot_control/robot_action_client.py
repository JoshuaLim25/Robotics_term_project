import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from action_interface.action import Robot
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from std_msgs.msg import Header
from builtin_interfaces.msg import Duration

# Constant for arm joint names
ARM_JOINTS = ['shoulder_to_shoulder_joint', 'upper_arm_to_elbow']

class RobotClient(Node):
    def __init__(self):
        super().__init__('robot_client')
        # Create action clients for wheel and arm actions.
        self.wheel_client = ActionClient(self, Robot, 'robot')
        self.arm_client = ActionClient(self, FollowJointTrajectory, '/joint_trajectory_controller/follow_joint_trajectory')

    def drive_and_move_arm(self, drive_time, pos1, pos2):
        # Save the inputs so they are accessible in callbacks.
        self.drive_time = drive_time
        self.arm_pos1 = pos1
        self.arm_pos2 = pos2
        self.get_logger().info("Starting wheel action...")
        self.send_wheel_goal()

    def send_wheel_goal(self):
        # Build the wheel goal using the custom Robot action.
        goal_msg = Robot.Goal()
        goal_msg.drive_time = self.drive_time
        goal_msg.v_x = 0.2
        goal_msg.w_z = 0.2
        # goal_msg.v_x = 0.05   # You can extend this to use user input if needed.
        # goal_msg.w_z = 0.05

        # Wait for the server and send the goal.
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
        # Build the trajectory message for the arm.
        goal_msg = FollowJointTrajectory.Goal()
        traj = JointTrajectory()
        traj.header.stamp = self.get_clock().now().to_msg()
        traj.header.frame_id = 'base_link'
        traj.joint_names = ARM_JOINTS

        point = JointTrajectoryPoint()
        point.positions = [self.arm_pos1, self.arm_pos2]
        point.velocities = [0.0, 0.0]
        point.time_from_start = Duration(sec=2, nanosec=0)
        traj.points.append(point)
        goal_msg.trajectory = traj

        # Wait for the arm action server and send the goal.
        self.arm_client.wait_for_server()
        self.get_logger().info("Sending arm goal...")
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

    # Ask the user for input parameters.
    drive_time = float(input("Enter the drive duration (in seconds): "))
    pos1 = float(input("Enter the first arm position: "))
    pos2 = float(input("Enter the second arm position: "))

    # Start the sequence: first the wheel motion, then the arm motion.
    robot_client.drive_and_move_arm(drive_time, pos1, pos2)
    rclpy.spin(robot_client)


if __name__ == '__main__':
    main()

