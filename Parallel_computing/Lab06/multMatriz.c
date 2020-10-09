/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: memComp.c
**************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

int main(){
  int ** matA, ** matB, ** matC;
  int i,j,k;
  int c = 0; // Contador para preencher as matrizes
  int n = 1000; // Numero do tamanho das matrizes NxN

  /* Alocacao das matrizes */

  matA = (int **)malloc(n * sizeof(int *));
  matB = (int **)malloc(n * sizeof(int *));
  matC = (int **)malloc(n * sizeof(int *));
  for (i=0;i < n;i++){
    matA[i] = (int *)malloc(n * sizeof(int));
    matB[i] = (int *)malloc(n * sizeof(int));
    matC[i] = (int *)malloc(n * sizeof(int));
  }

  /* Preenchimento das matrizes com valores lineares */
  /* Matriz B = 0,1,2,3,4.... */
  /* Matriz c = Matriz B * 2 */

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      matB[i][j] = c;
      matC[i][j] = c*2;
      ++c;
    }
  }

  /* Multiplicacao das matrizes */
  /* Matriz A = Matriz B * Matriz C */

  for (i=0; i<n; i++){
    for (k=0; k<n; k++){
      for (j=0; j<n; j++){
        matA[i][j] += matB[i][k] * matC[k][j];
      }
    }
  }
}
