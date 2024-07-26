import csv
import numpy as np
import os
import sys
import logging
from datetime import datetime
import subprocess
import paho.mqtt.client as mqtt
import json
import random
from tabulate import tabulate
import rclpy.node

# Adiciona o caminho do projeto ao sys.path
current_dir = os.path.dirname(os.path.abspath(__file__))
project_dir = os.path.abspath(os.path.join(current_dir, '../../..'))
action_robo_v2_dir = os.path.join(project_dir, 'comunicacao_android_ros2', 'action_robo_v2', 'action_robo_v2')

# Adiciona o diretório correto ao sys.path
sys.path.append(action_robo_v2_dir)

print("sys.path:")
for path in sys.path:
    print(path)

# Tenta importar após adicionar o caminho ao sys.path
try:
    from action_robo_v2.action_robo_client import HoverActionClient
    print("Importação bem-sucedida!")
except ModuleNotFoundError as e:
    print(f"Erro de importação: {e}")

# Controle do manipulador 
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
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        print(f"Resultado do comando: {result.stdout}")
        if result.stderr:
            print(f"Erro ao executar comando: {result.stderr}")

    def is_within_workspace(self, x, y, z): # Limites ajustados com base no alcance máximo de 500 mm (0.5 metros)
        if -0.5 <= x <= 0.5 and -0.5 <= y <= 0.5 and 0.0 <= z <= 0.5:
            return True
        return False


if __name__ == "__main__":

    controller = ControllerRobot()
    try:

        joint_angles = controller.calculate_joint_angles(0.08, 0.9, 0.5)
        controller.send_joint_angles_to_robot(joint_angles)
    except ValueError as e:
        print(e)
        


# Configura o logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)

# Constantes para ações
BUTTON_PRESSED_REWARD = 100
DEFAULT_REWARD = -1

class QLearning:
    def __init__(self, actions, alpha=0.1, gamma=0.9, epsilon=0.1, mqtt_client=None):
        self.q_table = {}
        self.actions = actions
        self.alpha = alpha
        self.gamma = gamma
        self.epsilon = epsilon
        self.mqtt_client = mqtt_client
        self.total_actions = 0
        self.successful_actions = 0

    def get_q_value(self, state, action):
        return self.q_table.get((state, action), 0.0)

    def update_q_value(self, state, action, reward, next_state):
        old_q_value = self.get_q_value(state, action)
        future_q_values = [self.get_q_value(next_state, a) for a in self.actions]
        new_q_value = old_q_value + self.alpha * (reward + self.gamma * max(future_q_values) - old_q_value)
        self.q_table[(state, action)] = new_q_value
        self.publish_q_table()

        # Atualize contadores de ações
        self.total_actions += 1
        if reward > 0:
            self.successful_actions += 1

        print(f"Q-value atualizado: {self.q_table[(state, action)]} para estado: {state} e ação: {action}")

    def publish_q_table(self):
        if self.mqtt_client:
            q_table_serializable = {str(key): value for key, value in self.q_table.items()}
            q_table_json = json.dumps(q_table_serializable)
            self.mqtt_client.publish('qlearning/q_table', q_table_json)

    def merge_q_table(self, new_q_table):
        for key, value in new_q_table.items():
            key_tuple = eval(key)
            if key_tuple in self.q_table:
                self.q_table[key_tuple] = max(self.q_table[key_tuple], value)
            else:
                self.q_table[key_tuple] = value

    def direct_policy(self, state):
        q_values = [self.get_q_value(state, action) for action in self.actions]
        max_q = max(q_values)
        if max_q == 0:
            print(f"Todos os Q-values para o estado {state} são zero. Escolhendo ação aleatória.")
            return random.choice(self.actions)
        best_action = self.actions[q_values.index(max_q)]
        print(f"Direct policy escolheu a ação: {best_action} para estado: {state} com Q-value: {max_q}")
        return best_action

    def epsilon_greedy_policy(self, state):
        if random.uniform(0, 1) < self.epsilon:
            chosen_action = random.choice(self.actions)
            print(f"Epsilon-greedy escolheu ação aleatória: {chosen_action}")
            return chosen_action
        else:
            return self.direct_policy(state)

    def get_accuracy(self):
        if self.total_actions == 0:
            return 0.0  # Evita divisão por zero se nenhuma ação foi tomada
        return (self.successful_actions / self.total_actions) * 100


class Robot:
    def __init__(self, robot_id, actions, qlearning):
        self.robot_id = robot_id
        self.actions = actions
        self.qlearning = qlearning
        self.current_state = (0.0, 0.0, 0.0)  # Define o estado inicial
        self.current_action = None
        self.controller = ControllerRobot()

    def coordenada_robo(self, x, y, z, reward):
        next_state = (x, y, z)
        print(f"Atualizando Q-value com estado atual: {self.current_state}, ação: {self.current_action}, recompensa: {reward}, próximo estado: {next_state}")
        self.qlearning.update_q_value(self.current_state, self.current_action, reward, next_state)
        self.current_state = next_state
        try:
            joint_angles = self.controller.calculate_joint_angles(x, y, z)
            self.controller.send_joint_angles_to_robot(joint_angles)
        except ValueError as e:
            print(e)

    def trajetoria_robo(self, xa, ya, za, xb, yb, zb, reward):
        print(f"Atualizando Q-value com trajetória: ({xa}, {ya}, {za}) -> ({xb}, {yb}, {zb}), recompensa: {reward}")
        self.qlearning.update_q_value(self.current_state, self.current_action, reward, (xb, yb, zb))
        self.current_state = (xb, yb, zb)
        try:
            joint_angles = self.controller.calculate_joint_angles(xb, yb, zb)
            self.controller.send_joint_angles_to_robot(joint_angles)
        except ValueError as e:
            print(e)

    def escolher_proxima_trajetoria(self, use_direct_policy=False):
        if use_direct_policy:
            self.current_action = self.qlearning.direct_policy(self.current_state)
        else:
            self.current_action = self.qlearning.epsilon_greedy_policy(self.current_state)
        print(f"Próxima ação escolhida: {self.current_action}")
        return self.current_action

class TopicMQTT:
    def __init__(self, id_robot):
        self.client = mqtt.Client()
        self.qlearning = QLearning(actions=self.gerar_acoes(), mqtt_client=self.client)
        self.robot = Robot(id_robot, actions=self.qlearning.actions, qlearning=self.qlearning)
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message
        self.client.connect('broker.hivemq.com', 1883)
        self.client.subscribe('hover_data')
        self.client.subscribe('qlearning/q_table')
        self.client.loop_start()
        self.publicar_proxima_trajetoria(self.robot.robot_id, self.robot.escolher_proxima_trajetoria())

    def gerar_acoes(self):
        acoes = []
        interval_x = [0.0, 0.2]
        interval_y = [0.0, 0.2]
        interval_z = [0.0, 0.4]
        step = 0.05

        for x in np.arange(interval_x[0], interval_x[1], step):
            for y in np.arange(interval_y[0], interval_y[1], step):
                for z in np.arange(interval_z[0], interval_z[1], step):
                    acao = ((0.0, 0.0, 0.0), (x, y, z))
                    acoes.append(acao)
        print(f"Ações geradas: {acoes}")
        return acoes

    def on_connect(self, client, userdata, flags, rc):
        print("Connected to MQTT broker with result code %d." % rc)

    def on_message(self, client, userdata, msg):
        print(msg.topic)
        print(msg)
        try:
            if msg.topic == 'qlearning/q_table':
                new_q_table = json.loads(msg.payload.decode())
                self.qlearning.merge_q_table(new_q_table)
            elif msg.topic == 'hover_data':
                data = json.loads(msg.payload.decode())

                required_keys = ['message', 'id_robot', 'current_x', 'current_y', 'current_z']
                if all(key in data for key in required_keys):
                    reward = DEFAULT_REWARD

                    if data['message'] == 'success':
                        reward = BUTTON_PRESSED_REWARD
                        self.robot.coordenada_robo(data['current_x'], data['current_y'], data['current_z'], reward)
                    elif data['message'] == 'failure':
                        print("Mensagem de falha recebida. Nenhuma atualização de coordenadas será feita, gerando nova trajetória.")

                    use_direct_policy = (data['message'] == 'success')
                    proxima_trajetoria = self.robot.escolher_proxima_trajetoria(use_direct_policy)
                    self.publicar_proxima_trajetoria(self.robot.robot_id, proxima_trajetoria)
                    
                    accuracy = self.qlearning.get_accuracy()
                    print(f"Current accuracy: {accuracy:.2f}%")
                else:
                    print("Erro: Mensagem MQTT não contém as chaves necessárias")
        except Exception as e:
            print(f"Erro ao processar mensagem MQTT: {e}")

    def send_action_robot(self, robot_id, initial_x, initial_y, initial_z, final_x, final_y, final_z):
        command = f'ros2 action send_goal /hover_action action_marvin_interfaces/action/Hover "{{id_robot: {robot_id}, initial_x: {initial_x}, initial_y: {initial_y}, initial_z: {initial_z}, final_x: {final_x}, final_y: {final_y}, final_z: {final_z}}}"'
        print(f"Executando comando: {command}")
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        print(f"Resultado do comando: {result.stdout}")
        if result.stderr:
            print(f"Erro ao executar comando: {result.stderr}")

    def publicar_proxima_trajetoria(self, robot_id, action):
        initial_coords, final_coords = action
        self.send_action_robot(robot_id, *initial_coords, *final_coords)

if __name__ == "__main__":

    controller = ControllerRobot()
    try:

        joint_angles = controller.calculate_joint_angles(0.05, 0.01, 0.02)
        controller.send_joint_angles_to_robot(joint_angles)
    except ValueError as e:
        print(e)
        
    topic_mqtt = TopicMQTT(id_robot=1)

