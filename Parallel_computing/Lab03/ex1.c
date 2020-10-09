/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex1.c
**************************************
*/

#include <stdio.h>

int main() {

  int tamanho,linha;

  printf("Digite o tamanho da matriz: \n");
  scanf("%d", &tamanho);

  float a[tamanho][tamanho],men_num;

  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      printf("Posição: %d,%d ", i+1, j+1);
      scanf("%f", &a[i][j]);
    }
  }

  men_num = a[0][0]; //declarei o men_num como primeiro valor
  linha=0;


  for (int m = 0; m < tamanho; m++){
    for (int n = 0; n < tamanho; n++){
      printf("menor numero: %f\n", men_num);
      printf("M=%d, N=%d\n", m, n);
      if(a[m][n] < men_num){
        men_num = a[m][n];
        linha = m;
      }
    }
  }

  printf("A linha que contém o menor número é: %d\n\n", linha+1);

  return 0;
}
