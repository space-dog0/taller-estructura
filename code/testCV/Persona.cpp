#include <iostream>
#include "Persona.hpp"
using namespace cv;
using namespace std;

Persona::Persona(Mat image) {
	img = image;
}
Mat Persona::getImg() {
	return img;
}
void Persona::setImg(Mat image) {
	this->img = image;
}


Persona :: ~Persona() {
}