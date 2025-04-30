from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
from rclpy.duration import Duration

# Basic navigation demo to go to pose.

rclpy.init()

navigator = BasicNavigator()

# Define goal pose
goal_pose = PoseStamped()
goal_pose.header.frame_id = 'map'
goal_pose.header.stamp = navigator.get_clock().now().to_msg()
# goal pose in meters in absolute coordinates on map
goal_pose.pose.position.x = 2.0
goal_pose.pose.position.y = -1.0
# goal orientation in quaternion
# to go from an orientation angle, theta, in radians
# use the math or numpy library
# orientation.w = math.cos(0.5 * theta)
# orientation.z = math.sin(0.5 * theta)
goal_pose.pose.orientation.w = 1.0
goal_pose.pose.orientation.z = 0.0

navigator.goToPose(goal_pose)

# display feedback, limit the amount
i = 0
while not navigator.isTaskComplete():
    i = i + 1
    feedback = navigator.getFeedback()
    if feedback and i % 5 == 0:
        print(
            'Estimated time of arrival: '
            + '{0:.0f}'.format(
                Duration.from_msg(feedback.estimated_time_remaining).nanoseconds
                / 1e9
            )
            + ' seconds.'
        )

# Display the result code
result = navigator.getResult()
if result == TaskResult.SUCCEEDED:
    print('Goal succeeded!')
elif result == TaskResult.CANCELED:
    print('Goal was canceled!')
elif result == TaskResult.FAILED:
    # (error_code, error_msg) = navigator.getTaskError()
    print('Goal failed!{error_code}:{error_msg}')
else:
    print('Goal has an invalid return status!')

