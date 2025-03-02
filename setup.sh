#!/usr/bin/bash

colcon build && echo "Build completed"
source install/setup.bash && echo "Sourced workspace"
# ros2 launch robot_control sim_control_launch.py
ros2 launch robot_control action_server_launch.py
