#pragma once
#include <iostream>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
using namespace cv;
using namespace std;

class Persona {
private:
    Mat img;
public:
    Persona(Mat image);
    Mat getImg();
    void setImg(Mat image);
    ~Persona(void);
};