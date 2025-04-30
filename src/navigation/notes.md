# ROS2 topics to copy into robot control
- `/diff_drive_controller/cmd_vel_unstamped`
- `/image_raw`



# Other helpful commands
ros2 launch robot_control action_server_launch.py
ros2 launch navigation localization_launch.py 
ros2 launch navigation navigation_launch.py


*Note*: You now need three terminals to run the system
If you are using the real robot you will need four terminals
• microros agent (real robot only)
• control launch
• localization launch
• nav2 launch

# Changes Made
- Edited `~/ros2_lab4/src/robot_control/setup.py` to include correct entrypoints (`sim` -> `action_client`)

# Possible Changes
- Can edit the origin ﬁeld to change the starting point of your robot
	- In `~/ros2_lab4/src/navigation/map/map_config.yaml`
The 15x15 matrix called **process noise covariance**, speciﬁes the accuracy of the model of the equations of motion in the Kalman ﬁlter. This is balanced with the diﬀ drive controller parameters:

```sh
pose_covariance_diagonal: [0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.001]
twist_covariance_diagonal: [0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.001]
```

- *Note*: The **smaller** you make the covariance number, the more signiﬁcantly the Kalman ﬁlter weighs that variable
	- E.g., twist covariance diagonal means [vx , vy , vz , ωx , ωy , ωz ] 
	- The forward velocity has a standard deviation of √0.0001 = 0.01[m/s],
	- The rotational velocity has a standard deviation of √0.001 = 0.032[rad/s],
	- while the process noise covariance gives the
	- forward velocity a standard deviation of √0.025 = 0.158[m/s]
	- and a rotational velocity a standard deviation of √0.02 = 0.141[rad/s]
- *Note*: As it is setup right now, the Kalman ﬁlter will weigh the measurement much more heavily than the model
	- The ﬁltered odometry will stay pretty close to the measured odometry
	- Playing with the weights can improve robot localization signiﬁcantly
The planner server, behavior server, waypoint follower, and velocity smoother,

## nav launch file
> all have a frequency parameter
> You will probably have to slow these down for computing power, but leave them for
now 
