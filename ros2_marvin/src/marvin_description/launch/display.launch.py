import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    # Obtém o caminho do arquivo URDF
    urdf_file = os.path.join(
        os.path.dirname(os.path.abspath(__file__)),
        "..", "..", "marvin_description", "urdf", "marvin.urdf"
    )

    # Lê o conteúdo do arquivo URDF
    with open(urdf_file, "r") as infp:
        robot_desc = infp.read()

    # Obtém o caminho do arquivo de configuração RViz
    rviz_config = os.path.join(
        os.path.dirname(os.path.abspath(__file__)),
        "..", "..", "marvin_description", "rviz", "config.rviz"
    )

    # Define o nó do publicador de estado do robô
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        output="screen",
        parameters=[{"robot_description": robot_desc}],
    )

    # Define o nó do publicador de estados conjuntos
    joint_state_publisher_node = Node(
        package="joint_state_publisher",
        executable="joint_state_publisher",
        name="joint_state_publisher",
        condition=UnlessCondition(LaunchConfiguration("gui")),
    )

    # Define o nó da interface gráfica do publicador de estados conjuntos
    joint_state_publisher_gui_node = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
        name="joint_state_publisher_gui",
        condition=IfCondition(LaunchConfiguration("gui")),
    )

    # Define o nó do RViz
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", LaunchConfiguration("rvizconfig")],  # Usa a configuração RViz
    )

    return LaunchDescription(
        [
            # Declaração do argumento para habilitar a interface gráfica do publicador de estados conjuntos
            DeclareLaunchArgument(
                name="gui",
                default_value="True",
                description="Flag to enable joint_state_publisher_gui",
            ),
            # Declaração do argumento para o arquivo de configuração RViz
            DeclareLaunchArgument(
                name="rvizconfig",
                default_value=rviz_config,
                description="Absolute path to rviz config file",
            ),
            joint_state_publisher_node,
            joint_state_publisher_gui_node,
            robot_state_publisher_node,
            rviz_node,
        ]
    )

