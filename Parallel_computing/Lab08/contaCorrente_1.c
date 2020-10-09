/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: contaCorrente_1.c
**************************************
*/

#include <stdio.h>

int depositos(float saldo){ // Deposita 5 reais
  return saldo + 5.0;
}

int saques (float saldo){ // saca 2 reais
  return saldo - 2.0;
}

int main(void) {
  float saldo = 2000.00;
  int num_saques = 100;
  int num_depositos = 0;

  for (int i = 0; i < num_depositos; i++){
    saldo = depositos(saldo);
  }

  for (int i = 0; i < num_saques; i++){
    saldo = saques(saldo);
  }


  printf("Saldo final: %.2lf\n", saldo);
  return 0;
}