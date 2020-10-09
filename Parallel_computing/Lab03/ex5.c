/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex5.c
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

  double matriz[tamanho_i][tamanho_j],x;

  for (i = 0; i < tamanho_i; ++i){
    for (j = 0; j < tamanho_j; ++j){
      printf("Digite o valor da posição %dx%d:\n", i+1, j+1);
      scanf("%lf",&matriz[i][j]);

    }
  }

  printf("Selecione a multiplicação:\n1 - Linha\n2 - Coluna\n");
  scanf("%d",&escolha);

  printf("Seleciona a posição: \n");
  scanf("%d",&pos);

  printf("Digite o multiplicador:\n");
  scanf("%lf",&x);

  switch (escolha){
    case 1:
      for (i = 0; i < tamanho_i; ++i){
        for (j = 0; j < tamanho_j; ++j){
          if (i == pos-1){
            matriz[i][j] = matriz[i][j] * x;
          }
        }
      }
    break;

    case 2:
    for (i = 0; i < tamanho_i; ++i){
      for (j = 0; j < tamanho_j; ++j){
        if (j == pos-1){
          matriz[i][j] = matriz[i][j] * x;
        }
      }
    }
    break;
  }

  printf("A matriz final é: \n\n");

  for (i = 0; i < tamanho_i; i++){
    for (j = 0; j < tamanho_j; j++){
      printf("[%lf] ",matriz[i][j]);
    }
    printf("\n");
  }




  return 0;
}
