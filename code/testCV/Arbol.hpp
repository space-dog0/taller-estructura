#include "Nodo.hpp"
#include "Persona.hpp"
#include <opencv2/core/mat.hpp>

class ArbolBinario {
private:
    Nodo* raiz;
    int ids;
    int similar = 1300;
    int diferente = 1700;
    void show(Nodo* node);
public:
    ArbolBinario();
    double distanciaEuclideana(Mat img, Mat img2);
    Nodo* insert(Nodo* nodo, Mat image);
    void insert(Mat image);
    Nodo* Buscar(Persona* p); // por ahora pongo dato
    vector<Nodo*> recorrer();
    void show();
    Nodo* singleLeftRotate(Nodo* t);
    Nodo* singleRightRotate(Nodo* t);
    Nodo* doubleLeftRotate(Nodo* t);
    Nodo* doubleRightRotate(Nodo* t);
    void updateHeight(Nodo* n);
    int height(Nodo* n);
    int getBalance(Nodo* n);
    bool isBalanced(Nodo* n);

};