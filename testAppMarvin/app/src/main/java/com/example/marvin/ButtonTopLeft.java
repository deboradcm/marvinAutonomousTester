package com.example.marvin;

import android.util.DisplayMetrics;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import java.util.Random;

public class ButtonTopLeft {

    private static int physicalClickCount = 0;
    private static int virtualClickCount = 0;
    private static int clickGeneralCount = 0;
    private static int topLeftButtonX;
    private static int topLeftButtonY;
    private static int topLeftButtonWidth;
    private static int topLeftButtonHeight;
    private static Button button;
    private static WindowManager windowManager;
    private static MainActivity mainActivity;

    // Configura o comportamento do botão
    public static void setupRandomMoveOnClick(final Button btn, final WindowManager wm, final Button replacementButton, MainActivity mainAct) {
        button = btn;
        windowManager = wm;
        mainActivity = mainAct;

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                physicalClickCount++;
                clickGeneralCount++;

                if (physicalClickCount == 2 && clickGeneralCount < 20) {
                    int x = (int) button.getX();
                    int y = (int) button.getY();
                    String buttonTag = (String) button.getTag();
                    moveButtonRandomlyTopLeft(button, windowManager);
                    physicalClickCount = 0;
                } else if (physicalClickCount < 2 && clickGeneralCount < 20) {
                    int x = (int) button.getX();
                    int y = (int) button.getY();
                    String buttonTag = (String) button.getTag();
                }
                if (clickGeneralCount > 20) {
                    button.setVisibility(View.GONE);
                    replacementButton.setVisibility(View.VISIBLE);
                }
            }
        });

        button.addOnLayoutChangeListener(new View.OnLayoutChangeListener() {
            @Override
            public void onLayoutChange(View v, int left, int top, int right, int bottom, int oldLeft, int oldTop, int oldRight, int oldBottom) {
                int[] location = new int[2];
                button.getLocationOnScreen(location);
                topLeftButtonX = location[0];
                topLeftButtonY = location[1];
                topLeftButtonWidth = right - left;
                topLeftButtonHeight = bottom - top;
                Log.d("ButtonTopLeft", "Layout changed: X: " + topLeftButtonX + ", Y: " + topLeftButtonY + ", Width: " + topLeftButtonWidth + ", Height: " + topLeftButtonHeight);
            }
        });

        button.requestLayout();
        button.invalidate();
    }

    private static void moveButtonRandomlyTopLeft(Button button, WindowManager windowManager) {
        DisplayMetrics displayMetrics = new DisplayMetrics();
        windowManager.getDefaultDisplay().getMetrics(displayMetrics);
        int screenWidth = displayMetrics.widthPixels;
        int screenHeight = displayMetrics.heightPixels;
        int buttonWidth = button.getWidth();
        int buttonHeight = button.getHeight();
        int margin = 0;

        Random random = new Random();

        // Calcula novas coordenadas X e Y para o botão no quadrante esquerdo do topo da tela
        int randomX = (int) (Math.random() * (screenWidth / 2 - buttonWidth - margin) + margin);
        int randomY = (int) (Math.random() * (screenHeight / 2 - buttonHeight - margin) + margin);

        // Define as novas coordenadas para o botão
        button.setX(randomX);
        button.setY(randomY);

        button.requestLayout();
        button.invalidate();
    }

    public static boolean isTouchOnButton(int x, int y) {
        Log.d("MainActivity", "Button coordinates: x = " + topLeftButtonX + ", y = " + topLeftButtonY + ", width = " + topLeftButtonWidth + ", height= " + topLeftButtonHeight);
        Log.d("MainActivity", "Touch coordinates: x = " + x + ", y = " + y);

        // Verifica se as coordenadas do toque estão dentro dos limites do botão
        boolean isOnButton = x >= topLeftButtonX && x <= topLeftButtonX + topLeftButtonWidth &&
                y >= topLeftButtonY && y <= topLeftButtonY + topLeftButtonHeight;

        Log.d("MainActivity", "Is touch on button? " + isOnButton);

        return isOnButton;
    }

    // Método para receber as coordenadas da interface e simular um clique virtual
    public static void onCoordinatesReceived(int x, int y, boolean inicio, int id_robot) {
        Log.d("MainActivity", "Coordenadas recebidas: x = " + x + ", y = " + y);

        if (isTouchOnButton(x, y)) {
            Log.d("MainActivity", "As coordenadas atingiram o botão");
            mainActivity.enviarDadosParaServidor(true, id_robot);
            virtualClickCount++;
            if (virtualClickCount >= 2) {
                moveButtonRandomlyTopLeft(button, windowManager);
                virtualClickCount = 0;
            }
            button.performClick(); // Simula um clique virtual no botão
        } else {
            if (!inicio) {
                mainActivity.enviarDadosParaServidor(false, id_robot);
            }
            Log.d("MainActivity", "As coordenadas não atingiram o botão");
        }

        // Simula um clique virtual na coordenada recebida
        simulateClick(x, y);
    }

    // Método para simular um clique virtual na coordenada fornecida
    private static void simulateClick(int x, int y) {
        MotionEvent downEvent = MotionEvent.obtain(System.currentTimeMillis(), System.currentTimeMillis(), MotionEvent.ACTION_DOWN, x, y, 0);
        MotionEvent upEvent = MotionEvent.obtain(System.currentTimeMillis(), System.currentTimeMillis(), MotionEvent.ACTION_UP, x, y, 0);
        mainActivity.dispatchTouchEvent(downEvent);
        mainActivity.dispatchTouchEvent(upEvent);
        downEvent.recycle();
        upEvent.recycle();
    }
}
