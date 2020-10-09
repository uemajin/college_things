/*
Nome: Jin Uema - 3184382-4
Materia : Teoria dos Grafos
Arquivo : fila.c
*/

#include <stdlib.h>
#include <stdio.h>

// declara��o do tipo Fila
typedef struct{
    int first;
    int last;
    int N;
    int *elementos;
}TFila;
// declaracao das funcoes para manipular o tipo Fila
TFila * InitFila(int N);

void Insere (TFila *fila, int elemento);
int Retira (TFila *fila);

//quantidade (quantidade elementos),
int estaVazia(TFila *fila);
int estaCheia(TFila *fila);


// implementa��o das fun��es que manipulam a Fila
/*
 Funcao para criar e inicializar a fila
*/
TFila * InitFila(int N){
    TFila *fila = (TFila*) calloc(1, sizeof(TFila));
    fila->elementos = (int*) calloc(N, sizeof(int));
    fila->N = N;
    fila->first = 0;
    fila->last = 0;
    return fila;
}
/*
 Funcao para desalocar memoria utilizada pela fila
*/

/*
funcao insere um elemento no final da fila
*/
void Insere (TFila *fila, int elemento){
    if(!estaCheia(fila))
        fila->elementos[fila->last++] = elemento;
    else
        printf("\nfila cheia.");
}
/*
funcao remove um elemento do inicio da  fila
*/
int Retira (TFila *fila){
    int ret = -1;
    if( !estaVazia(fila ))
        ret = fila->elementos[fila->first++];
    else
        printf("\nfila vazia.");

    return ret;
}
/*
funcao testa se a fila esta vazia
*/
int estaVazia(TFila *fila){
    return fila->first == fila->last;
}
/*
funcao testa se a fila esta cheia
*/
int estaCheia(TFila *fila){
    return fila->last == fila->N;
}
