/*
Nome: Jin Uema - 3184382-4
Materia : Teoria dos Grafos
Arquivo : main.c
*/

#include <stdio.h>
#include <stdlib.h> // calloc
#include <string.h>
#include "grafo.c"

int main(){

  FILE* arquivo;
  int buffertam = 50;
  char buffer[buffertam];
  TGrafo *grafo;
  int valor_aux, tam_fila;
  char * num1;
  char * num2;
  TFila * fila_topo;


  arquivo = fopen("entrada.txt", "r");
  fgets(buffer, buffertam, arquivo); // anda 1 linha no arquivo
  valor_aux = atoi(buffer); // tamanho do grafo
  tam_fila = valor_aux; // valor auxiliar para a fila depois
  grafo = Init(valor_aux); // cria um grafo com tamanho = primeiro num do arquivo

  /* Cria um vetor de strings para utilizar-las nas classificações depois */
  char lista_tarefas[valor_aux][50];
  for (int i = 0; i < valor_aux; i++){
    fgets(buffer, buffertam, arquivo);
    strcpy(lista_tarefas[i], buffer);
  }


  /* Pega os valores das arestas e insere no grafo*/
  fgets(buffer, buffertam, arquivo);
  valor_aux = atoi(buffer);
  for (int i = 0; i < valor_aux; i++){
    fgets(buffer, buffertam, arquivo);
    num1 = strtok(buffer, " ");
    num2 = strtok(NULL, " ");
    insereA(grafo,atoi(num1)-1,atoi(num2)-1);

  }

  /* Faz o TopoSort e retorna a fila com os valores ordenados e printa */
  fila_topo = topoSort(grafo);
  for (int i = 0; i < tam_fila; i++){
    printf("tarefa %d : %s", Retira(fila_topo)+1, lista_tarefas[i]);
  }

  libera(grafo);

  return 0;
}
