# Marvin
## Projeto de Teste Automático Colaborativo em Múltiplos Dispositivos

Este projeto faz parte da Especialização em IA para Engenharia de Testes de Software.

## Requisitos

- Ubuntu-22.04.1
- Ros2-Humble
- Gazebo 11.10.2

## Instalando o projeto
```
git clone --recurse-submodules https://github.com/deboradcm/marvinAutonomousTester.git
cd marvinAutonomousTester/ros2_marvin
colcon build
```
## Erros comuns 
Se você encontrar um erro indicando que o pacote 'diagnostic_updater' não foi localizado, será necessário instalar o pacote utilizando o terminal.
```
sudo apt-get update
sudo apt-get install ros-humble-diagnostic-updater
```
Outro erro comun esta relacionado ao arquivo test_hardware_management_srvs.cpp
```
cd :~/marvinAutonomousTester/ros2_marvin/src/ros2_marvin/src/ros2_control/controller_manager/test
code test_hardware_management_srvs.cpp
```
E altere as linhas 150, 162 e 174 removendo o termo "PLUGIN"<br><br>
Exemplo: A linha  150 vai de "TEST_ACTUATOR_HARDWARE_PLUGIN_NAME" para "TEST_ACTUATOR_HARDWARE_NAME"<br><br>
Nas linhas 42, 47 e 52 também faça a remoção do termo "PLUGIN" 



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
