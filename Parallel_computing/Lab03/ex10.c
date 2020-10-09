/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex10.c
**************************************
*/

#include <stdio.h>
#include <string.h>

const int t_i = 3;
const int t_j = 2;

void mult(float mat[t_i][t_j],int param,float mult,int status){

  switch (status){
    case 1: // se 1 linhas
      for (int i = 0; i < t_i; i++){
        for (int j = 0; j < t_j; j++){
          if (i == param){ // param = numero da linha +1
            mat[i][j] = (mat[i][j] * mult);
          }
          printf("[%f] ",mat[i][j]);
        }
        printf("\n");
      }
      break;
    case 2: // se 2 colunas
      for (int i = 0; i < t_i; i++){
        for (int j = 0; j < t_j; j++){
          if (j == param){ // param = numero da coluna +1
            mat[i][j] = (mat[i][j] * mult);
          }
          printf("[%f] ",mat[i][j]);
        }
        printf("\n");
      }
      break;
  }
}


int main() {

  float matriz[3][2] = {{-2,3},{-5,-15},{4,7}};

  mult(matriz,1,2,1);

  return 0;
}
