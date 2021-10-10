![UCN](60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Nicolas Bravo (Encargado de bitacora)
* Carlos Tapia (Coordinador)

## Resumen 

> Para este taller se realizara de software de vigilancia que funcionara a traves de vision artificial, en el cual reconocerá rostros de personas por medio de una camara de video o un video ya grabado, en el cual etiquetará con un codigo unico a cada persona.
> El software tendrá varios apartados para facilitar la vigilancia, en el transcurso de la sesion se podra ver las personas que más tiempo pasan en camara y los rostros estarán destacados por un rectangulo de color. Al terminar la sesion o el dia, el sistema tendra en memoria las personas que mas tiempo estuvieron en camara.
> Tambien arrojará una lista con las entidades y se podrá observar en que intervalo de tiempo esta aparece en el video.

## 1. Introducción

En el presente proyecto se propone implementar un sistema de vigilancia basado en el reconocimiento de caras. El proyecto busca calcular el tiempo que una persona aparece en la cámara, incluso si esta se pierde en la detección o no se encuentra en el cuadro por un tiempo determinado.
Para lograr esto se utilizará Visual Studio Community como IDE y las librerías de OpenCV.

El presente trabajo está dividido en 3 capítulos. El primer capítulo es la descripción del problema, los objetivos de este proyecto y su solución. En el segundo capítulo se hablará sobre cómo se desarrollará, como se implementará y que se utilizará en este proyecto. Y en el tercer capítulo se comentará sobre los resultados obtenidos del proyecto y se dará una conclusión.

### 1.1 Descripción del problema

Dado el laboratorio describir como se entiende el problema bajo sus propias palabras.

### 1.2 Objetivos 

**Objetivo General**

Implementar un sistema de detección de rostros que liste por persona la cantidad de tiempo que aparecieron dentro de un video.

**Objetivos específicos**

1.  Identificar rostros de personas que aparezcan en el video.
2.  Asignar una ID a cada persona identificada.
3.  Descacar rostros reconocidos por la libreria mediante un cuadrado de color.
4.  Determinar cuanto tiempo aparece una persona determinada en el video.

### 1.3 Solución propuesta

Para este proyecto se utilziaran las librerias de OpenCv y el IDE Visual Studio Comunnity. 

## 2. Materiales y métodos

Explicar brevemente como se espera desarrollar el trabajo de implementación.

### 2.1 Instalación

Describir brevemente las librerías utilizadas para la instalación y programas utilizados para la ejecución del código. (Agregar una sección de anexo para describir como fueron instaladas las librerías de OpenCV y la IDE utilzada para el trabajo)

### 2.2 Diseño 



### 2.3 Implementación



Por ejemplo, 

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
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018
