import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.duration import Duration
from sensor_msgs.msg import JointState  # Correct message type for your robot
# from custom_action_interfaces.action import MoveRobot
from action_interface.action import Robot

class RobotServer(Node):
    def __init__(self):
        super().__init__('move_robot_server')
        self.action_server = ActionServer(self, Robot, 'move_robot', self.execute_callback)
        self.joint_state_publisher = self.create_publisher(JointState, '/arduino/commands', 10)  # Correct topic
        self.get_logger().info("RobotServer started, waiting for goals...")

    def execute_callback(self, goal_handle):
        self.get_logger().info(f'Received goal: drive_time={goal_handle.request.drive_time}s, '
                               f'v_x={goal_handle.request.v_x}m/s, w_z={goal_handle.request.w_z}rad/s')

        joint_msg = JointState()
        joint_msg.velocity = [goal_handle.request.v_x, goal_handle.request.v_x, goal_handle.request.w_z, goal_handle.request.w_z]  # Adjust velocity array

        start_time = self.get_clock().now()
        end_time = start_time + Duration(seconds=goal_handle.request.drive_time)
        feedback_msg = Robot.Feedback()

        # **Continuously publish movement commands**
        while self.get_clock().now() < end_time:
            self.joint_state_publisher.publish(joint_msg)  # Send commands continuously
            elapsed_time = (self.get_clock().now() - start_time).nanoseconds / 1e9
            feedback_msg.percent_complete = min((elapsed_time / goal_handle.request.drive_time) * 100, 100.0)
            goal_handle.publish_feedback(feedback_msg)
            self.get_logger().info(f'Feedback: {feedback_msg.percent_complete:.1f}% complete')

            self.get_clock().sleep_for(Duration(seconds=0.1))  # Send every 100ms

        # **Ensure the robot stops**
        self.get_logger().info('Stopping robot...')
        stop_msg = JointState()
        stop_msg.velocity = [0.0, 0.0, 0.0, 0.0]  # Stop all motors

        for _ in range(10):  # Ensure stopping
            self.joint_state_publisher.publish(stop_msg)
            self.get_clock().sleep_for(Duration(seconds=0.1))

        self.get_logger().info("Robot stopped successfully.")

        goal_handle.succeed()
        result = Robot.Result()
        result.success = True
        return result

def main():
    rclpy.init()
    move_robot_server = RobotServer()
    rclpy.spin(move_robot_server)
    move_robot_server.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()




