package com.example.marvin;

// Interface para passar as coordenadas recebidas
public interface CoordinatesListener {
    void onCoordinatesReceived(int x, int y, boolean inicio, int id_robot);
}
