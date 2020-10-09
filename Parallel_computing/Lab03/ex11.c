/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex11.c
**************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum_lin(float ** mat,int l1, int l2, int y, int x){

  for (int i = 0; i < y; i++){
    for (int j = 0; j < x; j++){
      if(i == l2){
        mat[i][j] = mat[i][j] + mat[l2][j];
      }
      printf("[%f] ",mat[i][j]);
    }
    printf("\n");
  }

}

int main() {

  //float matriz[3][2] = {{-2,3},{-5,-15},{4,7}};

  int linha,coluna, i, j;
  float ** matriz;

  linha = 5;
  coluna = 3;

  matriz = malloc(linha * sizeof *matriz);

  for (i = 0; i < linha; i++){
    matriz[i] = malloc(coluna * sizeof *matriz[i]);
  }

  for (i = 0; i < linha; i++){
    for (j = 0; j < coluna; j++){
      printf("Digite o valor da matriz: %dx%d  \n",i+1,j+1);
      scanf("%f",&matriz[i][j]);
    }
  }

  sum_lin(matriz,1,2,linha,coluna);
  //mult_lin(matriz,0,1);

  return 0;
}
