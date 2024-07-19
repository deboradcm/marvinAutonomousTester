package com.example.marvin;

import android.util.DisplayMetrics;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.util.Log;

import java.util.Random;

public class ButtonWandering {
    private static int clickCount = 0;
    private static int clickGeneralCount = 0;
    private static int wanderingButtonX;
    private static int wanderingButtonY;
    private static int wanderingButtonWidth;
    private static int wanderingButtonHeight;

    public static void setupRandomMoveOnClick(final Button button, final WindowManager windowManager, final Button replacementButton, MainActivity mainActivity) {
        button.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {

                clickCount++;
                clickGeneralCount++;

                if (clickCount == 2 && clickGeneralCount < 20) {
                    // Obter as coordenadas após o movimento do botão
                    int x = (int) button.getX();
                    int y = (int) button.getY();
                    String buttonTag = (String) button.getTag();

                    // Enviar dados para o servidor
                    mainActivity.sendDataToServer("click", x, y, buttonTag);

                    // Movimenta o botão
                    moveButtonRandomly(button, windowManager);
                    clickCount = 0;

                } else if (clickCount < 2 && clickGeneralCount < 20) {
                    // Obter as coordenadas após o movimento do botão
                    int x = (int) button.getX();
                    int y = (int) button.getY();
                    String buttonTag = (String) button.getTag();

                    // Enviar dados para o servidor
                    mainActivity.sendDataToServer("click", x, y, buttonTag);

                } if (clickGeneralCount > 20) {
                    button.setVisibility(View.GONE);
                    replacementButton.setVisibility(View.VISIBLE);
                }
            }
        });

        // Adiciona OnLayoutChangeListener para monitorar mudanças no layout
        button.addOnLayoutChangeListener(new View.OnLayoutChangeListener() {
            @Override
            public void onLayoutChange(View v, int left, int top, int right, int bottom, int oldLeft, int oldTop, int oldRight, int oldBottom) {
                int[] location = new int[2];
                button.getLocationOnScreen(location);
                wanderingButtonX = location[0];
                wanderingButtonY = location[1];
                wanderingButtonWidth = right - left;
                wanderingButtonHeight = bottom - top;
                Log.d("ButtonWandering", "Layout changed: X: " + wanderingButtonX + ", Y: " + wanderingButtonY + ", Width: " + wanderingButtonWidth + ", Height: " + wanderingButtonHeight);
            }
        });

        button.requestLayout();
        button.invalidate();
    }

    private static void moveButtonRandomly(View button, WindowManager windowManager) {
        DisplayMetrics displayMetrics = new DisplayMetrics();
        windowManager.getDefaultDisplay().getMetrics(displayMetrics);
        int screenWidth = displayMetrics.widthPixels;
        int screenHeight = displayMetrics.heightPixels;

        int buttonWidth = button.getWidth();
        int buttonHeight = button.getHeight();

        Random random = new Random();

        // Calcula novas coordenadas X e Y para o botão
        int randomX = random.nextInt(screenWidth - buttonWidth);
        int randomY = random.nextInt(screenHeight - buttonHeight);

        // Define as novas coordenadas para o botão
        button.setX(randomX);
        button.setY(randomY);

        button.requestLayout();
        button.invalidate();
    }

    public static boolean isTouchOnButton(int x, int y) {
        Log.d("MainActivity", "Button coordinates: x = " + wanderingButtonX + ", y = " + wanderingButtonY + ", width = " + wanderingButtonWidth + ", height = " + wanderingButtonHeight);
        Log.d("MainActivity", "Touch coordinates: x = " + x + ", y = " + y);

        // Verifica se as coordenadas do toque estão dentro dos limites do botão
        boolean isOnButton = x >= wanderingButtonX && x <= wanderingButtonX + wanderingButtonWidth &&
                y >= wanderingButtonY && y <= wanderingButtonY + wanderingButtonHeight;

        Log.d("MainActivity", "Is touch on button? " + isOnButton);

        return isOnButton;
    }
}
