import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

class MockRobotNode(Node):
    def __init__(self):
        super().__init__('mock_robot_node')

        # Initialize variables for joint states
        self.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']
        self.positions = [0.0, 0.0, 0.0, 0.0]
        self.velocities = [0.0, 0.0, 0.0, 0.0]
        self.setpoints = [0.0, 0.0, 0.0, 0.0]  # Velocity setpoints

        # Create publishers and subscribers
        self.publisher = self.create_publisher(JointState, '/mock_robot/joint_states', 10)
        self.get_logger().info("Publisher created for /mock_robot/joint_states")

        self.subscriber = self.create_subscription(
            JointState,
            '/mock_robot/joint_setpoints',
            self.setpoint_callback,
            10
        )
        self.get_logger().info("Subscriber created for /mock_robot/joint_setpoints")

        # Timer for simulation updates
        self.timer_period = 1.0  # 1 Hz
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.get_logger().info("Timer initialized with period: 1.0 seconds")

    def setpoint_callback(self, msg):
        try:
            self.setpoints = msg.velocity
            self.get_logger().info(f"Received setpoints: {self.setpoints}")
        except Exception as e:
            self.get_logger().error(f"Error in setpoint_callback: {e}")

    def timer_callback(self):
        try:
            # Simulate motion based on setpoints
            for i in range(len(self.joint_names)):
                self.velocities[i] = self.setpoints[i]
                self.positions[i] += self.velocities[i] * self.timer_period

            # Publish updated joint states
            joint_state_msg = JointState()
            joint_state_msg.header.stamp = self.get_clock().now().to_msg()
            joint_state_msg.name = self.joint_names
            joint_state_msg.position = self.positions
            joint_state_msg.velocity = self.velocities
            self.publisher.publish(joint_state_msg)

            self.get_logger().info(f"Published joint states: {joint_state_msg}")
        except Exception as e:
            self.get_logger().error(f"Error in timer_callback: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = MockRobotNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()