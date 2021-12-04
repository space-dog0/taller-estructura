#pragma once
#include <iostream>
#include "Persona.hpp"
#include <opencv2/core/mat.hpp>
using namespace cv;
class Nodo {
private:
    Persona* persona;
    Nodo* left;
    Nodo* right;
public:
    Nodo(Persona* persona);
    void setPersona(Persona* persona);
    Persona* getPersona();
    void setRight(Nodo* n);
    void setLeft(Nodo* n);
    Nodo* getRight();
    Nodo* getLeft();
    void show();
};