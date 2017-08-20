#ifndef FIXCOL_H
#define FIXCOL_H

#include <stddef.h>

/*
 * Recibe como parametros un nombre de archivo en el directorio y
 * un numero de bytes y crea un nuevo archivo con columnas que tengan
 * la misma cantidad de n_bytes.
 */

void fixcol(char* name, size_t n_bytes);

#endif  // FIXCOL_H
