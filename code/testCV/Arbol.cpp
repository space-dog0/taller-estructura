#include <iostream>
#include "Arbol.hpp"
#include "opencv2/core.hpp"
using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}
double ArbolBinario::distanciaEuclideana(Mat img1, Mat img2) {
    return norm(img1, img2, NORM_L2);
}

void ArbolBinario::Insertar(Persona* p) { //llega la persona con la imagen en grises
    if (raiz == nullptr) {
        Nodo* nn = new Nodo(p);
        nn->vista();
        raiz = nn; // se asigna a raiz el nuevo nodo
    }
    else {
        Nodo* nodoAux = raiz;
        bool b = true;
        while (b) {
            if (diferente <= distanciaEuclideana(nodoAux->getPersona()->getImg(), p->getImg())) {
                if (nodoAux->getRight() == nullptr) { // si esta vacio se agrega
                    Nodo* nn = new Nodo(p);
                    nn->vista();
                    nodoAux->setRight(nn);
                    b = false;
                }
                else {
                    nodoAux = nodoAux->getRight(); // sino se sigue bajando
                }
            }
            else if (similar < distanciaEuclideana(nodoAux->getPersona()->getImg(), p->getImg()) && diferente > distanciaEuclideana(nodoAux->getPersona()->getImg(), p->getImg())) {
                if (nodoAux->getLeft() == nullptr) {
                    Nodo* nn = new Nodo(p);
                    nn->vista();
                    nodoAux->setLeft(nn);
                    b = false;
                }
                else {
                    nodoAux = nodoAux->getLeft();
                }
            }
            //este else es si la distancia e, es menor a la variable 'similar' (significa que es la misma cara).
            else {
                nodoAux->setPersona(p); // se remplaza la persona del nodo.
                nodoAux->vista(); // +1 veces  vista 
                b = false; //al remplazar la persona se corta el bucle
            }
        }
    }
}
Nodo* ArbolBinario::Buscar(Persona* p ) {
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
