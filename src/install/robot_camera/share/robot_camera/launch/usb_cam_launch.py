from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
import launch_ros.actions
import os
import yaml
from launch.substitutions import EnvironmentVariable
import pathlib
import launch.actions
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
	camera_params = os.path.join(get_package_share_directory('robot_camera'), 'params', 'params_1.yaml')

	return LaunchDescription([
		launch_ros.actions.Node(
		package='usb_cam',
		executable='usb_cam_node_exe',
		name='usb_cam_node',
		namespace='camera',
		output='screen',
		parameters=[camera_params]
	),
])

#import os
#from ament_index_python.packages import get_package_share_directory
#from launch import LaunchDescription
#from launch_ros.actions import Node
#
#def generate_launch_description():
#	camera_params = os.path.join(get_package_share_directory('robot_camera'), 'params', 'params_1.yaml')
#
#	return LaunchDescription([
#		Node(
#			package='usb_cam',
#			executable='usb_cam_node_exe',
#			name = 'usb_cam',
#			namespace='camera',
#			output='screen',
#			parameters=[camera_params]
#		)
#])

