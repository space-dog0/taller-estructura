#pragma once
#include <iostream>
#include "types.hpp"
using namespace std;

class Persona {
private:
    int x;
    int y;
    int width;
    int height;
    string id;
    int TiempoEnCamara;

public:
    Persona(string id, int TiempoEnCamara);
    string getId();
    int getTiempoEnCamara();
    void setId(string id);
    void AgregarMinutos(int minutos);
    ~Persona(void);
};