import csv
import numpy as np
import os
import logging
from datetime import datetime
import random
from tabulate import tabulate
import threading
from queue import Queue

# Configura o logging
logger = logging.getLogger()
logger.setLevel(logging.INFO)

# Cria um handler para salvar os logs em um arquivo, nomeado com a data e hora atuais
file_handler = logging.FileHandler(os.path.join('log', f'logs_{datetime.now().strftime("%Y%m%d_%H%M%S")}.txt'))
file_handler.setFormatter(logging.Formatter('%(asctime)s %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p'))

# Cria um handler para exibir os logs no console
console_handler = logging.StreamHandler()
console_handler.setFormatter(logging.Formatter('%(asctime)s %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p'))

# Adiciona os handlers ao logger
logger.addHandler(file_handler)
logger.addHandler(console_handler)

# Constantes para ações
MOVE_LEFT = 0
MOVE_RIGHT = 1
MOVE_UP = 2
MOVE_DOWN = 3
BUTTON_PRESSED_REWARD = 100
DEFAULT_REWARD = -1

class Button:
    @staticmethod
    def generate_position():
        # Gera uma posição aleatória para o botão dentro de um grid 10x10
        position = (random.randint(0, 9), random.randint(0, 9))
        logger.info(f'Posição do botão gerada: {position}')
        return position

class Environment:
    def __init__(self, states, button_position):
        self.states = states
        self.current_state = (0, 0)
        self.button_position = button_position
        self.button_position_shared = None
        self.button_pressed_by = None
        logger.info('Ambiente inicializado.')

    def step(self, action, robot_id):
        # Atualiza o estado atual baseado na ação
        if action == MOVE_LEFT:
            self.current_state = (max(0, self.current_state[0] - 1), self.current_state[1])
        elif action == MOVE_RIGHT:
            self.current_state = (min(self.states - 1, self.current_state[0] + 1), self.current_state[1])
        elif action == MOVE_UP:
            self.current_state = (self.current_state[0], max(0, self.current_state[1] - 1))
        elif action == MOVE_DOWN:
            self.current_state = (self.current_state[0], min(self.states - 1, self.current_state[1] + 1))

        # Verifica se o robô encontrou o botão
        if self.current_state == self.button_position:
            reward = BUTTON_PRESSED_REWARD
            # Se a posição do botão ainda não foi compartilhada, compartilha
            if self.button_position_shared is None:
                self.button_position_shared = self.button_position
                self.button_pressed_by = robot_id
                logger.info(f'Robô {robot_id} pressionou o botão na posição {self.button_position}. Compartilhando a posição do botão.')
        else:
            reward = DEFAULT_REWARD
        return self.current_state, reward

    def reset(self, button_position):
        # Reseta o ambiente para um novo episódio
        self.current_state = (0, 0)
        self.button_position = button_position
        self.button_position_shared = None
        self.button_pressed_by = None

class IMPALA:
    def __init__(self, states, actions, alpha=0.5, gamma=0.9, epsilon=1.0, min_epsilon=0.01, decay_rate=0.995, robot_id=1):
        self.states = states
        self.actions = actions
        self.alpha = alpha
        self.gamma = gamma
        self.epsilon = epsilon
        self.min_epsilon = min_epsilon
        self.decay_rate = decay_rate
        self.q_table = np.zeros((states, states, actions))
        self.robot_id = robot_id
        self.episode_rewards = []
        self.experience_queue = Queue()
        logger.info(f'Algoritmo IMPALA inicializado para o robô {robot_id}.')

    def choose_action(self, state, environment):
        # Escolhe uma ação baseada na política epsilon-greedy ou na política direta se a posição do botão for compartilhada
        if environment.button_position_shared is not None and self.robot_id != environment.button_pressed_by:
            action = self.direct_policy(state, environment.button_position_shared)
        else:
            action = self.epsilon_greedy_policy(state)
        return action

    def epsilon_greedy_policy(self, state):
        # Implementa a política epsilon-greedy
        if np.random.uniform() < self.epsilon:
            action = np.random.choice(self.actions)
        else:
            action = np.argmax(self.q_table[state[0], state[1], :])
        return action

    def direct_policy(self, state, button_position_shared):
        # Implementa uma política direta para se mover em direção ao botão compartilhado
        if state[0] < button_position_shared[0]:
            action = MOVE_RIGHT
        elif state[0] > button_position_shared[0]:
            action = MOVE_LEFT
        elif state[1] < button_position_shared[1]:
            action = MOVE_DOWN
        else:
            action = MOVE_UP
        return action

    def update_q_table(self):
        # Atualiza a Q-table usando as experiências acumuladas
        while not self.experience_queue.empty():
            state, action, reward, next_state = self.experience_queue.get()
            predict = self.q_table[state[0], state[1], action]
            target = reward + self.gamma * np.max(self.q_table[next_state[0], next_state[1], :])
            self.q_table[state[0], state[1], action] += self.alpha * (target - predict)

    def decay_epsilon(self):
        # Decai o valor de epsilon para reduzir a exploração ao longo do tempo
        if self.epsilon > self.min_epsilon:
            self.epsilon *= self.decay_rate

    def calculate_accuracy(self):
        # Calcula a acurácia baseada nas recompensas dos episódios
        return sum(self.episode_rewards) / len(self.episode_rewards) if self.episode_rewards else 0

class Actor(threading.Thread):
    def __init__(self, robot_id, states, actions, button_position, experience_queue):
        threading.Thread.__init__(self)
        self.robot_id = robot_id
        self.environment = Environment(states, button_position)
        self.actions = actions
        self.experience_queue = experience_queue
        self.q_learning = IMPALA(states, actions, robot_id=robot_id)
        logger.info(f'Ator {robot_id} inicializado.')

    def run_episode(self, max_steps):
        state = (0, 0)
        self.environment.current_state = state
        total_reward = 0

        # Executa um episódio de interação com o ambiente
        for step in range(max_steps):
            action = self.q_learning.choose_action(state, self.environment)
            next_state, reward = self.environment.step(action, self.robot_id)
            self.experience_queue.put((state, action, reward, next_state))
            state = next_state
            total_reward += reward
            if reward == BUTTON_PRESSED_REWARD:
                break

        self.q_learning.episode_rewards.append(total_reward)
        self.q_learning.decay_epsilon()
        return total_reward

    def run(self):
        while True:
            self.run_episode(100)

class Learner(threading.Thread):
    def __init__(self, q_table, experience_queue):
        threading.Thread.__init__(self)
        self.q_table = q_table
        self.experience_queue = experience_queue

    def run(self):
        while True:
            while not self.experience_queue.empty():
                state, action, reward, next_state = self.experience_queue.get()
                predict = self.q_table[state[0], state[1], action]
                target = reward + gamma * np.max(self.q_table[next_state[0], next_state[1], :])
                self.q_table[state[0], state[1], action] += alpha * (target - predict)

def add_coordinates(robot_id, episode, x, y):
    filename = os.path.join('data', f'coordinates_{robot_id}.csv')
    try:
        with open(filename, 'a') as f:
            writer = csv.writer(f)
            writer.writerow([robot_id, episode, x, y])
    except IOError:
        logger.error(f"Could not open file {filename} for writing.")

def log_button_position_shared(button_position_shared):
    with open(os.path.join('data', 'button_position_shared.csv'), 'w') as f:
        writer = csv.writer(f)
        writer.writerow(['x', 'y'])
        if button_position_shared is not None:
            writer.writerow(button_position_shared)
        else:
            writer.writerow([0, 0])  # ou qualquer outro valor padrão

def log_accuracy_table(robot1, robot2):
    table_data = [
        ['Robot 1', robot1.q_learning.calculate_accuracy()],
        ['Robot 2', robot2.q_learning.calculate_accuracy()]
    ]
    table = tabulate(table_data, headers=['Robot', 'Accuracy'], tablefmt='grid')
    logger.info(f'\n{table}')

if __name__ == "__main__":
    states = 10
    actions = [MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN]

    num_episodes = 100  # Número de episódios para evitar erro
    max_steps_per_episode = 100

    experience_queue = Queue()

    # Inicializa dois atores (robôs)
    actor1 = Actor(1, states, len(actions), Button.generate_position(), experience_queue)
    actor2 = Actor(2, states, len(actions), actor1.environment.button_position, experience_queue)

    # Inicializa o aprendiz
    learner = Learner(actor1.q_learning.q_table, experience_queue)

    # Inicia os atores e o aprendiz
    actor1.start()
    actor2.start()
    learner.start()

    # Coleta dados e logs durante os episódios
    for episode in range(num_episodes):
        # Registra as coordenadas dos robôs
        add_coordinates(1, episode, actor1.environment.current_state[0], actor1.environment.current_state[1])
        add_coordinates(2, episode, actor2.environment.current_state[0], actor2.environment.current_state[1])

        logger.info(f'Episódio {episode}: Recompensa total do robô 1: {sum(actor1.q_learning.episode_rewards)}')
        logger.info(f'Episódio {episode}: Recompensa total do robô 2: {sum(actor2.q_learning.episode_rewards)}')

        if actor1.environment.button_position_shared and actor2.environment.button_position_shared:
            logger.info(f"Botão pressionado por ambos os robôs no episódio {episode}, gerando nova posição do botão.")
            new_button_position = Button.generate_position()
            actor1.environment.reset(new_button_position)
            actor2.environment.reset(new_button_position)
            actor2.environment.button_position_shared = actor1.environment.button_position_shared

    # Salva as Q-tables dos robôs
    np.save(os.path.join('notebooks', 'q_table_robot1.npy'), actor1.q_learning.q_table)
    np.save(os.path.join('notebooks', 'q_table_robot2.npy'), actor2.q_learning.q_table)

    logger.info(f'Posição final do botão compartilhado: {actor1.environment.button_position_shared}')

    log_button_position_shared(actor1.environment.button_position_shared)

    # Registra os pressionamentos de botão
    with open(os.path.join('data', 'button_press_records.csv'), 'w') as f:
        writer = csv.writer(f)
        writer.writerow(['Robot ID', 'Button Pressed'])
        writer.writerow([1, 1 if actor1.environment.button_position_shared else 0])
        writer.writerow([2, 1 if actor2.environment.button_position_shared else 0])

    # Imprime a acurácia
    log_accuracy_table(actor1, actor2)

    logger.info('Processo de aprendizado concluído.')
