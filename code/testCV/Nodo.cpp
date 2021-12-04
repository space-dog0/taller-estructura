#include <iostream>
#include "Nodo.hpp"
#include "Persona.hpp"

#define RST  "\x1B[0m"
#define KBLU  "\x1B[34m"

#define BOLD(x) "\x1B[1m" x RST
#define FBLU(x) KBLU x RST
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
	cout << BOLD(FBLU("la persona con id "<<id<<""));
	cout << BOLD(FBLU(" se ha visto en "));
	cout << BOLD(FBLU("[ " << vecesVista << " ] "))<< BOLD(FBLU("frames de video\n"));
	
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
Nodo* Nodo::getRight() {
	return right;
}