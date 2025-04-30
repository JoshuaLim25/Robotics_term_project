# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import JointState

def update_velocity(s, v, dv):
    if s > v:
        v += dv
        if v > s:
            v = s
    else:
        v -= dv
        if v < s:
            v = s
    return v

class Simulation(Node):
    def __init__(self):
        super().__init__('simulation')
        timer_period = 0.5  # seconds
        self.publisher_ = self.create_publisher(JointState, '/arduino/joint_state_motor', 10)
        self.timer_pub = self.create_timer(timer_period, self.publisher_callback)
        self.subscriber_ = self.create_subscription(JointState, '/arduino/joint_state_setpoint', self.subscriber_callback, 10)
        self.simulation_timer = self.create_timer(timer_period * .1, self.simulation_callback)

        # Initialize parameters
        # self.declare_parameter('velocity', [0.0, 0.0, 0.0, 0.0])
        # self.velocity = self.get_parameter('velocity').value

        # Initialize joint state message
        self.joint_state = JointState()
        self.joint_state.name = ["base_to_front_left_leg", "base_to_front_right_leg", "shoulder_to_shoulder_joint", "upper_arm_to_elbow"]
        self.joint_state.velocity = [0.0, 0.0, 0.0, 0.0]
        self.joint_state.position = [0.0, 0.0, 0.0, 0.0]
        
        # Current velocities and positions
        self.wl = 0.0  # left wheel velocity
        self.wr = 0.0  # right wheel velocity
        self.w_shoulder = 0.0  # Initialize to 0
        self.w_elbow = 0.0    # Initialize to 0
        
        # Setpoints
        self.setpoint_left = 0.0
        self.setpoint_right = 0.0
        self.setpoint_shoulder = 0.0
        self.setpoint_elbow = 0.0

    def simulation_callback(self):
        # Update wheel velocities
        wl_prev = self.wl
        wr_prev = self.wr
        wl_current = 0.95122942 * wl_prev + 0.04877058 * self.setpoint_left
        wr_current = 0.95122942 * wr_prev + 0.04877058 * self.setpoint_right
        
        # Update wheel positions
        self.joint_state.position[0] += wl_current * 0.05
        self.joint_state.position[1] += wr_current * 0.05
        
        # Store updated wheel velocities
        self.wl = wl_current
        self.wr = wr_current
        self.joint_state.velocity[0] = wl_current
        self.joint_state.velocity[1] = wr_current

        # Update arm joint velocities and positions
        scale_steps_arm = 1019.0/3.14159
        scale_radians_arm = 1.0/scale_steps_arm
        accel = 500 * scale_radians_arm
        delta_v = accel * (1/50)
        
        # Update shoulder using its setpoint
        shoulder_current = update_velocity(self.setpoint_shoulder, self.w_shoulder, delta_v)
        self.w_shoulder = shoulder_current
        self.joint_state.position[2] += shoulder_current * 0.05
        self.joint_state.velocity[2] = shoulder_current
        
        # Update elbow using its setpoint
        elbow_current = update_velocity(self.setpoint_elbow, self.w_elbow, delta_v)
        self.w_elbow = elbow_current
        self.joint_state.position[3] += elbow_current * 0.05
        self.joint_state.velocity[3] = elbow_current

    def publisher_callback(self):
        # Simply publish current state
        self.publisher_.publish(self.joint_state)
        # self.get_logger().info(str(self.joint_state))

    def subscriber_callback(self, joint_state_cb):
        # Just update setpoints from parameters
        self.setpoint_left = joint_state_cb.velocity[0]
        self.setpoint_right = joint_state_cb.velocity[1]
        self.setpoint_shoulder = joint_state_cb.velocity[2]
        self.setpoint_elbow = joint_state_cb.velocity[3]

def main(args=None):
    rclpy.init(args=args)
    minimal_publisher = Simulation()
    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
