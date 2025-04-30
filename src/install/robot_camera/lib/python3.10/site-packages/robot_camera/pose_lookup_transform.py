import rclpy
from rclpy.node import Node
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
from geometry_msgs.msg import TransformStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from tf_transformations import translation_matrix
from tf_transformations import quaternion_matrix
from tf_transformations import euler_matrix
from tf_transformations import translation_from_matrix
from tf_transformations import quaternion_from_matrix
import numpy as np

class FrameListener(Node):

    def __init__(self):
        super().__init__('pose_transformer')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Create lookup transform pose publisher
        self.pose31_publisher = self.create_publisher(PoseWithCovarianceStamped, 'tag31/pose', 1)
        self.pose32_publisher = self.create_publisher(PoseWithCovarianceStamped, 'tag32/pose', 1)

        # Call on_timer function every second
        self.timer = self.create_timer(1.0, self.on_timer)
        
        # hard code the tag locations in the map, should be a parameter
        map_origin = [-5.0, -2.5, 0.0]
        # map_origin = [0.0, 0.0, 0.0]
        t31 = [31, 3.65, 4.52, 0.38, 1.5707963, 0.0, 0.0]
        t32 = [32, 5.18, 4.64, 0.38, -1.5707963, -3.1415927, 0.0]
        
        # make a list of the static map to tag transform matrices
        self.map_to_tag_list = []
        self.map_to_tag_list.append(translation_matrix([t31[1]+map_origin[0], t31[2]+map_origin[1], t31[3]])@euler_matrix(t31[4], t31[5], t31[6]))
        self.map_to_tag_list.append(translation_matrix([t32[1]+map_origin[0], t32[2]+map_origin[1], t32[3]])@euler_matrix(t32[4], t32[5], t32[6]))
        
        # create a pose with covariance message and populate the covariance
        self.robot_pose_msg = PoseWithCovarianceStamped()
        self.robot_pose_msg.header.frame_id = "map"
        self.robot_pose_msg.pose.covariance[0] = 0.1 # std_dev x [m] squared
        self.robot_pose_msg.pose.covariance[7] = 0.1 # std_dev y [m] squared
        self.robot_pose_msg.pose.covariance[14] = 0.1 # std_dev z [m] squared
        self.robot_pose_msg.pose.covariance[21] = 0.1 # std_dev roll [rad] squared
        self.robot_pose_msg.pose.covariance[28] = 0.1 # std_dev pitch [rad] squared
        self.robot_pose_msg.pose.covariance[35] = 0.1 # std_dev yaw [rad] squared

    def on_timer(self):
        tag_number = 31
        for map_to_tag_matrix in self.map_to_tag_list:
            try:
                tag_frame_name = 'tag36h11:' + str(tag_number)
                
                tag_to_robot_transform = self.tf_buffer.lookup_transform(tag_frame_name, 'base_link', rclpy.time.Time())
                v = tag_to_robot_transform.transform.translation
                q = tag_to_robot_transform.transform.rotation
                tag_to_robot_matrix = translation_matrix([v.x, v.y, v.z])@quaternion_matrix([q.x, q.y, q.z, q.w])
                
                map_to_robot_matrix = map_to_tag_matrix@tag_to_robot_matrix
                v = translation_from_matrix(map_to_robot_matrix)
                q = quaternion_from_matrix(map_to_robot_matrix)
                
                self.robot_pose_msg.header.stamp = tag_to_robot_transform.header.stamp
                self.robot_pose_msg.pose.pose.position.x = v[0]
                self.robot_pose_msg.pose.pose.position.y = v[1]
                self.robot_pose_msg.pose.pose.position.z = v[2]
                self.robot_pose_msg.pose.pose.orientation.w = q[3]
                self.robot_pose_msg.pose.pose.orientation.x = q[0]
                self.robot_pose_msg.pose.pose.orientation.y = q[1]
                self.robot_pose_msg.pose.pose.orientation.z = q[2]
                
                if tag_number == 31:
                    self.pose31_publisher.publish(self.robot_pose_msg)
                elif tag_number == 32:
                    self.pose32_publisher.publish(self.robot_pose_msg)
                    
                tag_number += 1
                
            except TransformException as ex:
                pass
       
def main():
    rclpy.init()
    pose_transform_node = FrameListener()
    
    try:
        rclpy.spin(pose_transform_node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()
