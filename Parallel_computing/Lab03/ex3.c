/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex3.c
**************************************
*/

#include <stdio.h>

int main() {

  int resp = 0, eixo_x = 0, eixo_y = 0;
  while (resp % 2 == 0){
    printf("Digite um numero para a pirâmide: \n");
    scanf("%d",&resp);
  }

  for (eixo_x = 0; eixo_x <= (resp/2); eixo_x++){
    for (eixo_y = eixo_x + 1; eixo_y <= resp - eixo_x; eixo_y++){
      printf("%d ",eixo_y);
    }
    printf("\n");
    for (eixo_y = 0; eixo_y < (eixo_x + 1) * 2; eixo_y++){
      printf(" ");
    }
  }

  return 0;
}
