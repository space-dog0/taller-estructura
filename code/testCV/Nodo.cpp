#include <iostream>
#include "Nodo.hpp"
#include "Persona.hpp"
using namespace std;

Nodo::Nodo(Persona* persona) {
	this->persona = persona;
	next = nullptr;
}
Persona* Nodo::getPersona() {
	return persona;
}
void Nodo::setNext(Nodo* n) {
	next = n;
}
Nodo* Nodo::getNext() {
	return next;
}