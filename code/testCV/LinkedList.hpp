#pragma once
#include <iostream>
#include "Nodo.hpp"

class LinkedList {
private:
    Nodo* first;
public:
    LinkedList();
    void insertarPrimer(Persona* persona);
    Nodo* getFirst();

};
