/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex6.c
**************************************
*/

#include <stdio.h>
#include <string.h>

int main() {

  int i,j,escolha,tamanho_i,tamanho_j,pos;

  printf("Selecione quantas linhas a matriz vai ter:\n");
  scanf("%d",&tamanho_i);

  printf("Selecione quantas colunas a matriz vai ter:\n");
  scanf("%d",&tamanho_j);

  double matriza[tamanho_i][tamanho_j];
  double matrizb[tamanho_j][tamanho_i];

  for (i = 0; i < tamanho_i; ++i){
    for (j = 0; j < tamanho_j; ++j){
      printf("Digite o valor da posição %dx%d:\n", i+1, j+1);
      scanf("%lf",&matriza[i][j]);

    }
  }

  //matriz normal

  for (i = 0; i < tamanho_i; i++){
    for (j = 0; j < tamanho_j; j++){
      printf("[%lf] ",matriza[i][j]);
    }
    printf("\n");
  }

  //matriz transposta
  for (i = 0; i < tamanho_i; i++){
    for (j = 0; j < tamanho_j; j++){
      matrizb[j][i] = matriza[i][j];
    }
  }


  printf("A matriz transposta é: \n\n");

  for (j = 0; j < tamanho_j; j++){
    for (i = 0; i < tamanho_i; i++){
      printf("[%lf] ",matrizb[j][i]);
    }
    printf("\n");
  }

  return 0;
}
