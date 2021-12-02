#include "Nodo.hpp"
#include "Persona.hpp"

class ArbolBinario {
private:
    Nodo* raiz;
    void show(Nodo* node);
public:
    ArbolBinario();
    void Insertar(Persona p);
    Nodo* Buscar(Persona p); // por ahora pongo dato
    void show();

};