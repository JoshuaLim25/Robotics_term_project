import time

import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from action_interface.action import Robot


class RobotActionServer(Node):

    def __init__(self):
        super().__init__('robot_action_server')
        self._action_server = ActionServer(
            self,
            Robot,
            'robot',
            self.execute_callback)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')

        feedback_msg = Robot.Feedback()
        feedback_msg.partial_sequence = [0, 1]

        for i in range(1, goal_handle.request.order):
            feedback_msg.partial_sequence.append(
                feedback_msg.partial_sequence[i] + feedback_msg.partial_sequence[i-1])
            self.get_logger().info('Feedback: {0}'.format(feedback_msg.partial_sequence))
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)

        goal_handle.succeed()


        result = Robot.Result()
        result.sequence = feedback_msg.partial_sequence
        return result


def main(args=None):
    rclpy.init(args=args)

    robot_action_server = RobotActionServer()

    rclpy.spin(robot_action_server)


if __name__ == '__main__':
    main()
