/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: fibParalelo.c
**************************************
*/

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int fibonacci(int n);
void *threads(void *numero_t, int qtde);
long resp_final;
int nthreads = 2;

int fib(int n){
 return (n < 2) ? 1 :(fib(n-1) + fib(n-2));
}

void *threads_fib(void *numero_t){
  long n, fibo_resultado;
  long lNumero_t = (long) numero_t;
  n = (lNumero_t % nthreads == 0) ? n - 2 : n - 1;

  fibo_resultado = fib(n);
  resp_final += fibo_resultado;
}

int main(void) {
  double time_s, time_e, time_pfib, time_rfib;
  pthread_t *treadson;
  long thread, fibo_r;
  struct timeval tempo;
  long n = 42;

  treadson = malloc(nthreads * sizeof(pthread_t));

  gettimeofday(&tempo, NULL);
  time_s = (double) (tempo.tv_sec*1000.0) + (double) (tempo.tv_usec / 1000.0);

  fibo_r = fib(n);

  gettimeofday(&tempo, NULL);
  time_e = (double) (tempo.tv_sec*1000.0) + (double) (tempo.tv_usec / 1000.0);
  time_rfib = time_e - time_s;

  printf("\n Tempo de Execução Fibonacci Recursivo: %lf ", time_rfib);

  gettimeofday(&tempo, NULL);
  time_s = (double) (tempo.tv_sec*1000.0) + (double) (tempo.tv_usec / 1000.0);
  for (thread = 0; thread < nthreads; thread++){
    pthread_create(&treadson[thread], NULL, threads_fib, (void *) thread);
  }
  gettimeofday(&tempo, NULL);
  time_e = (double) (tempo.tv_sec*1000.0) + (double) (tempo.tv_usec / 1000.0);
  time_pfib = time_e - time_s;

  for (thread = 0; thread < nthreads; thread++){
    pthread_join(treadson[thread], NULL);
  }

  printf("\n Tempo de Execução Fibonacci Paralelo: %lf ", time_pfib);

  free(treadson);

  return 0;
}
