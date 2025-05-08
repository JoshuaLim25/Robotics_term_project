#!/usr/bin/bash

colcon build && echo "Build completed"
source install/setup.bash && echo "Sourced workspace"
ros2 action send_goal --feedback /robot action_interface/action/Robot '{v_x: 1, w_z: 1, drive_time: 10}'
