import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

import time
from action_interface.action import Robot
from geometry_msgs.msg import Twist



class RobotActionServer(Node):

    def __init__(self):
        super().__init__('robot_action_server') # node name
        self._action_server = ActionServer(
            self,
            Robot, # action type, from import on line 7 and Robot.action
            'robot', # action name
            self.execute_callback)

        self.pub_wheel = self.create_publisher(
            Twist,
            'diff_drive_controller/cmd_vel_unstamped',
            10
        )

        # self.pub_arm = self.create_publisher(
        #     Twist,
        #     # 'joint_trajectory_controller/',
        #     'arm_controller/command',
        #     10
        # )


    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        feedback_msg = Robot.Feedback()

        feedback_msg.percent_complete = 0.0
        t = int(10*goal_handle.request.drive_time)
        # t = int(5*goal_handle.request.drive_time)
        # t = int(2*goal_handle.request.drive_time)
        # t = int(0.2*goal_handle.request.drive_time)
        # t = int(0.05*goal_handle.request.drive_time)

        twist = Twist()
        twist.linear.x = goal_handle.request.v_x
        twist.angular.z = goal_handle.request.w_z

        # NOTE: modified from https://docs.ros.org/en/iron/Tutorials/Intermediate/Writing-an-Action-Server-Client/Py.html#publishing-feedback 
        for i in range(t):
            self.pub_wheel.publish(twist)
            feedback_msg.percent_complete = i/t
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(0.1) # 10 Hz

        self.get_logger().info('before result')

        result = Robot.Result()
        result.complete = True 
        self.get_logger().info('after result')
        goal_handle.succeed()
        return result


def main(args=None):
    rclpy.init(args=args)

    robot_action_server = RobotActionServer()

    rclpy.spin(robot_action_server)


if __name__ == '__main__':
    main()
