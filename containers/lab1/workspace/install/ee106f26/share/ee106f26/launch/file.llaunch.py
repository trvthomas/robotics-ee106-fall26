from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('x_var', default_value='0'),
        DeclareLaunchArgument('enable_var', default_value='true'),

        # This is a comment
        Node(package='package_name', executable='node_filename', name='node_name'),

        Node(package='package_name', executable='node_filename_2', name='node_name_2',
             arguments=['-x', LaunchConfiguration('x_var'),
                        '-enable_var', LaunchConfiguration('enable_var')]),
    ])