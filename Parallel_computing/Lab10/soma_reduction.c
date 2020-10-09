/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: soma_3.c
**************************************
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#define TAM pow(2, 29)
#define NUM_THREAD 6

int *vet;

int main(){
	int sum = 0, sum_parcial = 0, tam = TAM;

	vet =  (int*) malloc(TAM * sizeof(int) );

	for(int j = 0; j < TAM; j++){
		vet[j] =  1;
	}
	double start = omp_get_wtime();
	#pragma omp parallel num_threads(NUM_THREAD) reduction(+:sum)
	{
		#pragma omp for
		for(int i = 0; i < tam; i++)
		{
			sum += vet[i];
		}

	}
	printf("Tempo: %f\n", omp_get_wtime()-start);
	printf("%d\n", sum);
	free(vet);
	return 0;
}
