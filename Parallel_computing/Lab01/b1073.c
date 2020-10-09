/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: b1073.c
**************************************
*/

#include <stdio.h>

int main() {

    int valor, contador;

    scanf("%d", &valor);

    contador = 2;

    while(contador <= valor){
      printf("%d^2 = %d\n", contador, contador*contador);
      contador = contador + 2;
    }

    return 0;
}
