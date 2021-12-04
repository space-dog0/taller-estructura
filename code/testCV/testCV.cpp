#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <sstream>
#include "Persona.hpp"
#include "Nodo.hpp"
#include "Arbol.hpp"
#include "CodificadorImg.hpp"
#include <string>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"


using namespace cv;
using namespace std;


int main() {
    vector<string> imagesStr;
    //TODO: Cargar todos los archivos del directorio automáticamente
    imagesStr.push_back("data/image-007.jpeg");
    imagesStr.push_back("data/image-008.jpeg");
    imagesStr.push_back("data/image-024.jpeg");
    imagesStr.push_back("data/image-025.jpeg");
    imagesStr.push_back("data/image-026.jpeg");
    imagesStr.push_back("data/image-046.jpeg");
    imagesStr.push_back("data/image-047.jpeg");

    cout << "imagesStr = { ";
    for (string n : imagesStr) {
        cout << n << ", ";
    }
    cout << "};" << endl;

	ArbolBinario* Arbol = new ArbolBinario();
	Mat img;
    CascadeClassifier faceCascade;
    CodificadorImg imgcoding;
    Mat imageGray;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");


    Scalar color(0, 0, 255);
    Scalar color2(0, 255, 9);
    Mat cropColor;
   


    for (string image : imagesStr) {

        vector<Rect> faces;
        vector<Mat> CodigoCarasGrises;
        img = imread(image, IMREAD_COLOR);
        cvtColor(img, imageGray, COLOR_BGR2GRAY);
        equalizeHist(imageGray, imageGray);
        faceCascade.detectMultiScale(imageGray, faces, 1.05, 8, 0 | CASCADE_SCALE_IMAGE, Size(50, 50)); // el primer parametro es la imagen que se leera , el segundo parametro es el vector conde se guardan las caras
        imgcoding.setImage(img);
        CodigoCarasGrises = imgcoding.codeGray(faces, true, Size(25, 25));

        Mat colorImage;
        Mat newSize;

        int widthImageInGrayColor = 40;
        int posX = 10;
        for (const auto& cf : CodigoCarasGrises) {
            // Inserto la imagen en el arbol y obtengo el identificador
            Persona* persona = new Persona(cf);
            Arbol->Insertar(persona);
            // Muestro la imagen codificada en la imagen original
            cvtColor(cf, colorImage, COLOR_GRAY2BGR);
            resize(colorImage, newSize, Size(widthImageInGrayColor, widthImageInGrayColor), INTER_LINEAR);
            newSize.copyTo(img(cv::Rect(posX, 10, newSize.cols, newSize.rows)));
            posX += widthImageInGrayColor + 10;
        }
        for (const auto& fm : faces) {
            rectangle(img, fm, color, 4);
        }
        imshow("Detected Face", img);
        waitKey(0);
    }
    // Esperar hasta presionar la tecla ESC
    while (true) {
        int pressKey = waitKey(100);
        if (pressKey == 27 || pressKey == 113) break;
    }

    destroyAllWindows();

}


