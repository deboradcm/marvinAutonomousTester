package com.example.marvin;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;

import android.util.DisplayMetrics;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.persist.MqttDefaultFilePersistence;
import org.json.JSONException;
import org.json.JSONObject;
import com.google.gson.Gson;

import java.util.Random;


public class MainActivity extends AppCompatActivity implements CoordinatesListener{

    private Button randomCornerButton1;
    private Button northButton;
    private Button southButton;
    private Button topLeftButton;
    private Button topRightButton;
    private Button bottomLeftButton;
    private Button bottomRightButton;
    private Button wandering1;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Inicia a assinatura do tópico MQTT
        MQTTSubscriber subscriber = new MQTTSubscriber();
        subscriber.setCoordinatesListener(this); // Configura a MainActivity como ouvinte de coordenadas
        subscriber.start();

        randomCornerButton1 = findViewById(R.id.randomCornerButton1);
        northButton = findViewById(R.id.northButton);
        southButton = findViewById(R.id.southButton);
        topLeftButton = findViewById(R.id.topLeftButton);
        topRightButton = findViewById(R.id.topRightButton);
        bottomLeftButton = findViewById(R.id.bottomLeftButton);
        bottomRightButton = findViewById(R.id.bottomRightButton);
        wandering1 = findViewById(R.id.wandering1);

        WindowManager windowManager = getWindowManager();
        ButtonBorder.setupRandomMoveOnClick(randomCornerButton1, windowManager, northButton, this );
        ButtonNorth.setupRandomMoveOnClick(northButton, windowManager,southButton, this );
        ButtonSouth.setupRandomMoveOnClick(southButton, windowManager, topRightButton, this);
        ButtonTopRight.setupRandomMoveOnClick(topRightButton, windowManager, topLeftButton, this);
        ButtonTopLeft.setupRandomMoveOnClick(topLeftButton, windowManager, bottomRightButton, this);
        ButtonBottomRight.setupRandomMoveOnClick(bottomRightButton, windowManager, bottomLeftButton, this);
        ButtonBottomLeft.setupRandomMoveOnClick(bottomLeftButton, windowManager, wandering1, this);

    }

    @Override
    public void onCoordinatesReceived(int x, int y, boolean inicio, int id_robot) {
        // Encaminha a lógica para ButtonBorder
        ButtonBorder.onCoordinatesReceived(x, y, inicio, id_robot);
    }


     public void enviarDadosParaServidor(boolean inicio, int id_robot) {
        Log.d("MainActivity", "Enviando dados para o servidor MQTT.");
        Log.d("MainActivity", "Clique manual detectado. Enviando dados para o servidor MQTT.");
        try {
            Retorno retorno = new Retorno();
            if (inicio == true) {
                retorno.setRetorno("true");
            } else{
                retorno.setRetorno("false");
            }

            retorno.setId_robot(id_robot);

            // Converte a instância de Evento em JSON
            Gson gson = new Gson();
            String jsonRetorno = gson.toJson(retorno);

            // Imprime o JSON no Logcat
            Log.d("JSON", jsonRetorno);

            // Obtém o caminho para o diretório de persistência de arquivos
            String persistencePath = getApplicationContext().getFilesDir().getAbsolutePath();

            // Cria uma instância do cliente MQTT usando o caminho de persistência de arquivos personalizado
            MqttClient client = new MqttClient("tcp://broker.hivemq.com:1883", MqttClient.generateClientId(), new MqttDefaultFilePersistence(persistencePath));

            // Conecta-se ao servidor MQTT
            client.connect();

            // Cria uma mensagem MQTT com o JSON como payload
            MqttMessage message = new MqttMessage(jsonRetorno.getBytes());

            // Publica a mensagem em um tópico MQTT
            client.publish("mqtt_topic", message);

            // Desconecta do servidor MQTT após a publicação
            client.disconnect();

        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

    public void sendDataToServer(String evento, int x, int y, String buttonTag) {
        try {
            Evento eventoObj = new Evento();
            eventoObj.setEvento(evento);

            // Preenche as coordenadas e a tag do botão no objeto Dados
            Dados dados = new Dados();
            dados.setX(x);
            dados.setY(y);
            dados.setButtonTag(buttonTag);

            eventoObj.setDados(dados);

            JSONObject jsonEvento = new JSONObject();
            jsonEvento.put("x", eventoObj.getDados().getX());
            jsonEvento.put("y", eventoObj.getDados().getY());
            jsonEvento.put("event", eventoObj.getEvento());
            // Verifica se a tag do botão não está vazia antes de adicioná-la ao JSON
            if (!eventoObj.getDados().getButtonTag().isEmpty()) {
                jsonEvento.put("button", eventoObj.getDados().getButtonTag());
            }

            // Obtém o caminho para o diretório de persistência de arquivos
            String persistencePath = getApplicationContext().getFilesDir().getAbsolutePath();

            // Cria uma instância do cliente MQTT usando o caminho de persistência de arquivos personalizado
            MqttClient client = new MqttClient("tcp://broker.hivemq.com:1883", MqttClient.generateClientId(), new MqttDefaultFilePersistence(persistencePath));

            // Conecta-se ao servidor MQTT
            client.connect();

            // Cria uma mensagem MQTT com o JSON como payload
            MqttMessage message = new MqttMessage(jsonEvento.toString().getBytes());

            // Publica a mensagem em um tópico MQTT
            client.publish("app/robot_interactions", message);

            // Desconecta do servidor MQTT após a publicação
            client.disconnect();

        } catch (MqttException | JSONException e) {
            Log.e("TAG", "Erro ao processar MQTT ou JSON: " + e.getMessage(), e);
        }
    }

    private boolean isDragging = false;
    private float startX, startY;

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        Log.d("TOUCH_EVENT", "X: " + event.getX() + ", Y: " + event.getY() + ", Action: " + event.getAction());

        int x = (int) event.getX();
        int y = (int) event.getY();

        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                startX = event.getX(); // acessando a variável startX
                startY = event.getY(); // acessando a variável startY
                isDragging = false;
                break;
            case MotionEvent.ACTION_MOVE:
                if (!isDragging && isDragging(x, y)) {
                    // Se o usuário começar a arrastar, é marcado como arrastando
                    isDragging = true;
                    sendDataToServer("button_drag_start", x, y, "");
                }
                break;

            case MotionEvent.ACTION_UP:
                if (isDragging) {
                    // Se o usuário estava arrastando e parou, é enviada uma mensagem indicando o fim do arrasto
                    sendDataToServer("button_drag_end", x, y, "");
                    isDragging = false;
                } else {
                    // Se não houve arrasto e o dedo foi levantado, verifique se foi um clique fora dos botões
                    if (!isInsideButton(x, y)) {
                        sendDataToServer("click_outside_button", x, y, "");
                    }
                }
                break;
        }

        return super.onTouchEvent(event);
    }

    private boolean isInsideButton(int x, int y) {
        // Verifica cada botão individualmente
        if (isInsideView(x, y, wandering1) ||
                isInsideView(x, y, northButton) || isInsideView(x, y, southButton) || isInsideView(x, y, topLeftButton) ||
                isInsideView(x, y, topRightButton) || isInsideView(x, y, bottomLeftButton) || isInsideView(x, y, bottomRightButton) ||
                isInsideView(x, y, randomCornerButton1)) {
            return true;
        }
        return false;
    }

    private boolean isInsideView(int x, int y, View view) {
        int[] location = new int[2];
        view.getLocationOnScreen(location);
        int viewX = location[0];
        int viewY = location[1];
        int viewWidth = view.getWidth();
        int viewHeight = view.getHeight();

        return (x >= viewX && x <= (viewX + viewWidth) && y >= viewY && y <= (viewY + viewHeight));
    }

    private boolean isDragging(int x, int y) {
        // Calcula a distância entre o ponto inicial e o ponto atual
        double distance = Math.sqrt(Math.pow(x - startX, 2) + Math.pow(y - startY, 2));
        // Se a distância for maior que um determinado limite, consideramos que o usuário está arrastando
        return distance > TOUCH_SLOP;
    }

    private static final int TOUCH_SLOP = 20;

    private void moveButtonRandomly(Button button) {
        DisplayMetrics displayMetrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(displayMetrics);
        int screenWidth = displayMetrics.widthPixels;
        int screenHeight = displayMetrics.heightPixels;

        int buttonWidth = button.getWidth();
        int buttonHeight = button.getHeight();

        int margin = 100; // Margem de 100 pixels em todas as direções

        int randomX = (int) (Math.random() * (screenWidth - buttonWidth - 2 * margin) + margin);
        int randomY = (int) (Math.random() * (screenHeight - buttonHeight - 2 * margin) + margin);

        button.setX(randomX);
        button.setY(randomY);

    }


}




