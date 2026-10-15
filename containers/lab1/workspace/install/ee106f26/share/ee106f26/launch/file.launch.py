from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # Node(package='ee106f26', executable='publisher.py', name='publisher'),
        # Node(package='ee106f26', executable='subscriber.py', name='subscriber'),
        Node(package='ee106f26', executable='tf_listener.py', name='tf'),
    ])