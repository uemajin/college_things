/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: b1071.c
**************************************
*/

#include <stdio.h>

int main() {

    int v1, v2, soma, t;

    scanf("%d", &v1);
    scanf("%d", &v2);

    soma = 0;

    if (v1>v2){
      t = v1;
      v1 = v2;
      v2 = t;
    }

    if (v1 % 2 != 0){
      v1 = v1 + 2;
      while (v1 < v2){
        if (v1 % 2 != 0){
          soma = soma + v1;
        }
        v1 ++;
      }
    }else{
      v1 ++;
      while (v1 < v2){
        if (v1 % 2 != 0){
          soma = soma + v1;
        }
        v1 ++;
      }
    }

    printf("%d\n", soma);
}
