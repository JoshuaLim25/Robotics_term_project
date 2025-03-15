import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from action_interface.action import Robot


class RobotActionClient(Node):

    def __init__(self):
        super().__init__('robot_action_client')
        self._action_client = ActionClient(self, Robot, 'robot')

    def send_goal(self, drive_time):
        goal_msg = Robot.Goal()
        goal_msg.drive_time = drive_time
        goal_msg.v_x = .2  # TODO, take user input
        goal_msg.w_z = .2

        self._action_client.wait_for_server()

        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected for wheels')
            return

        self.get_logger().info('Goal accepted for wheels')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: {0}'.format(result.complete))
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info('Received feedback: {0}'.format(feedback.percent_complete))


def main(args=None):
    rclpy.init(args=args)

    action_client = RobotActionClient()

    action_client.send_goal(10.0)

    rclpy.spin(action_client)


if __name__ == '__main__':
    main()
