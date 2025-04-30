import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
	control_launch = os.path.join(get_package_share_directory('robot_camera'), 'launch', 'usb_cam_launch.py')
	localization_launch = os.path.join(get_package_share_directory('robot_camera'), 'launch', 'image_proc_launch.py')
	apriltag_launch = os.path.join(get_package_share_directory('robot_camera'), 'launch', 'april_tag_launch.py')
	
	control_include = IncludeLaunchDescription(PythonLaunchDescriptionSource(control_launch))
	localization_include = IncludeLaunchDescription(PythonLaunchDescriptionSource(localization_launch))
	nav_include = IncludeLaunchDescription(PythonLaunchDescriptionSource(apriltag_launch))

	return LaunchDescription([
		control_include,
		localization_include,
		nav_include
	])
