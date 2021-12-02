#include <iostream>
#include "Nodo.hpp"
#include "Persona.hpp"
using namespace std;

Nodo::Nodo(Persona p ) {
	this->p = p;
	right = nullptr;
	left = nullptr;
}
Persona Nodo::getPersona() {
	return p;
}
void Nodo::setPersona(Persona p) {
	this->p = p;
}
void Nodo::show() {
	cout << "[" << Persona << "]";
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