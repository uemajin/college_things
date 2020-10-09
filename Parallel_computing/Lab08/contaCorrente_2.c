/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: contaCorrente_2.c
**************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;

void *banco(void* rank);

float saldo = 2000.00;
int num_saques = 100;
int num_depositos = 0;

int depositos(float saldo){ // Deposita 5 reais
  return saldo + 5.0;
}

int saques (float saldo){ // saca 2 reais
  return saldo - 2.0;
}

void *banco(void* rank){
  long my_rank = (long) rank;

  for (int i = 0; i < num_depositos; i++){
    saldo = depositos(saldo);
  }

  for (int i = 0; i < num_saques; i++){
    saldo = saques(saldo);
  }

  return NULL;

}

int main(void) {
  long thread;
  pthread_t* thread_handles;
  thread_count = 6;

  thread_handles = malloc (thread_count*sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++){
    pthread_create(&thread_handles[thread], NULL, banco, (void *) thread);
  }

  for (thread = 0; thread < thread_count; thread++){
    pthread_join(thread_handles[thread], NULL);
  }

  printf("Saldo final: %.2lf\n", saldo);

  free(thread_handles);

  return 0;
}