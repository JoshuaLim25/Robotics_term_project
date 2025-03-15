#!/usr/bin/bash

colcon build && echo "Build completed"
source install/setup.bash && echo "Sourced workspace"
sleep 3
ros2 run robot_control robot_action_server.py
