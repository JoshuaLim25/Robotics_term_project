import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from control_msgs.action import FollowJointTrajectory

from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from std_msgs.msg import Header
from builtin_interfaces.msg import Duration
from action_interface.action import Robot
# Maybe need:
# from action_interface.action import Robot
# trajectory_msgs/JointTrajectory
# FollowJointTrajectory
# control_msgs/action/FollowJointTrajectory
#from control_msgs.action import FollowJointTrajectory


'''
- action type, topic:
client uses the FollowJointTrajectory action (from the control_msgs package) and connects to the /joint_trajectory_controller/follow_joint_trajectory server.

- Trajectory message:
goal message builds a complete JointTrajectory: a header with a stamp and frame_id, correct joint names from the simulation.py file, and a single trajectory point (with positions, velocities, and a time_from_start).
'''
 

arm_joints = ['shoulder_to_shoulder_joint', 'upper_arm_to_elbow']
# trajectory.joint_names
# trajectory.points.positions
# trajectory.points.velocities
# trajectory.points.time_from_start.sec

class ArmActionClient(Node):

    def __init__(self):
        super().__init__('robot_arm_action_client')
        # self._action_client = ActionClient(self, Robot, 'robot')
        # self._action_client = ActionClient(self, JointTrajectory, 'robot')
        # self._action_client = ActionClient(self, FollowJointTrajectory, 'robot')
        self._action_client = ActionClient(self, FollowJointTrajectory, '/joint_trajectory_controller/follow_joint_trajectory')
        self.joint_names = ['shoulder_to_shoulder_joint', 'upper_arm_to_elbow']
        self.frame_id = 'base_link'

    def send_goal(self, pos1, pos2):
        goal_msg = FollowJointTrajectory.Goal()

        # # Build the JointTrajectory ms (for the goal)
        # goal_msg.trajectory.header = Header()
        # goal_msg.trajectory.header.stamp = self.get_clock().now().to_msg()
        # goal_msg.trajectory.header.frame_id = self.frame_id
        # goal_msg.trajectory.joint_names = self.joint_names
        
        # Build the trajectory message
        traj = JointTrajectory()
        traj.header = Header()
        traj.header.stamp = self.get_clock().now().to_msg()
        traj.header.frame_id = self.frame_id
        traj.joint_names = self.joint_names


        # Create a trajectory point (one point goal)
        point = JointTrajectoryPoint()

        point.positions = [pos1, pos2] # went back towards us
        
        # point.positions = [0.5, 1.0] # went back towards us
        # point.positions = [-0.5, -0.25] # went forward
        point.velocities = [0.0, 0.0] # zero to start
        # point.velocities = [1.0, 1.0] # zero to start
        point.time_from_start = Duration(sec=2, nanosec=0)
        # goal_msg.trajectory.points.append(point)
# changed
        traj.points.append(point)
        goal_msg.trajectory = traj # convenience

        self.get_logger().info("Waiting for arm action server...")
        self._action_client.wait_for_server()
        self.get_logger().info("Sending goal request...")
        #self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future = self._action_client.send_goal_async(goal_msg)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

#     def send_joint_trajectory(self):
#         #msg = JointTrajectory()
#         msg_arm = JointTrajectory()
#         msg_arm.header = Header()  
#         msg_arm.header.frame_id = self.frame_id  
#         msg_arm.joint_names = ["shoulder_to_shoulder_joint", "upper_arm_to_elbow"]
# 
#         point_arm = JointTrajectoryPoint()
#         point_arm.positions = [1.0, 0.5]
#         point_arm.velocities = [0.1, 0.2] 
#         point_arm.time_from_start.sec = 2
#         msg_arm.points.append(point_arm)
#       
# 
#         self._action_client.wait_for_server()         
#         self._send_joint_trajectory_future = self._action_client.send_goal_async(msg_arm, feedback_callback=self.feedback_callback)
#         # self._send_joint_trajectory_future = self._action_client.send_goal_async(msg_arm, feedback_callback=self.feedback_callback)
#         self._send_joint_trajectory_future.add_done_callback(self.goal_response_callback)
    
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected for arm')
            return

        self.get_logger().info('Goal accepted for arm')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        #self.get_logger().info('Result: {0}'.format(result.complete))
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        #self.get_logger().info('Received feedback: {0}'.format(feedback.percent_complete))
        self.get_logger().info(f'Received feedback {feedback.percent_complete}% complete')

#    def send_goal(self, drive_time):
#        goal_msg = Robot.Goal()
#    
#        goal_msg.drive_time = drive_time
#
#        goal_msg.v_x = 0.2
#        goal_msg.w_z = 0.2
#
#
#        # Create new JointTrajectory messages
#        msg_arm = JointTrajectory()
#        msg_arm.header = Header()  
#        msg_arm.header.frame_id = self.frame_id  
#        msg_arm.joint_names = arm_joints
# 
#
#        self._action_client.wait_for_server()
#        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
#        self._send_goal_future.add_done_callback(self.goal_response_callback)


def main(args=None):
    rclpy.init(args=args)

    action_client = ArmActionClient()
    pos1 = float(input("Enter the first position field: "))
    pos2 = float(input("Enter the second position field: "))

    action_client.send_goal(pos1, pos2)
    # action_client.send_joint_trajectory()

    rclpy.spin(action_client)
    

if __name__ == '__main__':
    main()
