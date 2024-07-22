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
    private CoordinateConverter coordinateConverter;
    private static final String BROKER_URL = "tcp://broker.hivemq.com:1883"; // Endereço do servidor MQTT
    private static final String TOPIC = "hover_data"; // Tópico MQTT que desejo assinar

    // Dimensões da tela como constantes
    private static final double SCREEN_WIDTH_METERS = 0.062;
    private static final double SCREEN_HEIGHT_METERS = 0.110;
    private static final int SCREEN_WIDTH_PIXELS = 1080;
    private static final int SCREEN_HEIGHT_PIXELS = 2220;

    public MQTTSubscriber() {
        this.coordinateConverter = new CoordinateConverter(SCREEN_WIDTH_METERS, SCREEN_HEIGHT_METERS, SCREEN_WIDTH_PIXELS, SCREEN_HEIGHT_PIXELS);
    }

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
                    double currentX = Double.parseDouble(payloadMap.get("current_x")); // Convertendo String para double
                    double currentY = Double.parseDouble(payloadMap.get("current_y")); // Convertendo String para double
                    String currentZ = payloadMap.get("current_z"); // Este valor não está sendo usado para conversão
                    int id_robot = Integer.parseInt(payloadMap.get("id_robot"));

                    // Convertendo coordenadas
                    int[] pixelCoords = coordinateConverter.convertMetersToPixels(currentX, currentY);
                    System.out.println("Pixel Coordinates: x=" + pixelCoords[0] + ", y=" + pixelCoords[1]);

                    // Ações baseadas na mensagem
                    if ("starting".equals(message_)) {
                        if (coordinatesListener != null) {
                            coordinatesListener.onCoordinatesReceived(pixelCoords[0], pixelCoords[1], true, id_robot);
                        }
                    } else if ("finish".equals(message_)) {
                        if (coordinatesListener != null) {
                            coordinatesListener.onCoordinatesReceived(pixelCoords[0], pixelCoords[1], false, id_robot);
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
