#include <iostream>
#include "Nodo.hpp"
#include "Persona.hpp"
using namespace std;

Nodo::Nodo(Persona* p ) {
	this->persona = p;
	vecesVista = 0;
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
	cout << "La persona con id " << id;
	cout << " se a visto" << endl;
	cout << "[ " << vecesVista <<" ]"<<" frames de video"<<endl;
}
void Nodo::setRight(Nodo* n) {
	right = n;
}
void Nodo::vista() {
	vecesVista++;
}
int Nodo::getVecesVista() {
	return vecesVista;
}
void Nodo::setId(int id) {
	this->id = id;
}
int Nodo::getId() {
	return id;
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