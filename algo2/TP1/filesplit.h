#ifndef FILESPLIT_H
#define FILESPLIT_H

#include <stddef.h>

/*
 * Recibe como parametros un nombre de archivo en el directorio y
 * un numero de bytes y divide el archivo en otros mas pequeños
 * con n_bytes.
 */

void filesplit(char* name,size_t n_bytes);


#endif  // FILESPLIT_H
