#pragma once
#include <iostream>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
using namespace cv;
using namespace std;

class Persona {
private:
    int id;
    Mat img;
    int vecesVista;
public:
    Persona(Mat image);
    int getId();
    Mat getImg();
    void setImg(Mat image);
    void setId(int id);
    void vista();
    ~Persona(void);
};