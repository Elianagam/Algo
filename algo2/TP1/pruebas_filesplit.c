#include "filesplit.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* arcgv[]){
	if (argc != 3){
		printf("Numero de argumentos invalidos");
		return -1;
	}
	char* name = arcgv[1];
	size_t n_bytes = (size_t)atoi(arcgv[2]);
	filesplit(name,n_bytes);
	return 0;
}
		
