#!/usr/bin/env python3
 
"""
Publishing Topics (ROS 2):
  Desired goal pose of the robotic arm
    /arm_controller/joint_trajectory - trajectory_msgs/JointTrajectory
   
-------
Author: Addison Sears-Collins
Date: April 29, 2024
"""
 
import rclpy
from rclpy.node import Node
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
from std_msgs.msg import Header
 
arm_joints = ['shoulder_to_shoulder_joint', 'upper_arm_to_elbow']

# self.joint_state.name = ["base_to_front_left_leg", "base_to_front_right_leg", "shoulder_to_shoulder_joint", "upper_arm_to_elbow"]
# trajectory.joint_names
# trajectory.points.positions
# trajectory.points.velocities
# trajectory.points.time_from_start.sec
 
class JointTrajectoryPublisherArm(Node):
    def __init__(self):
        super().__init__('robot_arm_action_client')    
  
        # Create publisher of the desired arm goal poses
        self.arm_pose_publisher = self.create_publisher(JointTrajectory, '/joint_trajectory_controller/JointTrajectoryController', 10)
 
        self.timer_period = 5.0  # seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
 
        self.frame_id = "base_link"
        
        # Desired time from the trajectory start to arrive at the trajectory point.
        # Needs to be less than or equal to the self.timer_period above to allow
        # the robotic arm to smoothly transition between points.
        self.duration_sec = 2
        self.duration_nanosec = 0.5 * 1e9 # (seconds * 1e9)
 
        # Set the desired goal poses for the robotic arm.
        self.arm_positions = []
        self.arm_positions.append([0.0, 0.0, 0.0, 0.0, 0.0, 0.0]) # Home location
        self.arm_positions.append([-1.345, -1.23, 0.264, -0.296, 0.389, -1.5]) # Goal location
        self.arm_positions.append([-1.345, -1.23, 0.264, -0.296, 0.389, -1.5]) 
        self.arm_positions.append([0.0, 0.0, 0.0, 0.0, 0.0, 0.0]) # Home location
 
        # Keep track of the current trajectory we are executing
        self.index = 0
        
        self.trajectory = []
        self.joint_names = ["base_to_front_left_leg", "base_to_front_right_leg", "shoulder_to_shoulder_joint", "upper_arm_to_elbow"]
 
    def timer_callback(self):
        """Set the goal pose for the robotic arm.
     
        """

        # Create new JointTrajectory messages
        msg_arm = JointTrajectory()
        msg_arm.header = Header()  
        msg_arm.header.frame_id = self.frame_id  
        msg_arm.joint_names = arm_joints
 
        # Create JointTrajectoryPoints
        point_arm = JointTrajectoryPoint()
        point_arm.positions = self.arm_positions[self.index]
        point_arm.time_from_start = Duration(sec=int(self.duration_sec), nanosec=int(self.duration_nanosec))  # Time to next position
        msg_arm.points.append(point_arm)
        self.arm_pose_publisher.publish(msg_arm)
 
        # Reset the index
        if self.index == len(self.arm_positions) - 1:
            self.index = 0
        else:
            self.index = self.index + 1
     
def main(args=None):
   
    # Initialize the rclpy library and make the node
    rclpy.init(args=args)
    arm_joint_publisher = JointTrajectoryPublisherArm()
   
    # spin the node so the callback function is called.
    rclpy.spin(arm_joint_publisher)
     
    # cleanup steps
    arm_joint_publisher.destroy_node()
    rclpy.shutdown()
   
if __name__ == '__main__':
  main()
