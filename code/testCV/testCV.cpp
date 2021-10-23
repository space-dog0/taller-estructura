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
	Persona* persona = new Persona("id: 2004", 2);
	Persona* persona2 = new Persona("id:2005", 4);
	listaPersonas->insertarPrimer(persona);
	listaPersonas->insertarPrimer(persona2);
	cout << listaPersonas->getFirst()->getPersona()->getId() << endl;
	cout << listaPersonas->getFirst()->getNext()->getPersona()->getId();

	string path = "Resources/2carasrep.png";
	Mat img = imread(path);
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces,1.6,10);
	
	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 1.6);
	}
	
	imshow("Image", img);
	waitKey(0);

}