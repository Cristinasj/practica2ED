/**
 * @file imagen.h
 * @brief Fichero de cabecera asociado a la biblioteca libimg.a.
 * Implementación del TDA Imagen (imagen digital en niveles de gris).
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

typedef unsigned char byte; // Cada píxel es un byte

class Imagen {

private:
  int filas;
  int cols;
  byte **img; // Vector de filas (o de columnas?). Matriz dinámica 2D.

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
  byte valor_pixel(int fila, int col) const; // consultar valor de un píxel. Preconds sobre f,c y postcond que no modifica.





};





#endif
