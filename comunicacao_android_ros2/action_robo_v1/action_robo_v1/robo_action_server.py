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

    def listener_callback(self, msg):
        data = json.loads(msg.data)
        self._received_touch =  data['retorno']
        self.get_logger().info('Received: %s' % self._received_touch)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing hover action...')

        goal = goal_handle.request
        initial_x = goal.initial_x
        initial_y = goal.initial_y
        initial_z = goal.initial_z
        final_x = goal.final_x
        final_y = goal.final_y
        final_z = goal.final_z
        msg = 'starting'

        distance_x = final_x - initial_x
        distance_y = final_y - initial_y
        distance_z = final_z - initial_z

        num_steps = 100
        step_size_x = distance_x // num_steps
        step_size_y = distance_y // num_steps
        step_size_z = distance_z // num_steps

        for step in range(num_steps):
            if self._received_touch == 'true':
                break
            
            current_x = initial_x + step * step_size_x
            current_y = initial_y + step * step_size_y
            current_z = initial_z + step * step_size_z

            #o current vai ser mandado para o robo
            
            #o feedback vai ser mandado para o android
            if step == num_steps-1:
                msg = 'finish'
            feedback_msg = Hover.Feedback()
            feedback_msg.message = msg
            feedback_msg.current_x = current_x  
            feedback_msg.current_y = current_y  
            feedback_msg.current_z = current_z  
    
            goal_handle.publish_feedback(feedback_msg)
            self.get_logger().info(f'Feedback: {feedback_msg.message} at ({feedback_msg.current_x}, {feedback_msg.current_y})')

            # Publicar o feedback no tópico MQTT
            hover_data = {
                "message": feedback_msg.message,
                "current_x": feedback_msg.current_x,    
                "current_y": feedback_msg.current_y,
                "current_z": feedback_msg.current_z,
            }
            
            self._mqtt_client.publish(self.mqtt_topic, json.dumps(hover_data).encode())

            rclpy.spin_once(self, timeout_sec=2)  # Aguardar 1 segundos entre os passos

        goal_handle.succeed()
            
        result_msg = Hover.Result()
        result_msg.message = "finish"
        result_msg.x = feedback_msg.current_x  # Mantém a mesma posição x
        result_msg.y = feedback_msg.current_y  # Mantém a mesma posição y
        result_msg.z = feedback_msg.current_z  # Mantém a mesma posição z

        if self._received_touch == 'false':
            hover_data = {
                "message": "failure",
                "initial_x": initial_x,
                "initial_y": initial_y,
                "initial_z": initial_z,
                "final_x": final_x,
                "final_y": final_y,
                "final_z": final_z,
            }
            
            self._mqtt_client.publish(self.mqtt_topic, json.dumps(hover_data).encode())
            return result_msg
        
        hover_data = {
            "message": "success",
            "current_x": feedback_msg.current_x,    
            "current_y": feedback_msg.current_y,
            "current_z": feedback_msg.current_z,
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
