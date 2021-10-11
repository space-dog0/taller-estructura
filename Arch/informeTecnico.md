![UCN](60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Nicolas Bravo (Encargado de bitacora)
* Carlos Tapia (Coordinador)

## Resumen 

> Para este taller se realizará de software de vigilancia que funcionará a través de visión artificial, en el cual reconocerá rostros de personas por medio de una cámara de video o un video ya grabado, en el cual etiquetará con un código único a cada persona.
> El software tendrá varios apartados para facilitar la vigilancia, en el transcurso de la sesión se podrá ver las personas que más tiempo pasan en cámara y los rostros estarán destacados por un rectángulo de color. Al terminar la sesión o el día, el sistema tendrá en memoria las personas que más tiempo estuvieron en cámara.
> También arrojará una lista con las entidades y se podrá observar en que intervalo de tiempo esta aparece en el video.

## 1. Introducción

En el presente proyecto se propone implementar un sistema de vigilancia basado en el reconocimiento de caras. El proyecto busca calcular el tiempo que una persona aparece en la cámara, incluso si esta se pierde en la detección o no se encuentra en el cuadro por un tiempo determinado.
Para lograr esto se utilizará Visual Studio Community como IDE y las librerías de OpenCV.

El presente trabajo está dividido en 3 capítulos. El primer capítulo es la descripción del problema, los objetivos de este proyecto y su solución. En el segundo capítulo se hablará sobre cómo se desarrollará, como se implementará y que se utilizará en este proyecto. Y en el tercer capítulo se comentará sobre los resultados obtenidos del proyecto y se dará una conclusión.

### 1.1 Descripción del problema

El problema a resolver es crear un software de vigilancia capaz de reconocer rostros de personas y que, además sepa identificar a la persona que se encuentra en pantalla.

### 1.2 Objetivos 

**Objetivo General**

Implementar un sistema de detección de rostros que liste por persona la cantidad de tiempo que aparecieron dentro de un video.

**Objetivos específicos**

1.  Identificar rostros de personas que aparezcan en el video.
2.  Asignar una ID a cada persona identificada.
3.  Destacar rostros reconocidos por la librería mediante un cuadrado de color.
4.  Determinar cuánto tiempo aparece una persona determinada en el video.

### 1.3 Solución propuesta

Para este proyecto se utilizarán las librerías de OpenCV que ayuda a identificar personas a través de visión artificial y el IDE Visual Studio Comunnity que es necesario para utilizar las librerías.

## 2. Materiales y métodos

### 2.1 Instalación

Para la realización de este proyecto se utilizaran las librerías de OpenCV (ver.4.3.5) y el IDE Visual Studio Comunnity 2019.
Describir brevemente las librerías utilizadas para la instalación y programas utilizados para la ejecución del código. (Agregar una sección de anexo para describir como fueron instaladas las librerías de OpenCV y la IDE utilzada para el trabajo)

### 2.2 Diseño 



### 2.3 Implementación

#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento
La segunda linea carga el path
La tercera es un contenedor de secuencia que encapsula matrices de tamaño dinámico.
La 5 linea hasta la 10 crea los rectangulos para las caras identificadas

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV
para la descarga de las librerías de OpenCv utilizamos la página oficial, y para la instalación utilizamos el video proporcionado por el profesor.
## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. Fernando, S., 2021. Introduction. [online] Opencv-srf.com. Available at: <https://www.opencv-srf.com/p/introduction.html> [Accessed 10 October 2021].
