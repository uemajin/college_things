/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: b1008.c
**************************************
*/

#include <stdio.h>

int main() {

    int numfunc, hrtrab;
    float valorhr, salario;
    scanf("%d", &numfunc);
    scanf("%d", &hrtrab);
    scanf("%f", &valorhr);

    salario = hrtrab * valorhr;

    printf("NUMBER = %d\n", numfunc);
    printf("SALARY = U$ %.2f\n", salario);

    return 0;
}
