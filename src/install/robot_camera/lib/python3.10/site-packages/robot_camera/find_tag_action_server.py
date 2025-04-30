import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.node import Node
# from robot_actions.action import Tag # OG
# from robot_camera.action import Tag
from action_interface.action import Tag
from apriltag_msgs.msg import AprilTagDetectionArray
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np

class TagActionServer(Node):

    def __init__(self):
        super().__init__('tag_action_server')
        self.tag_action_server = ActionServer(
            self,
            Tag,
            'tag_finder',
            goal_callback = self.goal_callback,
            execute_callback = self.execute_callback)
        self.tag_detections_sub = self.create_subscription(
            AprilTagDetectionArray,
            'detections',
            self.apriltag_callback,
            10)
        self.tag_detections_sub  # prevent unused variable warning
        self.detections = AprilTagDetectionArray()
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

    def goal_callback(self, goal_request):
        return GoalResponse.ACCEPT

    def execute_callback(self, goal_handle):

        min_tag = goal_handle.request.min_tag
        max_tag = goal_handle.request.max_tag
        
        for detection in self.detections.detections:
            if detection.id >= min_tag and detection.id <= max_tag:
                try:
                    tag_frame_name = 'tag36h11:' + str(detection.id)
                    map_to_tag_transform = self.tf_buffer.lookup_transform('map', tag_frame_name, rclpy.time.Time())
                    v = map_to_tag_transform.transform.translation
                    q = map_to_tag_transform.transform.rotation
                    goal_handle.succeed()
                    result_msg = Tag.Result()
                    result_msg.tag = detection.id
                    result_msg.x = v.x
                    result_msg.y = v.y
                    result_msg.orientation = 2*np.arctan2(q.z, q.w)
                    return result_msg
                except TransformException as ex:
                    pass
        goal_handle.succeed()
        result_msg = Tag.Result()
        result_msg.tag = -1
        result_msg.x = 0.0
        result_msg.y = 0.0
        result_msg.orientation = 0.0
        return result_msg

    def apriltag_callback(self, msg):
        self.detections = msg

def main(args=None):
    rclpy.init(args=args)
    tag_action_server = TagActionServer()

    try:
        rclpy.spin(tag_action_server)
    except KeyboardInterrupt:
        pass

if __name__ == '__main__':
    main()
