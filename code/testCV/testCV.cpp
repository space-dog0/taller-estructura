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
	//cout << listaPersonas->getFirst()->getPersona()->getId() << endl;
	//cout << listaPersonas->getFirst()->getNext()->getPersona()->getId();
	string path = "Resources/2carasrep.png";
	Mat img = imread(path);
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces,1.1,2);
	int contador = 0;
	for (int i = 0; i < faces.size(); i++)
	{
		int x, y, w, h;
		x = faces[i].x;
		y = faces[i].y;
		w = faces[i].width;
		h = faces[i].height;
		Persona* persona = new Persona(x,y,w,h,contador);
		listaPersonas->insertarPrimer(persona);
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 1.5);
		contador++;
	}
	imshow("Image", img);
	waitKey(0);

}