#include <iostream>
#include "Persona.hpp"
using namespace cv;
using namespace std;

Persona::Persona(Mat image) {
	img = image;
}

int Persona::getId() {
	return id;
}
Mat Persona::getImg() {
	return img;
}
void Persona::setImg(Mat image) {
	this->img = image;
}
void Persona::vista() {
	vecesVista++;
}
void Persona::setId(int id) {
	this->id = id;
}

Persona :: ~Persona() {
}