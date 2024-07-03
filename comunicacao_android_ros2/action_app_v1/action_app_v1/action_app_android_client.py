import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from std_msgs.msg import String
import paho.mqtt.client as mqtt
import json

from action_marvin_interfaces.action import Hover


class MQTTToActionClient(Node):
    def __init__(self):
        super().__init__('mqtt_to_action_client')
        self.client_action = ActionClient(self, Hover, 'hover_action')  
        self.client = mqtt.Client()
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message
        self.client.connect('broker.hivemq.com', 1883)
        self.client.subscribe('mqtt_topico')
        self.client.loop_forever()

    def on_connect(self, client, userdata, flags, rc):
        self.get_logger().info("Connected to MQTT broker with result code %d." % rc)

    def on_message(self, client, userdata, msg):
        try:
            data = json.loads(msg.payload.decode())
            print(data)
            self.send_goal(data)  # Envia os dados recebidos do MQTT como meta para o servidor Action
            self.get_logger().info("Received MQTT data and sent as goal to Action server.")
        except Exception as e:
            self.get_logger().error("Error parsing MQTT message: %s" % str(e))

    def send_goal(self, data):
        goal_msg = Hover.Goal()
        goal_msg.message = data['evento']
        goal_msg.x = data['dados']['x']
        goal_msg.y = data['dados']['y']
        
        self.client_action.wait_for_server()
        self._send_goal_future = self.client_action.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
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

        rclpy.shutdown()

    def feedback_callback(self, feedback_msg): #alguns projetos usam esse metodo como assincrono, é necessario?
        self.get_logger().info(f'Received feedback: {feedback_msg.feedback.message} at ({feedback_msg.feedback.x}, {feedback_msg.feedback.y})')

def main(args=None):
    rclpy.init(args=args)
    node = MQTTToActionClient()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
