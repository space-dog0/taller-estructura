#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include "Persona.hpp"
#include "Nodo.hpp"
#include "LinkedList.hpp"

using namespace cv;
using namespace std;


void main() {
	LinkedList* listaPersonas = new LinkedList();
	string path = "Resources/video6.mp4";
	VideoCapture cap(path);
	Mat img;
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	int id = 0;
	while (1) {
		cap.read(img);
		if (img.empty())  // si el frame esta vacio se rompe el bucle.
			break;
		vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 9);
		for (int i = 0; i < faces.size(); i++)
		{
			int x, y, w, h;
			x = faces[i].x;
			y = faces[i].y;
			w = faces[i].width;
			h = faces[i].height;
			Persona* persona = new Persona(x, y, w, h, id);
			listaPersonas->insertarPrimer(persona);
			Point tl(x, y); //esquina superior izquierda
			Point br((x + h), (y + w)); // esquina inferior derecha
			rectangle(img, tl, br, Scalar(0, 0, 255), 1.5);
			id++;
		}
		imshow("Video", img);
		waitKey(2);
	}
}