/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: b1072.c
**************************************
*/

#include <stdio.h>

int main() {

    int qte, sim, nao, valor;

    scanf("%d", &qte);

    sim = 0; 
    nao = 0;

    for (int i=0; i<qte; i++){
      scanf("%d", &valor);
      if(valor >= 10 && valor <= 20){
        sim ++;
      }else{
        nao ++;
      }
    }

    printf("%d in\n", sim);
    printf("%d out\n", nao);


    return 0;
}
