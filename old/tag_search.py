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

    def tag_is_found(self, min_tag, max_tag):
        self.tag_action_client.wait_for_server()

        goal_msg = Tag.Goal()
        goal_msg.min_tag = min_tag
        goal_msg.max_tag = max_tag
        
        send_goal_future = self.tag_action_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        self.goal_handle = send_goal_future.result()

        if not self.goal_handle or not self.goal_handle.accepted:
            self.get_logger().info('Goal was not accepted')
        else:
            self.result_future = self.goal_handle.get_result_async()
            rclpy.spin_until_future_complete(self, self.result_future)
            result = self.result_future.result().result
            status = self.result_future.result().status
            if status == GoalStatus.STATUS_SUCCEEDED and result.tag != -1:
                self.tag = result.tag
                self.x = result.x
                self.y = result.y
                self.orientation = result.orientation
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

def search_setup():
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
    
# Project 2 example

rclpy.init()

navigator = BasicNavigator()
tag_action_client = FindTagActionClient()
num_goals, goal_poses = search_setup()

drive = 'yes'
state = 'reset'
while True:
    time.sleep(1.0)    
    if state == 'reset':
        print('reset')
        if drive == 'no':
            state = 'reset'
        elif drive == 'yes':
            goal = 0
            state = 'start_next_goal'
        else:
            drive = 'no'
            state = 'reset'
    elif state == 'start_next_goal':
        print('start_next_goal', goal, 'of', num_goals)
        goal_pose = goal_poses[goal]
        navigator.goToPose(goal_pose)
        state = 'look_for_box'
    elif state == 'look_for_box':
        print('look_for_box')
        if navigator.isTaskComplete():
            goal += 1
            goal = goal % num_goals
            state = 'start_next_goal'
        elif tag_action_client.tag_is_found(0, 35):
            tag, x, y, orientation = tag_action_client.get_target_pose()
            state = 'align_with_box'
        else:
            state = 'look_for_box'
    elif state == 'align_with_box':
        print('align_with_box')
        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.header.stamp = navigator.get_clock().now().to_msg()
        goal_pose.pose.position.x = x
        goal_pose.pose.position.y = y
        goal_pose.pose.orientation.w = np.cos(0.5 * orientation)
        goal_pose.pose.orientation.z = np.sin(0.5 * orientation)
        print('Aligning with box:', goal_pose.pose.position.x, goal_pose.pose.position.y)
        navigator.goToPose(goal_pose)
        while not navigator.isTaskComplete():
            pass
        state = 'check_align'
    elif state == 'check_align':
        print('check_align')
        if tag_action_client.tag_is_found(tag, tag):
            tag, x, y, orientation = tag_action_client.get_box_pose()
            state = 'pick_up_box'
        else:
            # lost the tag
            # do something like goal -= 1
            # state = 'start_next_goal'
            state = 'pick_up_box'
    elif state == 'pick_up_box':
        print('pick_up_box')
        # pick up box
        state = 'return_home'
    elif state == 'return_home':
        print('return_home')
        # goal = -1
        # start goal
        state = 'drop_box'
    elif state == 'drop_box':
        print('drop_box')
        drive = 'no'
        state = 'reset'
    else:
        print('bad_state')
        # bad state
        drive = 'no'
        state = 'reset'

