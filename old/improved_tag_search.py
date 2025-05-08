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
        super().__init__('find_tag')
        self.tag_action_client = ActionClient(self, Tag, 'tag_finder')
        self.goal_handle = None
        self.result_future = None
        self.tag = -1
        self.x = 0.0
        self.y = 0.0
        self.orientation = 0.0
        self.get_logger().info("FindTagActionClient initialized")

    def tag_is_found(self, min_tag, max_tag):
        self.get_logger().info(f"Checking for tags between {min_tag} and {max_tag}")
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
            self.get_logger().info(f"Found tag {self.tag} at position ({self.x}, {self.y})")
            return True
            
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
        dx = offset*np.cos(self.orientation)
        dy = offset*np.sin(self.orientation)
        return self.tag, self.x + dx, self.y + dy, (self.orientation + np.pi) % (2*np.pi)

def search_setup(navigator):
    # I hard coded a list of poses
    # I took coordinates from the map .png pixels
    poses = []
    poses.append([625, 1450, 0])
    poses.append([1000, 1450, 45])
    poses.append([1000, 1300, 90])
    poses.append([750, 1350, 180])
    poses.append([440, 1200, 90])
    poses.append([440, 1000, 45])
    poses.append([970, 800, 90])
    poses.append([970, 50, 45])
    poses.append([1100, 60, -90])
    poses.append([970, 180, -135])
    poses.append([750, 300, 135])
    poses.append([550, 50, 180])
    poses.append([720, 600, -90])
    poses.append([350, 750, -135])
    poses.append([440, 1000, -90])
    poses.append([500, 1350, 0])
    # map origin in map_config.yaml file
    map_origin = [-5.0, -2.5]
    
    # Define goal poses
    goal_poses = []
    for pose in poses:
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.header.stamp = navigator.get_clock().now().to_msg()
        # goal pose in meters in absolute coordinates on map
        goal_pose.pose.position.x = pose[0]*0.01 + map_origin[0]
        goal_pose.pose.position.y = (1600-pose[1])*0.01 + map_origin[1]
        # goal orientation in quaternion
        # to go from an orientation angle, theta, in radians
        # use the math or numpy library
        # orientation.w = math.cos(0.5 * theta)
        # orientation.z = math.sin(0.5 * theta)
        goal_pose.pose.orientation.w = np.cos(0.5 * np.radians(pose[2]))
        goal_pose.pose.orientation.z = np.sin(0.5 * np.radians(pose[2]))
        goal_poses.append(goal_pose)
    num_goals = len(goal_poses)
    return num_goals, goal_poses

def main():
    # Initialize ROS
    rclpy.init()
    
    # Create the navigator and tag action client
    navigator = BasicNavigator()
    tag_action_client = FindTagActionClient()
    
    # Wait for Nav2 to be ready
    navigator.lifecycleStartup()
    
    # Setup search path
    num_goals, goal_poses = search_setup(navigator)
    
    # Create a multi-threaded executor to allow for concurrent operation
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(navigator)
    executor.add_node(tag_action_client)
    
    drive = 'yes'
    state = 'reset'
    goal = 0
    
    print("Starting search sequence...")
    
    try:
        while rclpy.ok():
            # Process callbacks
            executor.spin_once(timeout_sec=0.1)
            
            if state == 'reset':
                print('State: reset')
                if drive == 'no':
                    state = 'reset'
                elif drive == 'yes':
                    goal = 0
                    state = 'start_next_goal'
                else:
                    drive = 'no'
                    state = 'reset'
            elif state == 'start_next_goal':
                print(f'State: start_next_goal {goal} of {num_goals}')
                goal_pose = goal_poses[goal]
                navigator.goToPose(goal_pose)
                state = 'look_for_box'
            elif state == 'look_for_box':
                # Check task status before any other operations
                if navigator.isTaskComplete():
                    print("Navigation goal reached, moving to next goal")
                    goal += 1
                    goal = goal % num_goals
                    state = 'start_next_goal'
                    continue
                
                print('State: look_for_box')
                # Check for tags
                if tag_action_client.tag_is_found(0, 40):
                    tag, x, y, orientation = tag_action_client.get_target_pose()
                    print(f"Found tag {tag} at position ({x}, {y})")
                    navigator.cancelTask()  # Cancel current navigation
                    state = 'align_with_box'
                else:
                    # Short sleep to avoid constant tag checking
                    time.sleep(0.5)
            elif state == 'align_with_box':
                print('State: align_with_box')
                tag, x, y, orientation = tag_action_client.get_target_pose()
                goal_pose = PoseStamped()
                goal_pose.header.frame_id = 'map'
                goal_pose.header.stamp = navigator.get_clock().now().to_msg()
                goal_pose.pose.position.x = x
                goal_pose.pose.position.y = y
                goal_pose.pose.orientation.w = np.cos(0.5 * orientation)
                goal_pose.pose.orientation.z = np.sin(0.5 * orientation)
                print(f'Aligning with box at position: {x:.2f}, {y:.2f}, orientation: {orientation:.2f}')
                navigator.goToPose(goal_pose)
                
                # Wait for alignment to complete
                while not navigator.isTaskComplete():
                    executor.spin_once(timeout_sec=0.1)
                    time.sleep(0.1)
                
                state = 'check_align'
            elif state == 'check_align':
                print('State: check_align')
                if tag_action_client.tag_is_found(tag, tag):
                    tag, x, y, orientation = tag_action_client.get_box_pose()
                    print(f"Still see tag {tag} at refined position ({x}, {y})")
                    state = 'pick_up_box'
                else:
                    print("Lost sight of tag, trying to recover")
                    state = 'pick_up_box'  # Continue anyway for this example
            elif state == 'pick_up_box':
                print('State: pick_up_box')
                print("Tag found! Mission successful!")
                # Simulating box pickup operation
                time.sleep(2.0)
                state = 'return_home'
            elif state == 'return_home':
                print('State: return_home')
                # Set a home position (first position in our list)
                home_pose = goal_poses[0]
                navigator.goToPose(home_pose)
                
                # Wait for return to home to complete
                while not navigator.isTaskComplete():
                    executor.spin_once(timeout_sec=0.1)
                    time.sleep(0.1)
                    
                state = 'drop_box'
            elif state == 'drop_box':
                print('State: drop_box')
                print("Box delivered successfully!")
                drive = 'no'
                state = 'reset'
            else:
                print('Error: Bad state!')
                drive = 'no'
                state = 'reset'
    
    except KeyboardInterrupt:
        print("Operation cancelled by user")
    finally:
        executor.shutdown()
        navigator.destroy_node()
        tag_action_client.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
