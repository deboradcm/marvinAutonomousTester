# Marvin
Projeto de Teste automático colaborativo em múltiplos dispositivos da Especialização em IA para Engenharia de Testes de Software

```
source install/setup.bash
ros2 launch marvin_bringup marvin_launch.py
```

Execução da comunicação android-robo-ros2:
```
pip install paho-mqtt

colcon build 

1. action client enviando dados de coordenadas falsas:
ros2 run action_robo_v1 robo_action_client

2. Server action recebendo os dados:
ros2 run action_robo_v1 robo_action_server

3. topico criado em contato com o MQTT:
ros2 run mqtt_publish mqtt_publish
```
