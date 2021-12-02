#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <sstream>
#include "Persona.hpp"
#include "Nodo.hpp"
#include "LinkedList.hpp"
#include "CodificadorImg.hpp"

using namespace cv;
using namespace std;


void main() {
	LinkedList* listaPersonas = new LinkedList();
	Mat img;
	img = imread("Resources/wil3.jpg", IMREAD_COLOR);
	CascadeClassifier faceCascade;
	CodificadorImg imgcoding;
	int sum = 1;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	int id = 0;
	vector<Rect> faces;
	vector<Mat> CodigoCarasGrises;
	Mat imageGray;
	cvtColor(img, imageGray, COLOR_BGR2GRAY);
	equalizeHist(imageGray, imageGray);
		//if (img.empty())  // si el frame esta vacio se rompe el bucle.
		//	break;
	faceCascade.detectMultiScale(imageGray, faces, 1.05, 4, 0 | CASCADE_SCALE_IMAGE,Size(50,50)); // el primer parametro es la imagen que se leera , el segundo parametro es el vector conde se guardan las caras
	Scalar color(0, 0, 255);
	Scalar color2(0, 255, 9);
	Mat cropColor;
	Mat resizedDown;
	imgcoding.setImage(img);
	CodigoCarasGrises = imgcoding.codeGray(faces, true, Size(20, 20));

	 // las caras codificadas
	//for (const auto& cf : CodigoCarasGrises) {
	//	imshow("Imagen Codificida", cf);
	//	waitKey(0);
	//}


	Mat img1;
	bool encontrado = false;
	for (int i = 0; i < CodigoCarasGrises.size(); i++) {
		img1 = CodigoCarasGrises[i];
		for (const auto& cf : CodigoCarasGrises) {
			double dist = norm(img1, cf, NORM_L2);
			cout << "Comparación imagen 1 con imagen " << sum << ":" << dist << endl;
			if (dist < 1000) { // si la operacion es menor a 1000 , se encontro el rostro
				rectangle(img, faces[sum - 1], color2, 4);
				encontrado = true;
			}
			else {
				rectangle(img, faces[sum - 1], color, 4);

			}
			sum++;
		}
	}


	imshow("imagen", img);
	waitKey(0);	
}