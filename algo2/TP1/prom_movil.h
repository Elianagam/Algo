#ifndef PROM_MOVIL_H
#define PROM_MOVIL_H

#include <stddef.h>

/*
 * Devuelve un puntero con un arreglo del calculo del promedio movil,
 * tomando el valor de la posicion actual y sumando los k numeros que
 * se encuentren antes y despues. Para eso recorre el arreglo dos veces.
 */
double* obtener_promedio_movil(int* arreglo, size_t n, size_t k);

/*
 * Devuelve un puntero con un arreglo del calculo del promedio movil,
 * Avanza del valor actual y actualiza la suma restando los valores
 * de posiciones anteriores.
 */
double* promedio_movil_lineal(int* arreglo, size_t n, size_t k);

#endif  // PROM_MOVIL_H
