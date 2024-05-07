import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import SetEnvironmentVariable
import xacro

def generate_launch_description():
    ld = LaunchDescription()
    
    pkg_name = 'marvin_description'  # Nome do pacote

    pkg_share = get_package_share_directory(pkg_name)

    urdf_path = 'urdf/ur3e_urdf.xacro'

    rviz_relative_path = 'marvin_bringup/rviz/urdf_config.rviz'

    rviz_absolute_path = os.path.join(pkg_share, rviz_relative_path)

    # Processamento do arquivo xacro usando o módulo xacro
    xacro_file = os.path.join(pkg_share, urdf_path)
    urdf_content = xacro.process_file(xacro_file).toxml()
    robot_description = {'robot_description': urdf_content}
    world_path = os.path.join(pkg_share, 'worlds', 'chesset.world')

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[robot_description],
        output="screen"
    )
    
    gazebo_launch_file = os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([gazebo_launch_file]),
        launch_arguments={'world': world_path}.items()
    )
    
    spawn_entity_node = Node(
        package="gazebo_ros",
        executable="spawn_entity.py",
        arguments=["-topic", "robot_description", "-entity", "my_robot"],
        output="screen"
    )
    
    mqtt_publisher_node = Node(
        package="mqtt_publish",
        executable="mqtt_publish",
        output="screen"
    )
    
    topic_terminal_node = Node(
        package="topic_to_terminal",
        executable="terminal_sub",
        output="screen"
    )
    
    ld.add_action(mqtt_publisher_node)
    ld.add_action(topic_terminal_node)
    ld.add_action(robot_state_publisher_node)
    ld.add_action(gazebo_launch)
    ld.add_action(spawn_entity_node)
    
    return ld

