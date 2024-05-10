import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import xacro

# LOAD YAML:
def load_yaml(package_name, file_path):
    package_path = get_package_share_directory(package_name)
    absolute_file_path = os.path.join(package_path, file_path)
    try:
        with open(absolute_file_path, 'r') as file:
            return yaml.safe_load(file)
    except EnvironmentError:
        # parent of IOError, OSError *and* WindowsError where available.
        return None

# ========== **GENERATE LAUNCH DESCRIPTION** ========== #
def generate_launch_description():
    
    # DECLARE Gazebo WORLD file:
    world_path = os.path.join(
        get_package_share_directory('marvin_description'),
        'worlds',
        'marvin.world')
    
    # DECLARE Gazebo LAUNCH file:
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch'), '/gazebo.launch.py']),
                launch_arguments={'world': world_path}.items(),
             )

    # PANDA ROBOT Description file package:
    panda_description_path = os.path.join(
        get_package_share_directory('marvin_description'))
    
    # PANDA ROBOT ROBOT urdf file path:
    xacro_file = os.path.join(panda_description_path,
                              'urdf',
                              'ur3e_urdf.xacro')
    
    # Generate ROBOT_DESCRIPTION for PANDA ROBOT:
    doc = xacro.parse(open(xacro_file))
    xacro.process_doc(doc, mappings={"cell_layout_1": "true"})
    robot_description_config = doc.toxml()
    robot_description = {'robot_description': robot_description_config}

    # ROBOT STATE PUBLISHER NODE:
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[robot_description]
    )

    # SPAWN ROBOT TO GAZEBO:
    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', 'robot_description',
                                   '-entity', 'marvin'],
                        output='screen')

    # MQTT PUBLISHER NODE:
    mqtt_publisher_node = Node(
        package="mqtt_publish",
        executable="mqtt_publish",
        output="screen"
    )
    
    # TOPIC TERMINAL NODE:
    topic_terminal_node = Node(
        package="topic_to_terminal",
        executable="terminal_sub",
        output="screen"
    )
    
    # JOINT CONTROLLER NODE:
    joint_controller_node = Node(
        package="marvin_control",
        executable="marvin_controller",
        output="screen"
    )

    # Adicionando todos os nós à descrição de lançamento
    return LaunchDescription([
        gazebo, 
        node_robot_state_publisher,
        spawn_entity,
        mqtt_publisher_node,
        topic_terminal_node,
        joint_controller_node
    ])

