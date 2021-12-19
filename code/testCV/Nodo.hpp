#pragma once
#include <iostream>
#include "Persona.hpp"
#include <opencv2/core/mat.hpp>
using namespace cv;
class Nodo {
private:
    Persona* persona;
    int id;
    int vecesVista;
public:
    Nodo* l;
    Nodo* r;
    int h;
    Mat img;
    Nodo();
    void setRight(Nodo* n);
    void setLeft(Nodo* n);
    void setId(int id);
    void vista();
    int getId();
    void setAltura(int h);
    int getAltura();
    int getVecesVista();
    void show();
    Mat getImg();
    void setImg(Mat image);
};