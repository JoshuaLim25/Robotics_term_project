# CLIENT

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
# from custom_action_interfaces.action import Robot
from action_interface.action import Robot

class RobotClient(Node):
    def __init__(self):
        super().__init__('move_robot_client')
        self.action_client = ActionClient(self, Robot, 'move_robot')

    def send_goal(self, drive_time, v_x, w_z):
        goal_msg = Robot.Goal()
        goal_msg.drive_time = drive_time
        goal_msg.v_x = v_x
        goal_msg.w_z = w_z

        self.get_logger().info(f'Sending goal: drive_time={drive_time}s, v_x={v_x}m/s, w_z={w_z}rad/s')

        self.action_client.wait_for_server()
        self._send_goal_future = self.action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            rclpy.shutdown()
            return

        self.get_logger().info('Goal accepted')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Feedback: {feedback.percent_complete}% complete')

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Final Result: {result.success}')
        rclpy.shutdown()  # Exit the program properly

def main():
    rclpy.init()
    client = RobotClient()

    # Ask user for input
    drive_time = float(input("Enter drive time (seconds): "))
    v_x = float(input("Enter linear velocity (m/s): "))
    w_z = float(input("Enter angular velocity (rad/s): "))

    # Send goal to server
    client.send_goal(drive_time, v_x, w_z)

    # Ensure the result future exists before waiting
    while not hasattr(client, '_get_result_future'):
        rclpy.spin_once(client)  # Wait for goal to be accepted

    # Now we can safely wait for the result
    rclpy.spin_until_future_complete(client, client._get_result_future)

    # Clean up and exit
    client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


