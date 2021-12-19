#include <iostream>
#include "Nodo.hpp"
#include "Persona.hpp"

#define RST  "\x1B[0m"
#define KBLU  "\x1B[34m"

#define BOLD(x) "\x1B[1m" x RST
#define FBLU(x) KBLU x RST
using namespace std;

Nodo::Nodo() {
	vecesVista = 0;
	r = nullptr;
	l = nullptr;
	h = 0;
}


void Nodo::show() {
	cout << BOLD(FBLU("la persona con id "<<id<<""));
	cout << BOLD(FBLU(" se ha visto en "));
	cout << BOLD(FBLU("[ " << vecesVista << " ] "))<< BOLD(FBLU("frames de video\n"));
	
}
void Nodo::setRight(Nodo* n) {
	r = n;
}
void Nodo::setLeft(Nodo* n) {
	l = n;
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
int Nodo::getAltura() {
	return h;
}
void Nodo::setAltura(int h) {
	this->h = h;
}