#include <iostream>
#include "LinkedList.hpp"
#include "Nodo.hpp"

LinkedList::LinkedList() {
	first = nullptr;
}
void LinkedList::insertarPrimer(Persona* persona) {
	Nodo* nn = new Nodo(persona);  //se crea un nuevo nodo
	nn->setNext(first); //apunta al antiguo primer nodo
	first = nn; // ahora first apunta a este nuevo nodo
}
Nodo* LinkedList::getFirst() {
	return first;
}
