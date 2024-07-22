package com.example.marvin;

public class CoordinateConverter {
    private double screenWidthInMeters;
    private double screenHeightInMeters;
    private int screenWidthInPixels;
    private int screenHeightInPixels;

    public CoordinateConverter(double screenWidthInMeters, double screenHeightInMeters, int screenWidthInPixels, int screenHeightInPixels) {
        this.screenWidthInMeters = screenWidthInMeters;
        this.screenHeightInMeters = screenHeightInMeters;
        this.screenWidthInPixels = screenWidthInPixels;
        this.screenHeightInPixels = screenHeightInPixels;
    }

    public int[] convertMetersToPixels(double xInMeters, double yInMeters) {
        double pixelsPerMeterX = screenWidthInPixels / screenWidthInMeters;
        double pixelsPerMeterY = screenHeightInPixels / screenHeightInMeters;

        int pixelX = (int) (xInMeters * pixelsPerMeterX);
        int pixelY = (int) (yInMeters * pixelsPerMeterY);

        // Assegure que pixelY é calculado de forma que o eixo y seja invertido se necessário
        pixelY = screenHeightInPixels - pixelY;

        return new int[] { pixelX, pixelY };
    }
}

