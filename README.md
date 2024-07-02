# Marvin
## Projeto de Teste Automático Colaborativo em Múltiplos Dispositivos

Este projeto faz parte da Especialização em IA para Engenharia de Testes de Software.

## Requisitos

- Ubuntu 22.04.4 LTS (jammy)
- [Ros2-Humble](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)
- [Gazebo 11.10.2](https://classic.gazebosim.org/tutorials?tut=install_ubuntu)

## Instalando o projeto
```
git clone https://github.com/deboradcm/marvinAutonomousTester.git
cd marvinAutonomousTester/ros2_marvin/src/Universal_Robots_ROS2_Gazebo_Simulation
git clone -b humble https://github.com/deboradcm/Universal_Robots_ROS2_Gazebo_Simulation.git .

```
## Adicionando o Smartphone à Simulação no Gazebo

Para adicionar o smartphone à simulação no Gazebo, siga estes passos:

1. **Baixe o Modelo do Smartphone:**

    Baixe o modelo do telefone em [aqui](https://app.gazebosim.org/OpenRobotics/fuel/models/Phone).

2. **No Terminal:**

    ```bash
    cd ~/.gazebo
    ```

3. **Crie o Diretório `models`:**

    Se o diretório não existir, crie-o:

    ```bash
    mkdir models
    cd models
    ```

4. **Copie o Modelo do Smartphone:**

    Copie o modelo do telefone para dentro da pasta. No exemplo abaixo, estamos copiando o modelo Phone da pasta Downloads para a pasta models:

    ```bash
    cp -r ~/Downloads/Phone ~/.gazebo/models/
    ```

## Para executar o projeto

```bash
cd marvinAutonomousTester/ros2_marvin
colcon build 
source install/setup.bash
ros2 launch ur_simulation_gazebo ur_sim_control.launch.py ur_type:=ur3
