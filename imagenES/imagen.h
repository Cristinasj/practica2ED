/**
 * @file imagen.h
 * @brief Fichero de cabecera asociado a la biblioteca libimg.a.
 * Implementación del TDA Imagen (imagen digital en niveles de gris).
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <iostream>
#include <cmath>
#include "imagenES.h" // Necesario para leer y escribir imágenes a disco.

typedef unsigned char byte; // Cada píxel es un byte

class Imagen {

private:
  int filas;
  int cols;
  byte *img; // La fila 0 entera, luego la fila 1 entera, luego la 2...
             // Acceder a (f,c) usando índice cols*f + c.


public:

  /**
  * @brief Constructor por defecto
  * @post Crea una imagen sin memoria dinámica reservada (punteros a null_ptr).
  */
  Imagen();

  /**
   * @brief Constructor de copia
   * @pre otra es una imagen válida e inicializada.
   */
  Imagen(const Imagen& otra);

  /**
   * @brief Constructor a partir de un archivo tipo .pgm.
   * @pre El archivo existe y tiene permisos de lectura activados.
   * @param nombre El nombre del archivo.
   * @post Se crea una imagen a partir de los datos en el archivo dado.
   */
  Imagen(const char* nombre);

  /**
   * @brief Crear una imagen en memoria con @p filas filas y @p cols columnas.
   * @param filas Número de filas a reservar para la imagen nueva.
   * @param cols Número de columnas a reservar para la imagen nueva.
   * @pre filas>0 cols>0
   * @post Se crea una imagen nueva con valores basura (no inicializados).
   * @return Nada
   */
  Imagen(int filas, int cols);

  /**
   * @brief Liberar los recursos ocupados por la imagen
   * @post La imagen no puede volver a usarse.
   * @return nada
   */
  ~Imagen();

  /**
   * @brief Operador de asignación
   * @pre @p otra es una imagen válida e inicializada
   * @param otra La imagen cuyos valores se asignan a los de *this
   * @post Los valores guardados en la imagen se quedan idénticos a los de la otra imagen.
   * @return Referencia al resultado de la asignación (*this).
   */
  const Imagen& operator=(const Imagen& otra);

  /**
   * @brief Consultor del número de filas en la imagen.
   * @post No modifica la imagen.
   * @return Número de filas en la imagen (int)
   */
  int num_filas() const { return filas; }

  /**
   * @brief Consultor del número de columnas en la imagen.
   * @post No modifica la imagen.
   * @return Número de columnas en la imagen (int)
   */
  int num_columnas() const { return cols; }

  /**
   * @brief Asignar un valor a una casilla de la matriz.
   * @pre fila>=0 col>=0 fila<filas col<cols valor>=0 valor<=255
   * @param fila La fila del píxel al que asignar el valor
   * @param col La columna del píxel al que asignar el valor
   * @param valor El valor que asignar a la casilla.
   * @post La casilla de la fila @p fila y la columna @p col queda modificada.
   * @return @retval void
   */
  void asigna_pixel(int fila, int col, byte valor);

  /**
   * @brief Consultor del valor de un píxel de la imagen.
   * @pre fila>=0 col>=0 fila<fils col<cols
   * @post No modifica la imagen.
   * @return El valor del píxel en la posición dada.
   */
   byte valor_pixel(int fila, int col) const;

   /**
    * @brief Leer la imagen desde un fichero .pgm
    * @pre El fichero existe y es accesible
    * @param nombre El nombre del Fichero
    * @post Se lee la imagen del fichero y se guarda en *this
    * @return @retval void
    */
   void leer_imagen_desde(const char *nombre);

   /**
    * @brief Escribir la imagen a un fichero con nombre dado
    * @pre El nombre no contiene caracteres no usables en un nombre,
    * el programa tiene permitido crear/sobreescribir ficheros.
    * @param nombre El nombre del fichero al que escribir
    * @post Se escribe la información de la imagen al fichero dado.
    * @return @retval true Si se pudo realizar la escritura.
    */
    bool escribir_imagen_a(const char *nombre);

    /**
     * @brief Umbralizar la imagen eligiendo el umbral de forma automática.
     * @pre La imagen está inicializada y no vacía.
     * @post Todos los valores inferiores al umbral calculado se ponen a 255.
     * @return @retval void
     */
    void umbralizar_automaticamente();

    /**
     * @brief Crea un icono a partir de la imagen original.
     * @pre La imagen inicial es de tamaño > 0 y está inicializada.
     * @param fil_resultado El número de filas de la imagen resultado.
     * @param col_resultado El número de columnas de la imagen resultado.
     * @return Imagen reducida.
     */
    Imagen crear_icono(int fil_resultado, int col_resultado);

    //// CRISTINA!!! AQUÍ HE DEJADO ESTO PARA QUE LO IMPLEMENTES.
    /////  ME HACE FALTA LA CABECERA DE LA FUNCIÓN PARA HACER
    /////     EL MENÚ.
    /////
    /////   BORRA ESTO, PON LA DOCUMENTACIÓN E IMPLEMENTA COMO TE APETEZCA PLIS?
    /////
    /////
    /////   UwU -_- ^-^
    /////
    /////
    Imagen aumenta_contraste(byte min, byte max);




private:
  bool contiene_pixel(int f, int c); // Si la imagen tiene un píxel en (f,c).


};





#endif
