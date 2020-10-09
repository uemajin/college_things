/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: b1132.c
**************************************
*/

#include <stdio.h>

int main() {

    int n1, n2, t, soma;
    scanf("%d", &n1);
    scanf("%d", &n2);
    t = n1;
    soma = 0;
    if(n1 > n2){
      n1 = n2;
      n2 = t;
    }

    while(n1 <= n2){
      if(n1 % 13 != 0){
        soma = soma + n1;
      }
      n1 ++;
    }

    printf("%d\n", soma);

    return 0;
}
