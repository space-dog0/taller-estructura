#include <iostream>
#include "Arbol.hpp"
using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}
void ArbolBinario::Insertar(Persona p) {
    if (raiz == nullptr) {
        Nodo* nn = new Nodo(Persona p);
        raiz = nn; // se asigna a raiz el nuevo nodo
        int number = raiz->getPersona();
        cout << number;
    }
    else {
        Nodo* nodoAux = raiz;
        bool b = true;
        while (b) {
            if (dato > nodoAux->getPersona()) {
                if (nodoAux->getRight() == nullptr) { // si esta vacio se agrega
                    Nodo* nn = new Nodo(dato);
                    nodoAux->setRight(nn);
                    b = false;
                }
                else {
                    nodoAux = nodoAux->getRight(); // sino se sigue bajando
                }
            }
            if (dato < nodoAux->getPersona()) {
                if (nodoAux->getLeft() == nullptr) {
                    Nodo* nn = new Nodo(dato);
                    nodoAux->setLeft(nn);
                    b = false;
                    cout << nodoAux->getLeft()->getPersona();
                }
                else {
                    nodoAux = nodoAux->getLeft();
                }
            }
        }
    }
}
Nodo* ArbolBinario::Buscar(int dato) {
    return nullptr;
}

void ArbolBinario::show(Nodo* node) {
    if (node != NULL) {
        node->show();
        show(node->getLeft());
        show(node->getRight());
    }
}
void ArbolBinario::show() {
    show(raiz);
}
