import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_marvin_interfaces.action import Hover

class HoverActionServer(Node):
    def __init__(self):
        super().__init__('mqtt_to_action_server')
        self._action_server = ActionServer(
            self,
            Hover,
            'hover_action',
            execute_callback=self.execute_callback)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing hover action...')

        feedback_msg = Hover.Feedback()
        feedback_msg.message = 'Starting hover action'
        feedback_msg.x = goal_handle.request.x  # Utiliza o valor de x fornecido como meta
        feedback_msg.y = goal_handle.request.y  # Utiliza o valor de y fornecido como meta
        #feedback: dizer onde o robo está atualmente até chegar na coordenada nova (deslocamento)
        #mensagem: está se movendo e posição: um valor que vai diminuindo conforme ele vai se aproximando da coordenada enviada.
        #se ele passar muito tempo sem que ele consiga atingir o destino dele ele tem que retornar falha e cancelar a operação

        # Simulando ação de hover
        #a ação real dele será passar essas coordenadas para o robo
        for i in range(10):  # Simular 10 passos
            feedback_msg.message = f'Hover step {i+1}'
            goal_handle.publish_feedback(feedback_msg)
            self.get_logger().info(f'Feedback: {feedback_msg.message} at ({feedback_msg.x}, {feedback_msg.y})')
            rclpy.spin_once(self, timeout_sec=1)  # Aguardar 1 segundo entre os passos

        goal_handle.succeed()
        
        result_msg = Hover.Result()
        result_msg.x = feedback_msg.x  # Mantém a mesma posição x
        result_msg.y = feedback_msg.y  # Mantém a mesma posição y
        return result_msg

def main(args=None):
    rclpy.init(args=args)
    hover_action_server = HoverActionServer()
    rclpy.spin(hover_action_server)

if __name__ == '__main__':
    main()
