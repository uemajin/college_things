/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: soma_critical.c
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
	int sum = 0, tam = TAM;

	vet =  (int*) malloc(TAM * sizeof(int) );

	for(int j = 0; j < tam; j++){
		vet[j] =  1;
	}


	double start = omp_get_wtime();

	#pragma omp parallel num_threads(NUM_THREAD) shared(sum)
	{
		int sum_parcial = 0;
		int id = omp_get_thread_num();
		for(int i = id; i < tam; i += NUM_THREAD)
		{
			sum_parcial += vet[i];
		}
		#pragma omp critical
			sum += sum_parcial;
	}
	printf("Tempo: %f\n", omp_get_wtime()-start);
	printf("%d\n", sum);
	free(vet);
	return 0;
}
