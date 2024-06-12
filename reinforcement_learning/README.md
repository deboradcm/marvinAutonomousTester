# Q-Learning Multiagente

## Descrição

Este projeto implementa um algoritmo Q-Learning para dois robôs que aprendem a encontrar um botão em um ambiente 2D. Os robôs colaboram compartilhando a posição do botão quando um deles o pressiona. A implementação utiliza aprendizado por reforço, onde cada robô interage com o ambiente, realiza ações e recebe recompensas baseadas nessas ações. 

### Funcionamento do Algoritmo

1. **Ambiente**: Um ambiente 2D onde um botão é posicionado aleatoriamente.
2. **Ações**: Os robôs podem se mover para a esquerda, direita, para cima ou para baixo.
3. **Recompensas**:
    - Pressionar o botão: +100 pontos.
    - Movimentos sem pressionar o botão: -1 ponto.
4. **Q-Learning**: Cada robô mantém uma tabela Q para atualizar seus valores Q (Q-values) com base na equação de Bellman.
5. **Política**: Inicialmente, a política é exploratória (alta epsilon), mas torna-se mais exploratória conforme a aprendizagem progride (epsilon decai).

## Dependências

Instale as seguintes dependências:

obs: melhor criar um ambiente virtual

pip install -r requirements.txt

## Como Executar

cd robotic-arm-project/src
python3 reinforcement_learning.py

Obs: Necessário executar várias vezes para obter melhores resultados

# Estrutura de Diretórios
log/: Contém arquivos de log detalhados.
data/:
coordinates_robot1.csv: Coordenadas do robô 1 por episódio.
coordinates_robot2.csv: Coordenadas do robô 2 por episódio.
button_position_shared.csv: Posição compartilhada do botão.
button_press_records.csv: Registro de quais robôs pressionaram o botão.
notebooks/:
q_table_robot1.npy
q_table_robot2.npy

# Personalização
Ajuste os seguintes parâmetros no script principal conforme necessário:

Número de estados: states
Ações possíveis: actions
Parâmetros do Q-Learning: alpha, gamma, epsilon, min_epsilon, decay_rate


# artigos

Watkins, C.J.C.H., Dayan, P. (1992). Q-learning. Machine Learning, 8(3-4), 279–292. 

Sutton, R.S., Barto, A.G. (2018). Reinforcement Learning: An Introduction. MIT Press. 

Mnih, V., Kavukcuoglu, K., Silver, D., et al. (2015). Human-level control through deep reinforcement learning. Nature, 518(7540), 529–533. 

Watkins, C.J.C.H. (1989). Learning from Delayed Rewards. PhD thesis, University of Cambridge, England. 