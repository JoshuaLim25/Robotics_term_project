import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from tf_transformations import quaternion_from_euler

class StaticFramePublisher(Node):

    def __init__(self):
        super().__init__('static_tag_broadcaster')

        self.tf_static_broadcaster = StaticTransformBroadcaster(self)

    def make_transform_frames(self, tags):
        transforms = []
        for tag in tags:
            t = TransformStamped()
            q = quaternion_from_euler(tag[4], tag[5], tag[6])
            
            t.transform.translation.x = float(tag[1])
            t.transform.translation.y = float(tag[2])
            t.transform.translation.z = float(tag[3])

            # NEW
            norm = math.sqrt(q[0]**2 + q[1]**2 + q[2]**2 + q[3]**2)
            t.transform.rotation.x = q[0]/norm
            t.transform.rotation.y = q[1]/norm
            t.transform.rotation.z = q[2]/norm
            t.transform.rotation.w = q[3]/norm
            # OLD STUFF
            # t.transform.rotation.w = q[3]
            # t.transform.rotation.x = q[0]
            # t.transform.rotation.y = q[1]
            # t.transform.rotation.z = q[2]
            
            t.header.frame_id = 'map'

			# CHANGE
            t.child_frame_id = 'tag36h11:' + str(tag[0])
            # t.child_frame_id = 'tag_frame_' + str(tag[0])
            t.header.stamp = self.get_clock().now().to_msg()
            
            transforms.append(t)
            
        self.tf_static_broadcaster.sendTransform(transforms)

def main():

    rclpy.init()
    
    tag_frame_node = StaticFramePublisher()
    
    # hard code a list of tags, should eventually be a parameter
    # the tags are placed at fixed locations in the map
    # translation is in the map frame to the center of the tag
    # rotation is roll about the map's x axis, pitch about the map's y axis
    # and yaw about the map's z-axis  
    # r, p, and y, are always about the map frame's axes
    # they don't change when you roll, pitch or yaw  
    # list: [tag_number, x, y, z, r, p, y]
    map_origin = [-5.0, -2.5, 0.0]
    # map_origin = [0.0, 0.0, 0.0]
    t31 = [31, 3.65, 4.52, 0.38, 1.5707963, 0.0, 0.0]
    t32 = [32, 5.18, 4.64, 0.38, -1.5707963, -3.1415927, 0.0]
    
    tag_list = []
    tag_list.append([t31[0], t31[1]+map_origin[0], t31[2]+map_origin[1], t31[3], t31[4], t31[5], t31[6]])
    tag_list.append([t32[0], t32[1]+map_origin[0], t32[2]+map_origin[1], t32[3], t32[4], t32[5], t32[6]])
    
    tag_frame_node.make_transform_frames(tag_list)

    try:
        rclpy.spin(tag_frame_node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()
