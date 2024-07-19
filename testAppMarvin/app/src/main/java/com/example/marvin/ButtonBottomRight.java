package com.example.marvin;

import android.util.DisplayMetrics;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.util.Log;

import java.util.Random;

public class ButtonBottomRight {
    private static int clickCount = 0;
    private static int clickGeneralCount = 0;
    private static int bottomRightButtonX;
    private static int bottomRightButtonY;
    private static int bottomRightButtonWidth;
    private static int bottomRightButtonHeight;


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
                    moveButtonRandomlyBottomRight(button, windowManager);
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
                bottomRightButtonX = location[0];
                bottomRightButtonY = location[1];
                bottomRightButtonWidth = right - left;
                bottomRightButtonHeight = bottom - top;
                Log.d("ButtonBottomRight", "Layout changed: X: " + bottomRightButtonX + ", Y: " + bottomRightButtonY + ", Width: " + bottomRightButtonWidth + ", Height: " + bottomRightButtonHeight);
            }
        });
    }

    private static void moveButtonRandomlyBottomRight(Button button, WindowManager windowManager) {
        // Obtém as dimensões da tela
        DisplayMetrics displayMetrics = new DisplayMetrics();
        windowManager.getDefaultDisplay().getMetrics(displayMetrics);
        int screenWidth = displayMetrics.widthPixels;
        int screenHeight = displayMetrics.heightPixels;

        int buttonWidth = button.getWidth();
        int buttonHeight = button.getHeight();
        int margin = 0;

        Random random = new Random();

        // Calcula novas coordenadas X e Y para o botão no canto inferior direito
        int randomX = (int) (Math.random() * (screenWidth / 2 - buttonWidth - margin) + (screenWidth / 2) + margin);
        int randomY = (int) (Math.random() * (screenHeight / 2 - buttonHeight - margin) + (screenHeight / 2) + margin);

        // Limita a coordenada Y para garantir que o botão permaneça visível na parte inferior da tela
        int maxY = screenHeight - buttonHeight - margin;
        randomY = Math.min(randomY, maxY);

        // Define as novas coordenadas para o botão
        button.setX(randomX);
        button.setY(randomY);

        button.requestLayout();
        button.invalidate();
    }

    public static boolean isTouchOnButton(int x, int y) {
        Log.d("MainActivity", "Button coordinates: x = " + bottomRightButtonX + ", y = " + bottomRightButtonY + ", width = "+ bottomRightButtonWidth + ", height= "+ bottomRightButtonHeight);
        Log.d("MainActivity", "Touch coordinates: x = " + x + ", y = " + y);

        // Verifica se as coordenadas do toque estão dentro dos limites do botão
        boolean isOnButton = x >= bottomRightButtonX && x <= bottomRightButtonX + bottomRightButtonWidth &&
                y >= bottomRightButtonY && y <= bottomRightButtonY + bottomRightButtonHeight;

        Log.d("MainActivity", "Is touch on button? " + isOnButton);

        return isOnButton;
    }
}
