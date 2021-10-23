#include <iostream>
#include "LinkedList.hpp"
#include "Nodo.hpp"

LinkedList::LinkedList() { // por ahora solo se hara con una lista simple  si lo amerita mas adelante se cambiara por otra
	first = nullptr;
	size = 0;
}
void LinkedList::insertarPrimer(Persona* persona) {
	Nodo* nn = new Nodo(persona);  //se crea un nuevo nodo
	nn->setNext(first); //apunta al antiguo primer nodo
	first = nn; // ahora first apunta a este nuevo nodo
	size++;
}
Nodo* LinkedList::getFirst() {
	return first;
}
int LinkedList::getSize() {
	return size;
}
