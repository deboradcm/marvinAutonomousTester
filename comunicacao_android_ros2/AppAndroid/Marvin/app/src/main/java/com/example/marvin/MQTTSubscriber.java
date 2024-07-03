package com.example.marvin;

import static androidx.constraintlayout.helper.widget.MotionEffect.TAG;

import android.util.Log;
import com.google.gson.Gson;
import java.lang.reflect.Type;
import java.util.Map;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

public class MQTTSubscriber {
    private CoordinatesListener coordinatesListener;
    private static final String BROKER_URL = "tcp://broker.hivemq.com:1883"; // Endereço do servidor MQTT
    private static final String TOPIC = "hover_data"; // Tópico MQTT que desejo assinar

    // Método para configurar o ouvinte de coordenadas
    public void setCoordinatesListener(CoordinatesListener listener) {
        this.coordinatesListener = listener;
    }

    public void start() {
        try {
            // Cria um cliente MQTT
            MqttClient client = new MqttClient(BROKER_URL, MqttClient.generateClientId(), new MemoryPersistence());

            // Configura opções de conexão
            MqttConnectOptions options = new MqttConnectOptions();
            options.setAutomaticReconnect(true);

            // Define um callback para processar as mensagens recebidas
            client.setCallback(new MqttCallback() {
                @Override
                public void connectionLost(Throwable cause) {
                    // Registrar a perda de conexão
                    Log.d(TAG, "Conexão perdida com o servidor MQTT: " + cause.getMessage());

                    // Tenta reconectar automaticamente
                    reconnectToBroker(client);
                }

                private void reconnectToBroker(MqttClient client) {
                    try {
                        // Tenta reconectar ao servidor MQTT
                        client.connect();
                    } catch (MqttException e) {
                        e.printStackTrace();
                        // Lida com erros de reconexão, se necessário
                    }
                }

                @Override
                public void messageArrived(String topic, MqttMessage message) throws Exception {
                    // Processa a mensagem recebida
                    String payload = new String(message.getPayload());
                    System.out.println("Nova mensagem no tópico '" + topic + "': " + payload);

                    // Use o Gson para analisar a string JSON em um objeto Map
                    Gson gson = new Gson();
                    Type type = new com.google.gson.reflect.TypeToken<Map<String, String>>(){}.getType();
                    Map<String, String> payloadMap = gson.fromJson(payload, type);

                    // Acesse os valores do dicionário usando as chaves
                    String message_ = payloadMap.get("message");
                    String currentX = payloadMap.get("current_x");
                    String currentY = payloadMap.get("current_y");

                    // Faça o que você precisa com os valores
                    System.out.println("Message: " + message_);
                    System.out.println("Current X: " + currentX);
                    System.out.println("Current Y: " + currentY);

                    if ("starting".equals(message_)) {
                        // Notifica a MainActivity sobre as coordenadas recebidas
                        if (coordinatesListener != null) {
                            coordinatesListener.onCoordinatesReceived(Integer.parseInt(currentX), Integer.parseInt(currentY), true);
                        }
                    } else if ("finish".equals(message_)) {
                        // Notifica a MainActivity sobre as coordenadas recebidas
                        if (coordinatesListener != null) {
                            coordinatesListener.onCoordinatesReceived(Integer.parseInt(currentX), Integer.parseInt(currentY), false);
                        }
                    }
                }

                @Override
                public void deliveryComplete(IMqttDeliveryToken token) {
                    // Implementa o que fazer quando a entrega da mensagem é completa
                    // Obtém o ID do token de entrega
                    int deliveryTokenId = token.getMessageId();

                    // Verifica se a entrega foi bem-sucedida
                    if (token.isComplete()) {
                        System.out.println("Mensagem entregue com sucesso. ID do token de entrega: " + deliveryTokenId);
                    } else {
                        System.out.println("Falha na entrega da mensagem. ID do token de entrega: " + deliveryTokenId);
                    }
                }
            });

            // Conecta ao servidor MQTT
            client.connect(options);

            // Inscreva-se no tópico
            client.subscribe(TOPIC);

        } catch (MqttException e) {
            e.printStackTrace();
        }
    }
}
