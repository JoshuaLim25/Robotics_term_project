import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from action_msgs.msg import GoalStatus
from action_interface.action import Tag
from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator
import numpy as np
import time

class FindTagActionClient(Node):
    def __init__(self):
        super().__init__("find_tag")
        self.tag_action_client = ActionClient(self, Tag, "tag_finder")
        self.goal_handle = None
        self.result_future = None
        self.tag = -1
        self.x = 0.0
        self.y = 0.0
        self.orientation = 0.0
        self.get_logger().info("FindTagActionClient initialized")

    def tag_is_found(self, min_tag, max_tag):
        self.get_logger().info(f"Looking for tags in range {min_tag} to {max_tag}")
        self.tag_action_client.wait_for_server()
    
        goal_msg = Tag.Goal()
        goal_msg.min_tag = min_tag
        goal_msg.max_tag = max_tag
    
        send_goal_future = self.tag_action_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        self.goal_handle = send_goal_future.result()

        if not self.goal_handle or not self.goal_handle.accepted:
            self.get_logger().info('Goal was not accepted')
            return False
            
        self.result_future = self.goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, self.result_future)
        
        result = self.result_future.result().result
        status = self.result_future.result().status
        
        if status == GoalStatus.STATUS_SUCCEEDED and result.tag != -1:
            self.tag = result.tag
            self.x = result.x
            self.y = result.y
            self.orientation = result.orientation
            self.get_logger().info(f"Found tag {self.tag} at ({self.x}, {self.y})")
            return True
        else:
            self.get_logger().info("No tags found in range")
            self.tag = -1
            self.x = 0.0
            self.y = 0.0
            self.orientation = 0.0
            return False

    def get_box_pose(self):
        return self.tag, self.x, self.y, self.orientation

    def get_target_pose(self):
        # robot should receive a target pose 40cm in front of box
        # with orientation pointing toward box
        offset = 0.4
        dx = offset * np.cos(self.orientation)
        dy = offset * np.sin(self.orientation)
        return (
            self.tag,
            self.x + dx,
            self.y + dy,
            (self.orientation + np.pi) % (2 * np.pi),
        )

def main(args=None):
    rclpy.init(args=args)
    tag_action_client = FindTagActionClient()
    navigator = BasicNavigator()
    
    # Wait for Nav2 to be ready
    navigator.lifecycleStartup()
    
    # Set up navigation goal
    goal_pose = PoseStamped()
    goal_pose.header.frame_id = "map"
    goal_pose.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose.pose.position.x = 2.0
    goal_pose.pose.position.y = -1.0
    goal_pose.pose.orientation.w = np.cos(0.5 * np.radians(-90))
    goal_pose.pose.orientation.z = np.sin(0.5 * np.radians(-90))
    
    # Start navigation
    navigator.goToPose(goal_pose)
    
    # Use a multi-threaded executor to prevent blocking
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(tag_action_client)
    executor.add_node(navigator)
    
    # Implement a non-blocking check for tags
    check_frequency = 1.0  # seconds
    last_check_time = time.time()
    
    try:
        while rclpy.ok():
            # Process callbacks without blocking
            executor.spin_once(timeout_sec=0.1)
            
            # Check for tags periodically
            current_time = time.time()
            if current_time - last_check_time >= check_frequency:
                last_check_time = current_time
                
                # Non-blocking navigation state check
                if not navigator.isTaskComplete():
                    print("Looking for tag")
                    if tag_action_client.tag_is_found(0, 40):
                        navigator.cancelTask()
                        tag, x, y, o = tag_action_client.get_target_pose()
                        print("    Found tag")
                        print("   ", tag, x, y, o)
                        
                        # Create a new goal at the tag location
                        tag_pose = PoseStamped()
                        tag_pose.header.frame_id = "map"
                        tag_pose.header.stamp = navigator.get_clock().now().to_msg()
                        tag_pose.pose.position.x = x
                        tag_pose.pose.position.y = y
                        tag_pose.pose.orientation.w = np.cos(0.5 * o)
                        tag_pose.pose.orientation.z = np.sin(0.5 * o)
                        
                        # Navigate to the tag
                        navigator.goToPose(tag_pose)
                else:
                    print("Navigation complete")
                    break
                    
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        tag_action_client.destroy_node()
        navigator.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
