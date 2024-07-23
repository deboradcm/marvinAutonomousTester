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

sys.path.append(action_robo_v2_dir)
print("sys.path:")
for path in sys.path:
    print(path)
try:
    from action_robo_v2.action_robo_client import HoverActionClient
    print("Importação bem-sucedida!")
except ModuleNotFoundError as e:
    print(f"Erro de importação: {e}")

from marvin_control.marvin_controller import ControllerRobot

# Configuração do Logging
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
    
    def get_q_value(self, state, action):
        return self.q_table.get((state, action), 0.0)
    
    def update_q_value(self, state, action, reward, next_state): 
        old_q_value = self.get_q_value(state, action)
        future_q_values = [self.get_q_value(next_state, a) for a in self.actions]
        new_q_value = old_q_value + self.alpha * (reward + self.gamma * max(future_q_values) - old_q_value)
        self.q_table[(state, action)] = new_q_value
        self.publish_q_table()

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
        return self.actions[q_values.index(max_q)]

    def epsilon_greedy_policy(self, state):
        if random.uniform(0, 1) < self.epsilon:
            return random.choice(self.actions)
        else:
            return self.direct_policy(state)

class Robot:
    def __init__(self, robot_id, actions, qlearning):
        self.robot_id = robot_id
        self.actions = actions
        self.qlearning = qlearning
        self.current_state = None
        self.current_action = None
        self.controller = ControllerRobot()

    def coordenada_robo(self, x, y, z, reward):
        next_state = (x, y, z)
        self.qlearning.update_q_value(self.current_state, self.current_action, reward, next_state)
        self.current_state = next_state
        try:
            joint_angles = self.controller.calculate_joint_angles(x, y, z)  # Passando x, y e z
            self.controller.send_joint_angles_to_robot(joint_angles)
        except ValueError as e:
            print(e)

    def trajetoria_robo(self, xa, ya, za, xb, yb, zb, reward):
        self.qlearning.update_q_value(self.current_state, self.current_action, reward, (xb, yb, zb))
        self.current_state = (xb, yb, zb)

    def escolher_proxima_trajetoria(self, use_direct_policy=False):
        if use_direct_policy:
            self.current_action = self.qlearning.direct_policy(self.current_state)
        else:
            self.current_action = self.qlearning.epsilon_greedy_policy(self.current_state)
        return self.current_action
    
    def generate_new_actions(self):
        # Exemplo de geração dinâmica de novas ações
        acoes = []
        for _ in range(10):  # Gere 10 trajetórias diferentes
            start_x = random.uniform(-0.1, 0.1)
            start_y = random.uniform(-0.1, 0.1)
            start_z = random.uniform(0.0, 0.1)
            end_x = start_x + random.uniform(-0.05, 0.05)
            end_y = start_y + random.uniform(-0.05, 0.05)
            end_z = start_z + random.uniform(-0.05, 0.05)
            acoes.append(((start_x, start_y, start_z), (end_x, end_y, end_z)))
        return acoes

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
        self.publicar_proxima_trajetoria(self.robot.robot_id, ((0.0, 0.0, 0.0), (0.05, 0.01, 0.0)))

        def gerar_acoes(self):
            # Gera ações de forma dinâmica para criar mais variações
            acoes = []
            for _ in range(10):  # Gere 10 trajetórias diferentes
                start_x = random.uniform(-0.1, 0.1)
                start_y = random.uniform(-0.1, 0.1)
                start_z = random.uniform(0.0, 0.1)
                end_x = start_x + random.uniform(-0.05, 0.05)
                end_y = start_y + random.uniform(-0.05, 0.05)
                end_z = start_z + random.uniform(-0.05, 0.05)
                acoes.append(((start_x, start_y, start_z), (end_x, end_y, end_z)))
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
                reward = DEFAULT_REWARD

                if (self.robot.robot_id == data['id_robot'] and data['message'] != 'failure') or data['message'] == 'success':
                    reward = BUTTON_PRESSED_REWARD if data['message'] == 'success' else DEFAULT_REWARD
                    self.robot.coordenada_robo(data['current_x'], data['current_y'], data['current_z'], reward)
                else:
                    self.robot.trajetoria_robo(data['initial_x'], data['initial_y'], data['initial_z'], data['final_x'], data['final_y'], data['final_z'], reward)

                use_direct_policy = (data['message'] == 'success')
                proxima_trajetoria = self.robot.escolher_proxima_trajetoria(use_direct_policy)
                self.publicar_proxima_trajetoria(self.robot.robot_id, proxima_trajetoria)
        except Exception as e:
            print("Error parsing MQTT message: %s" % str(e))

    def send_action_robot(self, robot_id, initial_x, initial_y, initial_z, final_x, final_y, final_z):
        command = (
            f'ros2 action send_goal /hover_action '
            f'action_marvin_interfaces/action/Hover '
            f'"{{id_robot: {robot_id}, initial_x: {initial_x}, initial_y: {initial_y}, initial_z: {initial_z}, '
            f'final_x: {final_x}, final_y: {final_y}, final_z: {final_z}}}"'
        )
        print(f"Executando comando: {command}")
        subprocess.run(command, shell=True, check=True)

    def publicar_proxima_trajetoria(self, robot_id, trajetoria):
        self.send_action_robot(robot_id, trajetoria[0][0], trajetoria[0][1], trajetoria[0][2], trajetoria[1][0], trajetoria[1][1], trajetoria[1][2])

def main():
    id_robot = 1
    TopicMQTT(id_robot)
    try:
        while True:
            pass
    except KeyboardInterrupt:
        print("Encerrando topico MQTT")

if __name__ == "__main__":
    main()
