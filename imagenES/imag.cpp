// El main del programa. Como el que será el menú, al que se le dan opciones y transforma las imágenes.
#include "imagen.h"
#include "imagenES.h"
using namespace std;

typedef unsigned char byte;


int main(int nargs, char ** args) {

  // Prueba: A ver si puede leer y escribir una imagen y dejarla intacta?
  Imagen im("vacas.pgm");
  im.escribir_imagen_a("vacas_copia.pgm");

  return 0;
}
