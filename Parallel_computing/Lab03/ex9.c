/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex9.c
**************************************
*/

#include <stdio.h>
#include <string.h>

const int t_i = 3;
const int t_j = 2;

void modulo(float mat[t_i][t_j]){

  for (int i = 0; i < t_i; i++){
    for (int j = 0; j < t_j; j++){
      if (mat[i][j] < 0){
        mat[i][j] = (mat[i][j] * -1);
      }
      printf("[%f] ",mat[i][j]);
    }
    printf("\n");
  }

}

int main() {

  float matriz[3][2] = {{-2,3},{-5,-15},{4,7}};

  modulo(matriz);

  return 0;
}
