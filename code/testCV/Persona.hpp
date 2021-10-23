#pragma once
#include <iostream>

using namespace std;

class Persona {
private:
    int x;
    int y;
    int w;
    int h;
    int id;
    int TiempoEnCamara;

public:
    Persona(int x, int y,int w , int h, int id);
    int getId();
    int getTiempoEnCamara();
    void setId(int id);
    void AgregarMinutos(int minutos);
    ~Persona(void);
};