/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: b1009.c
**************************************
*/

#include <stdio.h>

int main() {

    char nome;
    double salfixo, qtdvendas, bonus, total;
    scanf("%s", &nome);
    scanf("%lf", &salfixo);
    scanf("%lf", &qtdvendas);

    bonus = (qtdvendas * 0.15);

    total = salfixo + bonus;

    printf("TOTAL = R$ %.2f\n", total);

    return 0;
}
