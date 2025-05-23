import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.node import Node
from action_interface.action import Tag
from apriltag_msgs.msg import AprilTagDetectionArray
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np

class TagActionServer(Node):

    def __init__(self):
        super().__init__('find_tag_action_server')
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
        self.get_logger().info('Tag Action Server initialized')

    def goal_callback(self, goal_request):
        self.get_logger().info(f'Received goal request: min_tag={goal_request.min_tag}, max_tag={goal_request.max_tag}')
        return GoalResponse.ACCEPT

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        min_tag = goal_handle.request.min_tag
        max_tag = goal_handle.request.max_tag
        
        # CHANGE: wrap your detection check in a loop
        timeout = 20.0  # seconds max
        start = self.get_clock().now()
        while (self.get_clock().now() - start).nanoseconds * 1e-9 < timeout:
            if self.detections.detections:  # Check if we have any detections
                break
            rclpy.spin_once(self, timeout_sec=0.1)
            
        # before we process self.detections, if it's still empty then abort
        if not self.detections.detections:
            self.get_logger().info('No tag detections found within timeout')
            goal_handle.succeed()
            result_msg = Tag.Result()
            result_msg.tag = -1
            result_msg.x = 0.0
            result_msg.y = 0.0
            result_msg.orientation = 0.0
            return result_msg
        # END CHANGE
        
        # Log what we found
        self.get_logger().info(f'Processing {len(self.detections.detections)} detections')
        for detection in self.detections.detections:
            self.get_logger().info(f'Checking tag {detection.id}')
            if detection.id >= min_tag and detection.id <= max_tag:
                try:
                    tag_frame_name = 'tag36h11:' + str(detection.id)
                    self.get_logger().info(f'Looking up transform for {tag_frame_name}')
                    
                    # Add timeout and use latest available transform
                    map_to_tag_transform = self.tf_buffer.lookup_transform(
                        'map', 
                        tag_frame_name, 
                        rclpy.time.Time(),
                        rclpy.duration.Duration(seconds=0.5)  # Add reasonable timeout
                    )

                    v = map_to_tag_transform.transform.translation
                    q = map_to_tag_transform.transform.rotation
                    goal_handle.succeed()
                    result_msg = Tag.Result()
                    result_msg.tag = detection.id
                    result_msg.x = v.x
                    result_msg.y = v.y
                    result_msg.orientation = 2*np.arctan2(q.z, q.w)
                    self.get_logger().info(f'Found tag {detection.id} at ({v.x}, {v.y})')
                    return result_msg
                except TransformException as ex:
                    self.get_logger().warn(f"Transform exception for tag {detection.id}: {ex}")
                    pass

        self.get_logger().info('No matching tags found in range')
        goal_handle.succeed()
        result_msg = Tag.Result()
        result_msg.tag = -1
        result_msg.x = 0.0
        result_msg.y = 0.0
        result_msg.orientation = 0.0
        return result_msg

    def apriltag_callback(self, msg):
        if msg.detections:
            self.get_logger().debug(f'Received {len(msg.detections)} tag detections')
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
