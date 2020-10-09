/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: soma_1.c
**************************************
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#define TAM pow(2, 29)
#define NUM_THREAD 8

int *vetor;

int main(){
	int sums[NUM_THREAD] = {0}, sum = 0, tam = TAM;

	vetor =  (int*) malloc(TAM * sizeof(int) );

	for(int j = 0; j < TAM; j++){
		vetor[j] =  1;
	}

	double  start = omp_get_wtime();
	#pragma omp parallel num_threads(NUM_THREAD)
	{
		int id = omp_get_thread_num();

		for(int i = id; i < tam; i += NUM_THREAD)
		{
			sums[id] += vetor[i];
		}
	}
	for(int i = 0; i < NUM_THREAD; i++){
		sum += sums[i];
	}
	printf("Tempo: %f \n",omp_get_wtime()-start);

	printf("%d\n", sum);
	free(vetor);
	return 0;
}
