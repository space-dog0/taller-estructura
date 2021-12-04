#include <iostream>
#include "Nodo.hpp"
#include "Persona.hpp"
using namespace std;

Nodo::Nodo(Persona* p ) {
	this->persona = p;
	right = nullptr;
	left = nullptr;
}
Persona* Nodo::getPersona() {
	return persona;
}
void Nodo::setPersona(Persona* p) {
	this->persona = p;
}
void Nodo::show() {
	cout << "[" << persona->getId() << "]";
}
void Nodo::setRight(Nodo* n) {
	right = n;
}
void Nodo::setLeft(Nodo* n) {
	left = n;
}
Nodo* Nodo::getLeft() {
	return left;
}
Nodo* Nodo::getRight() {
	return right;
}