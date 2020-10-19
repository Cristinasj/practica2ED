// El main del programa. Como el que será el menú, al que se le dan opciones y transforma las imágenes.

#include <string>
#include <iostream>
#include <sstream>

#include "imagen.h"
#include "imagenES.h"

using namespace std;

typedef unsigned char byte;


int main(int nargs, char ** args) {

  stringstream ayuda;
  ayuda << "#-------------------------------#\n";
  ayuda << "Uso correcto: " << args[0] << " OPCION FUENTE SALIDA [PARAMS]" << endl;
  ayuda << "------------" << endl;
  ayuda << "Donde..." << endl;
  ayuda << "\t OPTION puede ser: umbralizar, icono, contraste" << endl;
  ayuda << "\t FUENTE es el fichero que contiene la imagen original" << endl;
  ayuda << "\t SALIDA es el nombre del fichero bajo el que se guarda el resultado" << endl;
  ayuda << "\t PARAMS son los parámetros que toman las funciones de transformación." << endl;
  ayuda << "~~~~~~~~~" << endl;
  ayuda << "OPCIONES: " << endl;
  ayuda << "umbralizar: Hacer blancos los píxeles más claros." << endl << endl;
  ayuda << "icono: Hacer una imagen menor a partir de la dada." << endl;
  ayuda << "\tParámetros: 2. Alto de la imagen y ancho de la imagen." << endl << endl;
  ayuda << "contraste: Aumentar el contraste de la imagen." << endl;
  ayuda << "\tParámetros: 2. Extremo menor y extremo mayor del intervalo de luminosidad deseado." << endl << endl;
  ayuda << "#-------------------------------#\n";


  cout << ayuda.str();

  return 0;
}
