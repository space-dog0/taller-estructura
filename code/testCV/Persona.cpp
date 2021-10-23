#include <iostream>
#include "Persona.hpp"
using namespace std;

Persona::Persona(int x, int y, int w, int h, int id) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->id = id;
	TiempoEnCamara = 0;
}
int Persona::getTiempoEnCamara() {
	return TiempoEnCamara;
}
int Persona::getId() {
	return id;
}
void Persona::AgregarMinutos(int minutos) {
	this->TiempoEnCamara += minutos;
}
void Persona::setId(int id) {
	this->id = id;
}
Persona :: ~Persona() {
}