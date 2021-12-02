#pragma once
#include <iostream>
#include "Persona.hpp"
class Nodo {
private:
    Persona p;
    Nodo* left;
    Nodo* right;
public:
    Nodo(int dato);
    Persona getPersona();
    void setPersona(Persona p);
    void setRight(Nodo* n);
    void setLeft(Nodo* n);
    Nodo* getRight();
    Nodo* getLeft();
    void show();
};