#pragma once
#include <iostream>
#include "Persona.hpp"
class Nodo {
private:
    Persona* persona;
    Nodo* next;
public:
    Nodo(Persona* persona);
    Persona* getPersona();
    void setNext(Nodo* n);
    Nodo* getNext();
};