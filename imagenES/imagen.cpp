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
  return img[fila*cols + col];
}


bool Imagen::contiene_pixel(int f, int c) {
  return (f>=0 && c>=0 && f<filas && c<cols);
}



void Imagen::leer_imagen_desde(const char *nombre) {
  if (img != nullptr) {
    delete [] img;
  }
  img = LeerImagenPGM(nombre, filas, cols);
}


bool Imagen::escribir_imagen_a(const char *nombre) {
  return EscribirImagenPGM(nombre, img, filas, cols);
}


Imagen::Imagen(const char* nombre): Imagen() {
  this->leer_imagen_desde(nombre);
}



// Declarado para poder usarlo en umbralizar_automaticamente
byte valor_medio(byte* array, int num_elementos);



void Imagen::umbralizar_automaticamente() {
  const byte Max_Diferencia = 5;

  // Inicializar umbral_anterior a un extremo (si coinciden a la primera, es una imagen blanca)
  byte umbral_anterior = 255;

  // Primero determinar el primer umbral.
  byte umbral_actual = valor_medio(img, filas*cols);

  // Lista de píxeles inferiores o iguales al umbral
  byte* menores = new byte[filas*cols];
  int num_menores = 0;

  // Lista de píxeles superiores al umbral
  byte* mayores = new byte[filas*cols];
  int num_mayores = 0;

  // Iterar hasta que se estabilice.
  while(abs(umbral_actual - umbral_anterior) > Max_Diferencia) {
    num_menores = num_mayores = 0;

    // Repartir entre los dos subgrupos
    for (int i=0; i<filas*cols; i++) {
      if (img[i] <= umbral_actual) {
        menores[num_menores] = img[i];
        num_menores++;
      }
      else {
        mayores[num_mayores] = img[i];
        num_mayores++;
      }
    }

    // Calcular las medias y actualizar umbrales.
    umbral_anterior = umbral_actual;
    umbral_actual = (valor_medio(menores, num_menores) + valor_medio(mayores, num_mayores)) / 2;
  }

  delete [] mayores;
  delete [] menores;

  // ----- Ahora que se tiene el umbral (umbral_actual), umbralizar. ----
  for (int i=0; i<filas*cols; i++) {
    img[i] = (img[i]<=umbral_actual) ? img[i] : 255;
  }

}



Imagen Imagen::crear_icono(int fil_resultado, int col_resultado) {
  Imagen resultado(fil_resultado, col_resultado);

  int alto_cuadrante = this->filas / fil_resultado;
  int ancho_cuadrante = this->cols / col_resultado;
  int casillas_por_cuadrante = alto_cuadrante * ancho_cuadrante;

  for (int f_res=0; f_res<fil_resultado; f_res++) {
    for (int c_res=0; c_res<col_resultado; c_res++) {

      // Para el píxel de la imagen resultado, calcular la media del cuadrante asociado.
      long suma = 0;
      for (int f=f_res*alto_cuadrante; f<(f_res+1)*alto_cuadrante; f++) {
        for (int c=c_res*ancho_cuadrante; c<(c_res+1)*ancho_cuadrante; c++) {
          suma += valor_pixel(f, c);
        }
      }

      resultado.asigna_pixel(f_res, c_res, (byte)(suma/casillas_por_cuadrante));

    }
  }

  return resultado;
}
















// Funciones privadas para reservar espacio, liberar, copiar...

// Calcular el valor medio de luminosidad en una lista de píxeles.
byte valor_medio(byte* array, int num_elementos) {
  long int suma = 0;
  for (int i=0; i<num_elementos; i++) {
    suma += array[i];
  }
  return (byte)(suma/(num_elementos==0 ? 1 : num_elementos));
}





// Privados
