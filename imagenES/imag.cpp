// El main del programa. Como el que será el menú, al que se le dan opciones y transforma las imágenes.


#include <string>
#include <iostream>
#include <sstream>

#include "imagen.h"
#include "imagenES.h"

using namespace std;

typedef unsigned char byte;

// borrar esta línea (la necesito para que compile el menú sin haber terminado la parte del contraste)
Imagen Imagen::aumenta_contraste(byte min, byte max) {}


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

  string menu_ayuda = ayuda.str();

  // Tiene que haber al menos 3 argumentos. La opción, el fichero original y donde guardar el resultado.
  if (nargs < 3) {
    cout << menu_ayuda << endl;
    return 1;
  }

  string opcion = args[1];
  string nombre_fuente = args[2];
  string nombre_destino = args[3];

  if (opcion == "umbralizar" && nargs == 4) {
    Imagen im(nombre_fuente.c_str());
    im.umbralizar_automaticamente();
    im.escribir_imagen_a(nombre_destino.c_str());
  }

  else if (opcion == "icono" && nargs == 6) {
    string num_filas = args[4];
    string num_cols = args[5];

    stringstream aux;
    aux << num_filas << " " << num_cols;
    int n_f, n_c; // Número de filas y columnas de la imagen deseada
    aux >> n_f >> n_c; // Es FIFO

    Imagen im(nombre_fuente.c_str());
    Imagen icono = im.crear_icono(n_f, n_c);
    icono.escribir_imagen_a(nombre_destino.c_str());
  }

  else if (opcion == "contraste" && nargs == 6) {
    string min_s = args[4];
    string max_s = args[5];
    stringstream aux;
    aux << min_s << " " << max_s;
    int min, max;
    aux >> min >> max;

    // Hacer la conversión y escribir el resultado al archivo destino.
    Imagen(nombre_fuente.c_str()).aumenta_contraste(min, max).escribir_imagen_a(nombre_destino.c_str());
  }

  else {
    cout << menu_ayuda << endl;
  }




  return 0;
}



















//
