import subprocess
import numpy as np

def calculate_joint_angles(x, y, z):
    # Aqui, você adicionaria sua lógica de cinemática inversa.
    # Retornando um exemplo de ângulos para fins ilustrativos.
    return [1.5, -0.5, 1.0, -3.57, -1.5, 2.0]  # Exemplo de ângulos das juntas

def send_joint_trajectory(angles):
    # Comando ROS2 formatado como string para enviar os ângulos das juntas
    command = f'ros2 action send_goal /joint_trajectory_controller/follow_joint_trajectory control_msgs/action/FollowJointTrajectory "{{trajectory: {{joint_names: [shoulder_pan_joint, shoulder_lift_joint, elbow_joint, wrist_1_joint, wrist_2_joint, wrist_3_joint], points: [{{positions: {angles}, velocities: [], accelerations: [], time_from_start: {{sec: 6, nanosec: 0}}}}]}}}}"'
    subprocess.run(command, shell=True)

def robot_action(x, y, z):
    # Calcula os ângulos necessários para alcançar a posição (x, y, z)
    angles = calculate_joint_angles(x, y, z)
    # Envia os ângulos calculados ao robô via ROS2
    send_joint_trajectory(angles)

# Exemplo de uso
robot_action(0.3, 0.2, 0.1)

