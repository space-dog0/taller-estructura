#include <iostream>
#include "Persona.hpp"
using namespace std;

Persona::Persona(string id, int TiempoEnCamara) {
	this->id = id;
	this->TiempoEnCamara = TiempoEnCamara;
}
int Persona::getTiempoEnCamara() {
	return TiempoEnCamara;
}
string Persona::getId() {
	return id;
}
void Persona::AgregarMinutos(int minutos) {
	this->TiempoEnCamara += minutos;
}
void Persona::setId(string id) {
	this->id = id;
}
Persona :: ~Persona() {
}