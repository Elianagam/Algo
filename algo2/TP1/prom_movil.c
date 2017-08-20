#include <stdio.h>
#include <stdlib.h>


double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
	double* prom = malloc((n+1) * sizeof(double));
	if (!prom) return NULL;
	for (int num = 0; num != n; num++){
		double suma = 0, divisor = 0;
		for (int i = num; i <= k + num; i++){
			if (i < n && arreglo[i]){ 
				suma += arreglo[i];
				divisor++;
			}
		}
		for (int cont = 0, j = num -1; cont != k; cont++, j--){
			if (j >= 0 && arreglo[j] ){
				suma += arreglo[j];
				divisor++;
			}
		}
		double valor_promedio = suma / divisor;
		//printf("suma: %f --div: %f --Valor promedio[%d]: %f\n",suma,divisor,num,valor_promedio);
		prom[num] = valor_promedio;
	}
	return prom;
}

double* promedio_movil_lineal(int* arreglo, size_t n, size_t k){
	double* prom = malloc((n+1) * sizeof(double));
	if (! prom) return NULL;
	
	double suma = 0, suma_aux = 0, div = 0;
	int cont = 0;
	while (cont < k){
		suma = suma + arreglo[cont];
		div++;
		cont++;
	}
	for (int num = 0; num != n ; cont++,num++){
		if (cont < n){
			suma = suma + arreglo[cont];
			div++;
		}
		if (cont > 2*k ){
			size_t pos = cont - 2*k-1;
			suma_aux += arreglo[pos];
			div--;
		}
		double sim = suma- suma_aux;
		prom[num] = sim / div;
		//printf("\nsuma: %f -- valor prom[%d] %f",sim,num,prom[num]);
	}
	return prom;
}
