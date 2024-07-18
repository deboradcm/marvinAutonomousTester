import numpy as np
import subprocess
from ur_analytic_ik import ur3e

class ControllerRobot:
    # Esta função calcula os ângulos das juntas necessários para o efetuador final do robô alcançar aposição (x, y, z) fornecida.
    def calculate_joint_angles(x, y, z):
        eef_pose = np.identity(4)
        eef_pose[:3, 3] = [x, y, z]
        eef_pose[:3, :3] = np.identity(3)  # Orientação padrão

        joint_solutions = ur3e.inverse_kinematics(eef_pose)
        print(f"Joint solutions: {joint_solutions}")  # Depuração
        if len(joint_solutions) == 0:
            raise ValueError("Nenhuma solução válida para as juntas foi encontrada para a posição fornecida.")
        
        joint_angles = joint_solutions[0][0]  # Seleciona o array interno
        print(f"Selected joint angles: {joint_angles}")  # Depuração
        return joint_angles

    def send_joint_angles_to_robot(joint_angles):
        joint_names = [
            "shoulder_pan_joint",
            "shoulder_lift_joint",
            "elbow_joint",
            "wrist_1_joint",
            "wrist_2_joint",
            "wrist_3_joint"
        ]
        
        positions = [float(angle) for angle in joint_angles]
        
        # Formatação das posições das juntas
        command = (
            f'ros2 action send_goal /joint_trajectory_controller/follow_joint_trajectory '
            f'control_msgs/action/FollowJointTrajectory '
            f'"{{trajectory: {{joint_names: {joint_names}, points: [{{positions: {positions}, '
            f'velocities: [], accelerations: [], time_from_start: {{sec: 6, nanosec: 0}}}}]}}}}"'
        )
        
        print(f"Executando comando: {command}")  # Depuração
        subprocess.run(command, shell=True, check=True)


