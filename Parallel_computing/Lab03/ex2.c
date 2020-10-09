/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex2.c
**************************************
*/

#include <stdio.h>

int main() {

  double notaA, notaB, notaC, media, exerc, ma;

  printf("Digite a primeira nota: \n");
  scanf("%lf",&notaA);
  printf("Digite a segunda nota: \n");
  scanf("%lf",&notaB);
  printf("Digite a terceira nota: \n");
  scanf("%lf",&notaC);
  printf("Digite a media dos exercícios: \n");
  scanf("%lf",&exerc);

  ma = ((notaA + (notaB*2) + (notaC*3) + exerc)/7);

    if (ma >= 9){
      printf("Nota : A\n");
    }else if (ma >= 7.5 && ma < 9){
      printf("Nota : B\n");
    }else if (ma >= 6 && ma < 7.5){
      printf("Nota : C\n");
    }else if (ma >= 4 && ma < 6){
      printf("Nota : D\n");
    }else if (ma < 4){
      printf("Nota : E\n");
    }

  return 0;
}
