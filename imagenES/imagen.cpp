#include "imagen.h"
using namespace std;

typedef unsigned char byte;


Imagen::Imagen(): filas(0), cols(0), img(0) { }

Imagen::Imagen(const Imagen& otra): filas(otra.filas), cols(otra.cols) {
  if (otra.img == nullptr) {
    img = nullptr;
  }
  else {
    img = new byte[filas*cols];
    for (int i=0; i<filas*cols-1; i++)
      img[i] = otra.img[i];
  }
}


Imagen::Imagen(int filas, int cols) {
  this->filas = filas;
  this->cols = cols;
  int tam = filas*cols;
  if (tam == 0) {
    img = nullptr;
  }
  else {
    img = new byte[tam];
  }
}


Imagen::~Imagen() {
  if (img != nullptr) {
    delete [] img;
  }
}



const Imagen& Imagen::operator=(const Imagen& otra) {
  Imagen copia(otra);
  byte* aux = this->img;
  this->img = copia.img;
  copia.img = aux;
  return *this;
}




void Imagen::asigna_pixel(int fila, int col, byte valor) {
  if (fila>=0 && fila<filas && col>=0 && col<cols && valor>=0 && valor<=255) {
    img[fila*cols + col] = valor;
  }
}



byte Imagen::valor_pixel(int fila, int col) const {
  return img[fila*filas + col];
}


bool Imagen::contiene_pixel(int f, int c) {
  return (f>=0 && c>=0 && f<filas && c<cols);
}





// Funciones privadas para reservar espacio, liberar, copiar...
