import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from std_msgs.msg import String
import paho.mqtt.client as mqtt
from rclpy.qos import qos_profile_system_default
import json
import math
from threading import Thread
from action_marvin_interfaces.action import Hover

class HoverActionServer(Node):
    broker_address = "broker.hivemq.com"
    mqtt_topic = "hover_data"

    def __init__(self):
        super().__init__('hover_action_server')
        self._action_server = ActionServer(
            self,
            Hover,
            'hover_action',
            execute_callback=self.execute_callback)
        
        self._mqtt_client = mqtt.Client()
        self._mqtt_client.connect(self.broker_address, 1883)
        
        # Inicia uma thread separada para lidar com o cliente MQTT
        mqtt_thread = Thread(target=self.mqtt_loop)
        mqtt_thread.start()

        #se inscreve no topico que recebe os dados do android app
        self.subscription = self.create_subscription(
            String,
            'mqtt_data',
            self.listener_callback,
            10)
        self._received_touch = 'false'
        self.id_robot = None

    def listener_callback(self, msg):
        data = json.loads(msg.data)
        #se o id_robot for diferente de None e se o id for igual ao recebido entao o _received_touch é atualizado
        if self.id_robot:
            if self.id_robot == data['id_robot']:
                self._received_touch =  data['retorno']

        self.get_logger().info('Received: %s' % self._received_touch)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing hover action...')

        goal = goal_handle.request
        self.id_robot = goal.id_robot
        initial_x = goal.initial_x
        initial_y = goal.initial_y
        initial_z = goal.initial_z
        final_x = goal.final_x
        final_y = goal.final_y
        final_z = goal.final_z
        msg = 'starting'

        self.get_logger().info(f'final_x: {final_x}')
        # Calcula a distância a ser percorrida em cada eixo
        distance_x = final_x - initial_x
        distance_y = final_y - initial_y
        distance_z = final_z - initial_z
        self.get_logger().info(f'{distance_x}')
        self.get_logger().info(f'{distance_y}')
        self.get_logger().info(f'{distance_z}')
        # Define o número de passos e o tamanho do passo para cada eixo
        num_steps = 5
        step_size_x = distance_x / num_steps
        step_size_y = distance_y / num_steps
        step_size_z = distance_z / num_steps

        for step in range(num_steps):
            # Verifica se um toque foi recebido (condição de parada)
            if self._received_touch == 'true':
                break
            
            self.get_logger().info(f'{step}')
            self.get_logger().info(f'{step_size_x}')
            # Calcula a posição atual com base no passo atual utilizando interpolação linear
            current_x = initial_x + step * step_size_x
            current_y = initial_y + step * step_size_y
            current_z = initial_z + step * step_size_z
            self.get_logger().info(f'{current_x}')

            #o current vai ser mandado para o robo
            
            ## Atualiza a mensagem para "finish" no último passo
            if step == num_steps-1:
                msg = 'finish'
            
            #o feedback vai ser enviado para o conversor
            feedback_msg = Hover.Feedback()
            feedback_msg.message = msg
            feedback_msg.current_x = current_x  
            feedback_msg.current_y = current_y  
            feedback_msg.current_z = current_z  
    
            goal_handle.publish_feedback(feedback_msg)
            #caso algo nao funcione, tirar esse current_z
            self.get_logger().info(f'Feedback: {feedback_msg.message} at ({feedback_msg.current_x}, {feedback_msg.current_y}, {feedback_msg.current_z})')

            # Publica as coordenadas convertidas no tópico MQTT
            hover_data = {
                "message": feedback_msg.message,
                "id_robot": self.id_robot,
                "current_x": feedback_msg.current_x,    
                "current_y": feedback_msg.current_y,
                "current_z": feedback_msg.current_z,
                "initial_x": initial_x,
                "initial_y": initial_y,
                "initial_z": initial_z,
                "final_x": final_x,
                "final_y": final_y,
                "final_z": final_z
            }
            
            self._mqtt_client.publish(self.mqtt_topic, json.dumps(hover_data).encode())

            rclpy.spin_once(self, timeout_sec=1)  # Aguarda 1 segundos entre os passos

        # Indica que o objetivo foi alcançado com sucesso
        goal_handle.succeed()
        
        # Cria uma mensagem de resultado final
        result_msg = Hover.Result()
        result_msg.message = "finish"
        result_msg.id_robot = self.id_robot
        result_msg.x = feedback_msg.current_x  # Mantém a mesma posição x
        result_msg.y = feedback_msg.current_y  # Mantém a mesma posição y
        result_msg.z = feedback_msg.current_z  # Mantém a mesma posição z

        # Verifica se o toque não foi recebido, indicando falha
        if self._received_touch == 'false':
            hover_data = {
                "message": "failure",
                "id_robot": self.id_robot,
                "initial_x": initial_x,
                "initial_y": initial_y,
                "initial_z": initial_z,
                "final_x": final_x,
                "final_y": final_y,
                "final_z": final_z,
            }
            
            self._mqtt_client.publish(self.mqtt_topic, json.dumps(hover_data).encode())
            return result_msg
        
        # Publica uma mensagem de sucesso no tópico MQTT
        #QUANDO A MSG FOR DE SUCESSO, FAZER COM QUE A IA RESET AS TRAJETORIAS DE FALHA
        hover_data = {
            "message": "success",
            "id_robot": self.id_robot,
            "current_x": feedback_msg.current_x,    
            "current_y": feedback_msg.current_y,
            "current_z": feedback_msg.current_z,
            "initial_x": initial_x,
            "initial_y": initial_y,
            "initial_z": initial_z,
            "final_x": final_x,
            "final_y": final_y,
            "final_z": final_z
        }
            
        self._mqtt_client.publish(self.mqtt_topic, json.dumps(hover_data).encode())
        

        return result_msg

    def mqtt_loop(self):
        self._mqtt_client.loop_forever()

def main(args=None):
    rclpy.init(args=args)
    hover_action_server = HoverActionServer()
    rclpy.spin(hover_action_server)

if __name__ == '__main__':
    main()
