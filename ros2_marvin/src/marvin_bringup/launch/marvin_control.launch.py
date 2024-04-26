import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    ld = LaunchDescription()
    
    mqtt_publisher_node = Node(
        package="mqtt_publish",
        executable="mqtt_publish"
    )
    
    topic_terminal_node = Node(
        package="topic_to_terminal",
        executable="terminal_sub"
    )
    
    package_share_directory = get_package_share_directory('marvin_description')
    
    launch_file_path = os.path.join(package_share_directory, 'launch', 'display.launch.py')
    
    marvin_description_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([launch_file_path])
    )
  
    ld.add_action(mqtt_publisher_node)
    ld.add_action(topic_terminal_node)
    ld.add_action(marvin_description_launch)
    return ld
