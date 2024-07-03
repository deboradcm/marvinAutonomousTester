import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import paho.mqtt.client as mqtt
from rclpy.qos import qos_profile_system_default
import json
from rclpy.action import ActionClient
from action_marvin_interfaces.action import Hover

class HoverActionClient(Node):
    '''broker_address = "broker.hivemq.com"
    mqtt_topic = "hover_data"'''

    def __init__(self):
        super().__init__('hover_action_client')
        self._action_client = ActionClient(
            self,
            Hover,
            'hover_action'
        )
        
        '''self._mqtt_client = mqtt.Client()
        self._mqtt_client.connect(self.broker_address, 1883)'''


    def send_goal(self, initial_x, initial_y, initial_z, final_x, final_y, final_z): #alguns projetos usam esse metodo como assincrono, é necessario?
        goal_msg = Hover.Goal()
        goal_msg.message = 'hover'
        goal_msg.initial_x = initial_x
        goal_msg.initial_y = initial_y
        goal_msg.initial_z = initial_z
        goal_msg.final_x = final_x
        goal_msg.final_y = final_y
        goal_msg.final_z = final_z

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: {0} - x: {1}, y: {2}'.format(result.message, result.x, result.y))

        '''# Publicar o resultado no tópico MQTT
        hover_data = {
            "message": result.message,
            "x": result.x,
            "y": result.y
        }
        self._mqtt_client.publish(self.mqtt_topic, json.dumps(hover_data).encode())'''

        rclpy.shutdown()

    def feedback_callback(self, feedback_msg): #alguns projetos usam esse metodo como assincrono, é necessario?
        self.get_logger().info(f'Received feedback: {feedback_msg.feedback.message} at ({feedback_msg.feedback.current_x}, {feedback_msg.feedback.current_y})')

def main(args=None):
    rclpy.init(args=args)
    hover_action_client = HoverActionClient()
    hover_action_client.send_goal(100, 120, 180, 200, 220, 280)
    rclpy.spin(hover_action_client)
    #rclpy.shutdown()

if __name__ == '__main__':
    main()
