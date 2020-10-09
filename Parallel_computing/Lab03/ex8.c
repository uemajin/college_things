/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex8.c
**************************************
*/

#include <stdio.h>
#include <string.h>

const int t_i = 3;
const int t_j = 2;

void transposta(float mat[t_i][t_j]){

  float newmat[t_j][t_i];

  for (int i = 0; i < t_i; i++){
    for (int j = 0; j < t_j; j++){
      newmat[j][i] = mat[i][j];
    }
  }

  for (int j = 0; j < t_j; j++){
    for (int i = 0; i < t_i; i++){
      printf("[%f] ",newmat[j][i]);
    }
    printf("\n");
  }
}

int main() {

  float matriz[3][2] = {{2,3},{5,9},{4,7}};

  transposta(matriz);

  return 0;
}
