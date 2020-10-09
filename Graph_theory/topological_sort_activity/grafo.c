/*
Nome: Jin Uema - 3184382-4
Materia : Teoria dos Grafos
Arquivo : grafo.c
*/

#include <stdio.h>
#include <stdlib.h> // calloc
#include <string.h>
#include "fila.c"

typedef struct _TNo{
	int w; // vertice adjacente ao vertice v
	struct _TNo *prox; // proximo no na lista de ajdacencia
}TNo;

// definindo o tipo TGrafo
typedef struct{
	int V; // quantidade de v�rtices
	int A; // quantidade de arestas
	TNo **adj; //vetor armanazena o inicio de uma lista encadeada de adjac�ncia
}TGrafo;

// declaracao de funcoes
TGrafo * Init( int V );
void insereA( TGrafo *G, int v, int w);
int buscaCaminho(TGrafo *G , int s, int t);
void removeA(TGrafo *G, int v, int w);
void show(TGrafo *G);
void libera(TGrafo *G);
void Busca_prof(TGrafo *G, int v, int *visitado);
TFila * topoSort(TGrafo *G);

/*
Fun��o cria e devolve uma nova estrutura TGrafo,
inicializa os atributos da estrutura, cria uma lista de
adjac�ncias para V v�rtices e zera os valores para arestas.
*/
TGrafo * Init( int V ){
    int i;
    TGrafo *g; //variavel ponteiro
    // aloca a inicializa a posicao de memoria com 0
    g = (TGrafo *) calloc(1, sizeof(TGrafo));
    g->V = V; // atualiza a quantidade de vertices
    g->A = 0; // zera o numero de arestas

    // alocar vetor para as entradas da lista de adjacencias
    g->adj = (TNo**) calloc(g->V, sizeof(TNo *));

    // retorna o grafo
    return g;
}



/*
Fun��o cria uma aresta v-w no grafo. A fun��o sup�e
que v e w s�o distintos, positivos e menores que V.
Se o grafo j� tem a aresta v-w, a fun��o n�o faz nada.
A fun��o tamb�m atualiza a quantidade de arestas no grafo.
*/
void insereA( TGrafo *G, int v, int w){
    TNo *aux = G->adj[v];
    TNo *ant = NULL;
    while( aux && w >= aux->w ){ // enquanto nao cheguei ao final e nao achei a posicao certa
        if( w == aux->w){
          printf("Tarefas (%d,%d) ja inseridas !\n", v+1,w+1);
          return;
        }// ja existe o no
        ant = aux;
        aux = aux->prox;
    }
    // aux para com valor null
    // ant guarda o ultimo no da lista

    if (v > w){
      if (G->adj[v] != NULL && G->adj[w] != NULL){
        if(buscaCaminho(G,w,v))
            printf("Tarefas (%d,%d) sao ciclicas !\n", v+1,w+1);
          return;
        }
    }


    // cria o novo no
    TNo *novo = (TNo*) calloc(1, sizeof(TNo));
    novo->w = w;
    novo->prox = aux;
    if( ant ) // se existe anterio insere no final usando ant
        // insere no final da lista
        ant->prox = novo;
    else
        // insere no inicio pois a lista esta vazia
        G->adj[v] = novo;
    // incrementa o numero de arestas
    G->A++;

}


/*
Funcao verifica se o caminho entre as vertices causa
um grafo ciclico, se isto ocorre, retorna o verdadeiro.
*/
int buscaCaminho(TGrafo *G , int s, int t){
  int r = 0;
  int * visitado = (int *) calloc (G->V, sizeof(int)); // vetor visitados
  Busca_prof(G, s, visitado);
  r = visitado[t];
  free(visitado);
  return (r);
}

/*
Fun��o remove do grafo a aresta que tem ponta inicial v
e ponta final w. A fun��o sup�e que v e w s�o distintos,
positivos e menores que V. Se n�o existe a aresta v-w,
a fun��o n�o faz nada. A fun��o tamb�m atualiza a
quantidade de arestas no grafo.
*/
void removeA(TGrafo *G, int v, int w){
  TNo * temp, *prev;
  //printf("START AUX->W: %d; AUX_P->W = %d\n\n",aux->w, aux->prox->w);
  temp = G->adj[v];
  if (temp != NULL && temp->w == w){
    G->adj[v] = temp->prox;
    free(temp);
    return;
  }
  while (temp != NULL && temp->w != w){
     prev = temp;
     temp = temp->prox;
 }
 if (temp == NULL) return;
 prev->prox = temp->prox;
 free(temp);
}

/*
Para cada v�rtice v do grafo, esta fun��o imprime,
em uma linha, todos os v�rtices adjacentes a v.
*/
void show(TGrafo *G){
    int v, w;
    printf("grafo V:%d A:%d\n",G->V,G->A);
    for(v=0;v<G->V;v++){
        TNo *aux;
        aux = G->adj[v];
        printf("%d:",v+1);
        while( aux ){ // aux != null
            printf(" %d",aux->w+1);
            aux = aux->prox;
        }
        printf("\n");
    }
}
/*
Fun��o libera a mem�ria utilizado pelo grafo e pela
matriz de adjac�ncia.
*/
void libera(TGrafo *G){

    free(G);
}

/*
Algoritmo Busca-prof( G, v )
	Entrada: um grafo G representado em uma estrutura de dados e um v�rtice v
	Sa�da:  visita a partir v todos os v�rtices do grafo em profundidade

*/
void Busca_prof(TGrafo *G, int v, int *visitado){
    int w;
    //marque v como visitado
    visitado[v] = 1;
    //imprime v
    //para Cada v�rtice w adjacente a v fa�a
    TNo *adjacente;
    for(adjacente = G->adj[v]; adjacente;adjacente=adjacente->prox ){
        // se w n�o foi visitado ent�o
        if( !visitado[adjacente->w])
            //Busca-prof(G, w)
            Busca_prof(G,adjacente->w,visitado);
    }
}

/*
Algoritmo Busca Topologica (G)
  Entrada: um grafo G representado em uma estrutura de ordenados
  Saida: uma fila com os valores ordenados em ordem topologica.

*/
TFila * topoSort(TGrafo *G){

  TFila *zerovet = InitFila(G->V);
  TFila *topoSort = InitFila(G->V);

  int *indegree = (int*)calloc(G->V, sizeof(int));
  int z = 0;
  TNo * temp;

  /*
  Realiza a classificacao do vetor de indegree. ele conta todos os elementos
  que chegam em um vertice v.
  */
  for(int v=0;v<G->V;v++){
      TNo *aux;
      aux = G->adj[v];
      //printf("TopoSort %d: ",v+1);
      while( aux ){ // aux != null
          indegree[aux->w]+= 1;
          aux = aux->prox;
      }
      //printf("%d\n",indegree[v]);
}
/*
  Realiza a insercao na fila auxiliar com indices 0.
*/
  while (!estaCheia(topoSort)){
    for(int v=0; v<G->V; v++){
      if (indegree[v] == 0){
        Insere(zerovet, v);
        //printf("Valor colocado na fila inicial : %d \n ",v);
        indegree[v] = -1;
      }
    }

    /*
      Retira da fila auxiliar e insere na fila de ordem topologica..
    */
    z = Retira(zerovet);
    Insere(topoSort, z);
    temp = G->adj[z];
    //printf("Valor colocado na fila final : %d \n ",z+1);
    while( temp ){ // aux != null
      indegree[temp->w]-= 1;
      temp = temp->prox;
      }
  }

  free(indegree);
  return topoSort;
}
