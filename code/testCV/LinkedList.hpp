#pragma once
#include <iostream>
#include "Nodo.hpp"

class LinkedList {
private:
    Nodo* first;
    int size;
public:
    LinkedList();
    void insertarPrimer(Persona* persona);
    Nodo* getFirst();
    int getSize();

};
