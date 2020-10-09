#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int topo;
    unsigned capacidade;
    int* vetor;
}Pilha;

Pilha * initPilha(int capacidade)
{
    struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->vetor = (int*)malloc(pilha->capacidade * sizeof(int));
    return pilha;
}

int cheio(Pilha* pilha)
{
    return pilha->topo == pilha->capacidade - 1;
}

int vazio(Pilha* pilha)
{
    return pilha->topo == -1;
}

void addPilha(Pilha* pilha, int n)
{
    if (cheio(pilha))
        return;
    pilha->vetor[++pilha->topo] = n;
}

int pop(Pilha* pilha)
{
    if (vazio(pilha))
        return -1;
    return pilha->vetor[pilha->topo--];
}

int val_top(Pilha* pilha)
{
    if (vazio(pilha))
        return -1;
    return pilha->vetor[pilha->topo];
}
