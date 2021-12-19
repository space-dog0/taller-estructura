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
const std::string green("\033[1;32m");

using namespace cv;
using namespace std;



template <typename T>
bool contains(vector<T> vec, const T& elem)
{
    bool result = true;
    if (find(vec.begin(), vec.end(), elem) != vec.end())
    {
        result = false;
    }
    return result;
}

int main() {
    system("Color 0B");
    //vector<string> imagesStr;
    ////TODO: Cargar todos los archivos del directorio automáticamente
    //imagesStr.push_back("data/image-007.jpeg");
    //imagesStr.push_back("data/image-008.jpeg");
    //imagesStr.push_back("data/image-024.jpeg");
    //imagesStr.push_back("data/image-025.jpeg");
    //imagesStr.push_back("data/image-026.jpeg");
    //imagesStr.push_back("data/image-046.jpeg");
    //imagesStr.push_back("data/image-047.jpeg");

    //cout << "imagesStr = { ";
    //for (string n : imagesStr) {
    //    cout << n << ", ";
    //}
    //cout << "};" << endl;
    ArbolBinario* Arbol = new ArbolBinario();
    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
    string path = "Resources/video9.mp4";
    VideoCapture cap(path);
    Scalar color(0, 0, 255);
    Scalar color2(0, 255, 9);
    Mat cropColor;

    Mat img;
    CodificadorImg imgcoding;
    Mat imageGray;
    cap.read(img);
    while (!img.empty()) {
        vector<Rect> faces;
        vector<Mat> CodigoCarasGrises;
        cvtColor(img, imageGray, COLOR_BGR2GRAY);
        equalizeHist(imageGray, imageGray);
        faceCascade.detectMultiScale(imageGray, faces, 1.05, 8, 0 | CASCADE_SCALE_IMAGE, Size(50, 50)); // el primer parametro es la imagen que se leera , el segundo parametro es el vector conde se guardan las caras
        imgcoding.setImage(img);
        CodigoCarasGrises = imgcoding.codeGray(faces, true, Size(25, 25));
        for (const auto& cf : CodigoCarasGrises) {
            // Inserto la imagen en el arbol y obtengo el identificador
            Arbol->insert(cf);
            cap.read(img);
            cout << "cargando...\n";
        }
    }
    int opcion;
    cout << "---Bienvenido'---\n1)Iniciar sesion\n2)salir\n" << endl;
    cin >> opcion;
    while (opcion == 1) {
        cout << "1)Administrador\n2)Guardia\n";
        cin >> opcion;
        if (opcion == 1) {
            int opcion;
            cout << "1)Listado de identidades detectadas y tiempo vistas\n";
            cin >> opcion;
            if (opcion == 1) {
                Arbol->show();
            }

        }
        else if (opcion == 2) {
            int opcion;
            cout << "1)Observar entidades\n2)mostrar cinco identidades mas vistas\n";
            cin >> opcion;
            if (opcion == 1) {
                Mat img;
                CodificadorImg imgcoding;
                string path = "Resources/video9.mp4";
                VideoCapture cap(path);
                Mat imageGray;
                Scalar color(0, 0, 255);
                cap.read(img);
                while (!img.empty()) {
                    vector<Rect> faces;
                    cvtColor(img, imageGray, COLOR_BGR2GRAY);
                    equalizeHist(imageGray, imageGray);
                    faceCascade.detectMultiScale(imageGray, faces, 1.05, 8, 0 | CASCADE_SCALE_IMAGE, Size(50, 50)); // el primer parametro es la imagen que se leera , el segundo parametro es el vector conde se guardan las caras
                    for (const auto& fm : faces) {
                        rectangle(img, fm, color, 4);
                    }
                    imshow("Detected Face", img);
                    waitKey(2);
                    cap.read(img);
                }
                while (true) {
                    int pressKey = waitKey(100);
                    if (pressKey == 27 || pressKey == 113) break;
                }
            }
            else if (opcion == 2) { //mostrar identidades mas vistas
                vector<Nodo*> lista;
                lista = Arbol->recorrer();
                vector<int> listaMayores(5);
                vector<int> idMayores(5);
                //cout << lista[0]->getId();
                int contador = -1;
                int id = -1;
                for (int j = 0; j < 5; j++)
                {
                    for (int i = 0; i < lista.size(); i++) {

                        if (lista[i]->getVecesVista() > listaMayores[j] && contains(idMayores, lista[i]->getId()))
                        {
                            listaMayores[j] = lista[i]->getVecesVista();
                            idMayores[j] = lista[i]->getId();
                        }
                    }

                }
                for (int i = 0; i < 5; i++) {
                    cout <<green<<"la id "<< idMayores[i] << endl;
                    cout << " se ha visto " << listaMayores[i] << " veces" << endl;

                }
            }
        }
        cout << "---Bienvenido'---\n1)Iniciar sesion\n2)salir\n" << endl;
        cin >> opcion;
    } //true admin , false guardia
 
    destroyAllWindows();
}



