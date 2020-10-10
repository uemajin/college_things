/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: mulMatriz_omp.c
**************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <omp.h>
#define NUM_THREAD 2
#define TAM_MATRIX 1000

int main(){
  int ** matA, ** matB, ** matC;
  int sum;
  int c = 0; // Contador para preencher as matrizes
  int i,j,k;
  sum = 0;

  /* Alocacao das matrizes */

  matA = (int **)malloc(TAM_MATRIX * sizeof(int *));
  matB = (int **)malloc(TAM_MATRIX * sizeof(int *));
  matC = (int **)malloc(TAM_MATRIX * sizeof(int *));
  for (i=0;i < TAM_MATRIX;i++){
    matA[i] = (int *)malloc(TAM_MATRIX * sizeof(int));
    matB[i] = (int *)malloc(TAM_MATRIX * sizeof(int));
    matC[i] = (int *)malloc(TAM_MATRIX * sizeof(int));
  }

  /* Preenchimento das matrizes com valores lineares */
  /* Matriz B = 0,1,2,3,4.... */
  /* Matriz c = Matriz B * 2 */

  for (i=0; i<TAM_MATRIX; i++){
    for (j=0; j<TAM_MATRIX; j++){
      matB[i][j] = c;
      matC[i][j] = c*2;
      ++c;
    }
  }

  /* Multiplicacao das matrizes */
  /* Matriz A = Matriz B * Matriz C */

  double start = omp_get_wtime();

  #pragma omp parallel for num_threads(NUM_THREAD) private(i, j, k) shared(matA, matB, matC) reduction (*:sum)
  for (i=0; i<TAM_MATRIX; i++){
    //printf("i = %d \n", i);
    for (k=0; k<TAM_MATRIX; k++){
      //printf("k = %d \n", k);
      for (j=0; j<TAM_MATRIX; j++){
      sum += matB[i][k] * matC[k][j];
      }
      matA[i][j] = sum;
    }
  }

  printf("Tempo: %f\n", omp_get_wtime()-start);

}
