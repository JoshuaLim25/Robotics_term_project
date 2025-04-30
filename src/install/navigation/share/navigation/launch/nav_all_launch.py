import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
	control_launch = os.path.join(get_package_share_directory('robot_control'), 'launch', 'action_server_launch.py')
	localization_launch = os.path.join(get_package_share_directory('navigation'), 'launch', 'localization_launch.py')
	nav_launch = os.path.join(get_package_share_directory('navigation'), 'launch', 'navigation_launch.py')
	
	control_include = IncludeLaunchDescription(PythonLaunchDescriptionSource(control_launch))
	localization_include = IncludeLaunchDescription(PythonLaunchDescriptionSource(localization_launch))
	nav_include = IncludeLaunchDescription(PythonLaunchDescriptionSource(nav_launch))

	return LaunchDescription([
		control_include,
		localization_include,
		nav_include
	])
