package com.example.marvin;

import java.util.Random;

public class CoordinateConverter {
    private int screenWidth;
    private int screenHeight;
    private double x;
    private double y;
    private double z;
    private double fov;

    public CoordinateConverter(double x, double y, double z, int screenWidth, int screenHeight, double fov) {
        this.screenWidth = screenWidth;
        this.screenHeight = screenHeight;
        this.x = x;
        this.y = y;
        this.z = z;
        this.fov = fov;
    }

    public CoordinateConverter(double x, double y, double z) {
        this(x, y, z, 1080, 2220, 90);
    }

    public double[] generateRandomCoordinates(double xMin, double xMax, double yMin, double yMax, double zMin, double zMax) {
        Random random = new Random();
        double x = xMin + (xMax - xMin) * random.nextDouble();
        double y = yMin + (yMax - yMin) * random.nextDouble();
        double z = zMin + (zMax - zMin) * random.nextDouble();
        return new double[]{x, y, z};
    }

    public int[] convertToPixelCoordinates() {
        // Distância do plano de projeção
        double d = screenWidth / (2 * Math.tan(Math.toRadians(fov) / 2));

        // Projeção em perspectiva
        double u = (x / z) * d;
        double v = (y / z) * d;

        // Converter para coordenadas de pixels
        int pixelX = (int) (screenWidth / 2 + u);
        int pixelY = (int) (screenHeight / 2 - v);

        return new int[]{pixelX, pixelY};
    }

    public static void main(String[] args) {
        CoordinateConverter converter = new CoordinateConverter(1.0, 2.0, 3.0);

        // Exemplo de uso
        double[] randomCoords = converter.generateRandomCoordinates(-10, 10, -10, 10, 1, 100);
        System.out.println("Random Coordinates: x=" + randomCoords[0] + ", y=" + randomCoords[1] + ", z=" + randomCoords[2]);

        int[] pixelCoords = converter.convertToPixelCoordinates();
        System.out.println("Pixel Coordinates: x=" + pixelCoords[0] + ", y=" + pixelCoords[1]);
    }
}
