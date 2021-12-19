#include <iostream>
#include "Arbol.hpp"
#include "opencv2/core.hpp"
#include <stack>
using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
    ids = 1;
}
double ArbolBinario::distanciaEuclideana(Mat img1, Mat img2) {
    return norm(img1, img2, NORM_L2);
}

//void ArbolBinario::Insertar(Persona* p) { //llega la persona con la imagen en grises
//    if (raiz == nullptr) {
//        Nodo* nn = new Nodo(p);
//        nn->vista();
//        nn->setId(ids);
//        ids++;
//        raiz = nn; // se asigna a raiz el nuevo nodo
//
//    }
//    else {
//        Nodo* nodoAux = raiz;
//        bool b = true;
//        while (b) {
//            double DistanciaE = distanciaEuclideana(nodoAux->getPersona()->getImg(), p->getImg());
//
//            if (diferente <= DistanciaE) {
//                if (nodoAux->r == nullptr) { // si esta vacio se agrega
//                    Nodo* nn = new Nodo(p);
//                    nn->setId(ids);
//                    ids++;
//                    nn->vista();
//                    nodoAux->setRight(nn);
//                    if (!isBalanced(nodoAux)) { //ver si rota
//                        cout << "hola putos";
//                        double d =distanciaEuclideana(nodoAux->getPersona()->getImg(), nodoAux->r->getPersona()->getImg());
//                        nodoAux = (d >= diferente) ? singleLeftRotate(nodoAux) : doubleLeftRotate(nodoAux);
//                    }
//                    b = false;
//                }
//                else {
//                    nodoAux = nodoAux->r; // sino se sigue bajando
//                }
//            }
//            else if (similar < DistanciaE && diferente > DistanciaE) {
//                if (nodoAux->l == nullptr) {
//                    Nodo* nn = new Nodo(p);
//                    nn->setId(ids);
//                    ids++;
//                    nn->vista();
//                    nodoAux->setLeft(nn);
//                    // is balance
//                    if (!isBalanced(nodoAux)) { //ver si rota
//                        cout << "hola putosw2";
//                        double d = distanciaEuclideana(nodoAux->getPersona()->getImg(), nodoAux->r->getPersona()->getImg());
//                        nodoAux = (d < diferente && d > similar) ? singleLeftRotate(nodoAux) : doubleLeftRotate(nodoAux);
//                    }
//
//                    b = false;
//                }
//                else {
//                    nodoAux = nodoAux->l;
//                }
//            }
//            //este else es si la distancia e, es menor a la variable 'similar' (significa que es la misma cara).
//            else {
//                nodoAux->setPersona(p); // se remplaza la persona del nodo.
//                nodoAux->vista(); // +1 veces  vista 
//                b = false; //al remplazar la persona se corta el bucle
//           
//            }
//            updateHeight(nodoAux);
//        }
//
//
//    }
//}
Nodo* ArbolBinario::Buscar(Persona* p ) {
    return nullptr;
}

void ArbolBinario::show(Nodo* node) {
    if (node != NULL) {
        node->show();
        show(node->l);
        show(node->r);
    }
}
vector<Nodo*> ArbolBinario::recorrer() {
    vector<Nodo*> lista;
    if (raiz == nullptr) {
        return lista;
    }
    Nodo* nodoAux = raiz;
    stack <Nodo*> p ;
    p.push(nodoAux);
    while (!p.empty()) {
        nodoAux = p.top();
        p.pop();
        lista.push_back(nodoAux);
        if (nodoAux->r != nullptr) {
            p.push(nodoAux->r);
        }
        if (nodoAux->l != nullptr) {
            p.push(nodoAux->l);
        }

    }
    return lista;

}

void ArbolBinario::show() {
    show(raiz);
}

Nodo* ArbolBinario::singleLeftRotate(Nodo* t) {
    Nodo* oldR = t->r;
    t->r = oldR->l;
    oldR->l = t;

    updateHeight(t);
    updateHeight(oldR);

    return oldR;
}

Nodo* ArbolBinario::singleRightRotate(Nodo* t) {
    Nodo* oldL = t->l;
    t->l = oldL->r;
    oldL->r = t;

    updateHeight(t);
    updateHeight(oldL);

    return oldL;
}

Nodo* ArbolBinario::doubleLeftRotate(Nodo* n) {
    n->r = singleRightRotate(n->r);
    return singleLeftRotate(n);
}

Nodo* ArbolBinario::doubleRightRotate(Nodo* n) {
    n->l = singleLeftRotate(n->l);
    return singleRightRotate(n);
}
void ArbolBinario::updateHeight(Nodo* n) {
    if (n != nullptr) n->h = 1 + max(height(n->l), height(n->r));
}
int ArbolBinario::height(Nodo* n) {
    return n == nullptr ? 0 : n->h;
}

int ArbolBinario::getBalance(Nodo * n) {
    return n == nullptr ? 0 : height(n->l) - height(n->r);
}

bool ArbolBinario::isBalanced(Nodo* n) {
    return abs(getBalance(n)) <= 1;
}
Nodo* ArbolBinario::insert(Nodo* nodo, Mat image) {
    // Tolerancia para considerar una imagen igual
    //Si el árbol no tiene hijos
    if (nodo == nullptr) {
        nodo = new Nodo();
        nodo->vista();
        nodo->setId(ids);
        nodo->img = image;
        nodo->l = nullptr;
        nodo->r = nullptr;
        ids++;
        return nodo;
    }
    else if (similar < distanciaEuclideana(nodo->img, image) && diferente > distanciaEuclideana(nodo->img, image)) {
        nodo->l = insert(nodo->l, image);
        if (!isBalanced(nodo)) { //ver si se rota
            double d = distanciaEuclideana(nodo->l->img, image);
            nodo = (d < similar && d < diferente) ? singleRightRotate(nodo) : doubleRightRotate(nodo);
        }

    }
    else if (diferente <= distanciaEuclideana(nodo->img, image)) {
        nodo->r = insert(nodo->r, image);

        if (!isBalanced(nodo)) { //ver si rota
            double d = distanciaEuclideana( nodo->r->img,image);
            nodo = (d > diferente) ? singleLeftRotate(nodo) : doubleLeftRotate(nodo);
        }
    }
    else { //La cara es igual (menor a la distancia exigida para similar)
        nodo->img = image; //Cambio la imagen por la nueva
        nodo->vista(); //+1 veces vista la imagen

    }
    updateHeight(nodo);
    return nodo;
}
void ArbolBinario::insert(Mat image) {
    raiz = insert(raiz, image);
}