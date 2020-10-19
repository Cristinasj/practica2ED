// El main del programa. Como el que será el menú, al que se le dan opciones y transforma las imágenes.
#include "imagen.h"
#include "imagenES.h"
using namespace std;

typedef unsigned char byte;


int main(int nargs, char ** args) {

  Imagen im("vacas.pgm");
  im.umbralizar_automaticamente();
  im.escribir_imagen_a("vacas_umbralizadas.pgm");

  return 0;
}
