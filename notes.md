# Helpful commands

```sh
# Check that action definition exists (i.e., echoes contents of .action file)
ros2 interface show action_interface/action/Robot 

# fully qualified action names, see if server is running
ros2 action list 
```


# Changes
- created new node (`robot_action_server`) in `src/robot_control/robot_control`, where packages go
  - This 
- added entrypoint in `setup.py`
- check in server file
- change min/max tag in client file: `navigator.waitUntilNav2Active()`


## Problems
`ros2 action send_goal --feedback robot_control action_interface/action/Robot
"{v_x: 1, w_z: 1, drive_time: 10}"` doesn't work because of `robot_control`
(missing slash, and it's not supposed to be the package name, rather the node
name)

# Workflow
- one terminal has `ros2 run robot_control robot_action_server` going
- another has `ros2 action send_goal --feedback /<action_name>
  action_interface/action/Robot '{v_x: 1, w_z: 1, drive_time: 10}'`, where the
action name is just `/robot` 
  - `ros2 action send_goal --feedback /robot action_interface/action/Robot
    '{v_x: 1, w_z: 1, drive_time: 10}'`


# Rest of Lab
ros2 interface show control_msgs/action/FollowJointTrajectory 
- use the first bit of these, namely:
  - `trajectory_msgs/JointTrajectory trajectory`
  - `string[] joint_names`
```sh
        JointTrajectoryPoint[] points
                float64[] positions
                float64[] velocities
```
  - `builtin_interfaces/Duration time_from_start`

## ARM 
- You're trying to publish to `trajectory_msgs/msg/JointTrajectory`


# What stuff does
- `static_tag_broadcaster.py`: static map -> `tag36h11:<id>` transforms.
- `pose_lookup_transform.py`: computes the robot’s pose in the map frame by multiplying map->tag and tag->base_link.

# LAUNCH ORDER
*NOTE*: start the map/TF and Nav2 stack FIRST, then start the tag-detection logic. This avoids “lifecycle transition” errors (e.g. Nav2 trying to activate before map exists).

