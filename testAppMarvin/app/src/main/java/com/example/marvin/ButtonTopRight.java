package com.example.marvin;

import android.util.DisplayMetrics;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.util.Log;

import java.util.Random;

public class ButtonTopRight {
    private static int clickCount = 0;
    private static int clickGeneralCount = 0;
    private static int topRightButtonX;
    private static int topRightButtonY;
    private static int topRightButtonWidth;
    private static int topRightButtonHeight;

    public static void setupRandomMoveOnClick(final Button button, final WindowManager windowManager, final Button replacementButton, MainActivity mainActivity) {
        button.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {

                clickCount++;
                clickGeneralCount++;

                if (clickCount == 2 && clickGeneralCount < 20 ) {
                    // Obter as coordenadas após o movimento do botão
                    int x = (int) button.getX();
                    int y = (int) button.getY();
                    String buttonTag = (String) button.getTag();

                    // Enviar dados para o servidor
                    mainActivity.sendDataToServer("click", x, y, buttonTag);

                    // movimenta o botão
                    moveButtonRandomlyTopRight(button, windowManager);
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
                topRightButtonX = location[0];
                topRightButtonY = location[1];
                topRightButtonWidth = right - left;
                topRightButtonHeight = bottom - top;
                Log.d("ButtonTopRight", "Layout changed: X: " + topRightButtonX + ", Y: " + topRightButtonY + ", Width: " + topRightButtonWidth + ", Height: " + topRightButtonHeight);
            }
        });

        button.requestLayout();
        button.invalidate();
    }

    private static void moveButtonRandomlyTopRight(Button button, WindowManager windowManager) {
        // Obtém as dimensões da tela
        DisplayMetrics displayMetrics = new DisplayMetrics();
        windowManager.getDefaultDisplay().getMetrics(displayMetrics);
        int screenWidth = displayMetrics.widthPixels;
        int screenHeight = displayMetrics.heightPixels;

        int buttonWidth = button.getWidth();
        int buttonHeight = button.getHeight();
        int margin = 0;

        Random random = new Random();

        // Calcula novas coordenadas X e Y para o botão no quadrante direito do topo
        int randomX = (int) (Math.random() * (screenWidth / 2 - buttonWidth - margin) + screenWidth / 2);
        int randomY = (int) (Math.random() * (screenHeight / 2 - buttonHeight - margin) + margin);

        // Define as novas coordenadas para o botão
        button.setX(randomX);
        button.setY(randomY);

        button.requestLayout();
        button.invalidate();
    }

    public static boolean isTouchOnButton(int x, int y) {
        Log.d("MainActivity", "Button coordinates: x = " + topRightButtonX + ", y = " + topRightButtonY + ", width = "+ topRightButtonWidth + ", height= "+ topRightButtonHeight);
        Log.d("MainActivity", "Touch coordinates: x = " + x + ", y = " + y);

        // Verifica se as coordenadas do toque estão dentro dos limites do botão
        boolean isOnButton = x >= topRightButtonX && x <= topRightButtonX + topRightButtonWidth &&
                y >= topRightButtonY && y <= topRightButtonY + topRightButtonHeight;

        Log.d("MainActivity", "Is touch on button? " + isOnButton);

        return isOnButton;
    }
}
