/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: b1070.c
**************************************
*/

#include <stdio.h>

int main() {

    int valor, qtde;

    scanf("%d", &valor);

    qtde = 0;

    while (qtde != 6){
      if(valor % 2 != 0){
        qtde ++;
        printf("%d\n", valor);
      }
      valor ++;
    }

    return 0;
}
