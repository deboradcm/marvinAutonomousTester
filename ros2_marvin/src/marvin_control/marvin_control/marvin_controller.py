import numpy as np
import subprocess
from ur_analytic_ik import ur3e

class ControllerRobot:
    def calculate_joint_angles(self, x, y, z):
        # Adiciona mensagens de depuração para verificar as coordenadas
        print(f"Calculando ângulos das juntas para x: {x}, y: {y}, z: {z}")
        
        # Verifica se as coordenadas estão dentro de um intervalo esperado
        if not self.is_within_workspace(x, y, z):
            raise ValueError("As coordenadas fornecidas estão fora do espaço de trabalho do robô.")
        
        eef_pose = np.identity(4)
        eef_pose[:3, 3] = [x, y, z]
        eef_pose[:3, :3] = np.identity(3)  # Orientação padrão

        print(f"eef_pose: {eef_pose}")  # Depuração adicional

        try:
            joint_solutions = ur3e.inverse_kinematics(eef_pose)
            print(f"Joint solutions: {joint_solutions}")  # Depuração
            if len(joint_solutions) == 0:
                raise ValueError("Nenhuma solução válida para as juntas foi encontrada para a posição fornecida.")
            joint_angles = joint_solutions[0][0]  # Seleciona a primeira solução e converte para 1D
            print(f"Selected joint angles: {joint_angles}")  # Depuração
            return joint_angles
        except Exception as e:
            print(f"Erro ao calcular cinemática inversa: {e}")
            raise ValueError("Erro ao calcular cinemática inversa.")
        
    def send_joint_angles_to_robot(self, joint_angles):
        joint_names = [
            "shoulder_pan_joint",
            "shoulder_lift_joint",
            "elbow_joint",
            "wrist_1_joint",
            "wrist_2_joint",
            "wrist_3_joint"
        ]
        
        # Certifique-se de que joint_angles é um array 1D
        positions = [float(angle) for angle in joint_angles.flatten()]
        
        command = (
            f'ros2 action send_goal /joint_trajectory_controller/follow_joint_trajectory '
            f'control_msgs/action/FollowJointTrajectory '
            f'"{{trajectory: {{joint_names: {joint_names}, points: [{{positions: {positions}, '
            f'velocities: [], accelerations: [], time_from_start: {{sec: 6, nanosec: 0}}}}]}}}}"'
        )
        
        print(f"Executando comando: {command}")  # Depuração
        subprocess.run(command, shell=True, check=True)

    def is_within_workspace(self, x, y, z):
        # Exemplo de verificação de limites do espaço de trabalho do robô UR3e
        if -0.8 <= x <= 0.8 and -0.8 <= y <= 0.8 and 0.0 <= z <= 0.8:
            return True
        return False

# Exemplo de uso da classe
if __name__ == "__main__":
    controller = ControllerRobot()
    try:
        # Tente uma pose mais próxima do centro do espaço de trabalho
        joint_angles = controller.calculate_joint_angles(0.5, 0.1, 0.2)
        controller.send_joint_angles_to_robot(joint_angles)
    except ValueError as e:
        print(e)

