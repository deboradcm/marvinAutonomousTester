package com.example.marvin;

import android.util.DisplayMetrics;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;

import java.util.Random;

public class ButtonBorder {

    private static int clickCount = 0;
    private static int clickGeneralCount = 0;
    private static int buttonBorderX;
    private static int buttonBorderY;
    private static int buttonBorderWidth;
    private static int buttonBorderHeight;
    private static Button button;
    private static WindowManager windowManager;
    private static MainActivity mainActivity;

    //Configura o comportamento do botão
    public static void setupRandomMoveOnClick(final Button btn, final WindowManager wm, final Button replacementButton, MainActivity mainAct) {
        button = btn;
        windowManager = wm;
        mainActivity = mainAct;

        //Clique físico
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                clickCount++;
                clickGeneralCount++;

                if (clickCount == 2 && clickGeneralCount < 20) {
                    int x = (int) button.getX();
                    int y = (int) button.getY();
                    String buttonTag = (String) button.getTag();
                    moveButtonRandomlyBorder(button, windowManager);
                    clickCount = 0;
                } else if (clickCount < 2 && clickGeneralCount < 20) {
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
                buttonBorderX = location[0];
                buttonBorderY = location[1];
                buttonBorderWidth = right - left;
                buttonBorderHeight = bottom - top;
                Log.d("ButtonBorder", "Layout changed: X: " + buttonBorderX + ", Y: " + buttonBorderY + ", Width: " + buttonBorderWidth + ", Height: " + buttonBorderHeight);
            }
        });

        button.requestLayout();
        button.invalidate();
    }

    private static void moveButtonRandomlyBorder(Button button, WindowManager windowManager) {
        DisplayMetrics displayMetrics = new DisplayMetrics();
        windowManager.getDefaultDisplay().getMetrics(displayMetrics);
        int screenWidth = displayMetrics.widthPixels;
        int screenHeight = displayMetrics.heightPixels;
        int buttonWidth = button.getWidth();
        int buttonHeight = button.getHeight();
        Random random = new Random();

        int edge = random.nextInt(4);
        int randomX = 0;
        int randomY = 280; // Definindo a posição inicial de Y

        switch (edge) {
            case 0: // Borda superior
                randomX = random.nextInt(900);
                randomY = 0;
                button.setX(randomX);
                button.setY(randomY);
                break;
            case 1: // Borda direita
                randomX = 870;
                randomY = random.nextInt(2000);
                button.setX(randomX);
                button.setY(randomY);
                break;
            case 2: // Borda inferior
                randomX = random.nextInt(900);
                randomY = 500;
                button.setX(randomX);
                button.setY(randomY);
                break;
            case 3: // Borda esquerda
                randomX = 0;
                randomY = random.nextInt(2050);
                button.setX(randomX);
                button.setY(randomY);
                break;
        }
        button.requestLayout();
        button.invalidate();
    }

    public static boolean isTouchOnButton(int x, int y) {
        Log.d("MainActivity", "Button coordinates: x = " + buttonBorderX + ", y = " + buttonBorderY + ", width = " + buttonBorderWidth + ", height= " + buttonBorderHeight);
        Log.d("MainActivity", "Touch coordinates: x = " + x + ", y = " + y);

        boolean isOnButton = x >= buttonBorderX && x <= buttonBorderX + buttonBorderWidth &&
                y >= buttonBorderY && y <= buttonBorderY + buttonBorderHeight;

        Log.d("MainActivity", "Is touch on button? " + isOnButton);

        return isOnButton;
    }

    // Método para receber as coordenadas da interface
    public static void onCoordinatesReceived(int x, int y, boolean inicio, int id_robot) {
        Log.d("MainActivity", "Coordenadas recebidas: x = " + x + ", y = " + y);

        if (isTouchOnButton(x, y)) {
            Log.d("MainActivity", "As coordenadas atingiram o botão da borda");
            mainActivity.enviarDadosParaServidor(true, id_robot); // Chama o método da MainActivity
            clickCount++;
            if (clickCount >= 2) {
                moveButtonRandomlyBorder(button, windowManager); // Chama o método correto
                clickCount = 0;
            }
        } else {
            if (!inicio) {
                mainActivity.enviarDadosParaServidor(false, id_robot); // Chama o método da MainActivity
            }
            Log.d("MainActivity", "As coordenadas não atingiram o botão");
        }
    }

}
