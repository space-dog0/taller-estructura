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
    void Insertar(Persona* p);
    Nodo* Buscar(Persona* p); // por ahora pongo dato
    void recorrer(vector<Nodo*> lista);
    void recorrer(Nodo* node,vector<Nodo*> lista);
    void show();

};