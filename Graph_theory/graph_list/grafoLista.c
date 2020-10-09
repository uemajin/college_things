
#include <stdio.h>
#include <stdlib.h> // calloc
#include <limits.h>

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

typedef struct{
    int topo;
    unsigned capacidade;
    int* vetor;
}Pilha;

// declaracao de funcoes
TGrafo * Init( int V );
Pilha * initPilha(int capacidade);
void insereA( TGrafo *G, int v, int w);
void removeA(TGrafo *G, int v, int w);
void inverteA(TGrafo *G, int u);
void show(TGrafo *G);
void libera(TGrafo *G);
void Busca_prof(TGrafo *G, int v, int *visitado);
int cheio(Pilha* pilha);
int vazio(Pilha* pilha);
void addPilha(Pilha* pilha, int n);
int pop(Pilha* pilha);
int val_top(Pilha* pilha);
void Busca(TGrafo *G);
void mostraCaminho(TGrafo *G, int s, int t);
void printaCaminho(TGrafo *G ,int s, int t, int indice, int* visitado, int* caminho);

int main(void){
    // cria uma variavel ponteiro para armazenar um tipo TGrafo
    TGrafo *grafo;

    grafo = Init( 6 );// cria um grafo com 4 vertices

    insereA(grafo,0,1);
    insereA(grafo,0,2);
    insereA(grafo,0,3);
    insereA(grafo,1,3);
    insereA(grafo,1,4);
		insereA(grafo,3,4);
		insereA(grafo,4,2);
		insereA(grafo,5,5);

    show(grafo);

		printf("-----------------\n");

		int *visitado = (int*)calloc(grafo->V, sizeof(int));

		mostraCaminho(grafo, 0, 4);

    libera(grafo);
    return 0;
}
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

Pilha * initPilha(int capacidade){
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->vetor = (int*)malloc(pilha->capacidade * sizeof(int));
    return pilha;
}

int cheio(Pilha* pilha){
    return pilha->topo == pilha->capacidade - 1;
}

int vazio(Pilha* pilha){
    return pilha->topo == -1;
}

void addPilha(Pilha* pilha, int n){
    if (cheio(pilha))
        return;
    pilha->vetor[++pilha->topo] = n;
}

int pop(Pilha* pilha){
    if (vazio(pilha))
        return -1;
    return pilha->vetor[pilha->topo--];
}

int val_top(Pilha* pilha){
    if (vazio(pilha))
        return -1;
    return pilha->vetor[pilha->topo];
}


/*
Fun��o cria uma aresta v-w no grafo. A fun��o sup�e
que v e w s�o distintos, positivos e menores que V.
Se o grafo j� tem a aresta v-w, a fun��o n�o faz nada.
A fun��o tamb�m atualiza a quantidade de arestas no grafo.
*/
void insereA( TGrafo *G, int v, int w){
    // insere no inicio da lista da entrada do vertice v
    TNo *novo = (TNo*) calloc(1, sizeof(TNo));
    novo->w = w;
    novo->prox = G->adj[v];
    G->adj[v] = novo;
    G->A ++;
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
        printf("%d:",v);
        while( aux ){ // aux != null
            printf(" %d",aux->w);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void inverteA(TGrafo * G, int u){
	if (G->adj[u] != NULL){
		TNo * atual = G->adj[u];
		TNo * ant = NULL;
		TNo * prox = NULL;
		while(atual){
			prox = atual->prox;
			atual->prox = ant;
			ant = atual;
			atual = prox;
		}
		G->adj[u] = ant;
		return;
	}
	return;
}
/*
Fun��o libera a mem�ria utilizado pelo grafo e pela
matriz de adjac�ncia.
*/
void libera(TGrafo *G){

    free(G);
}

void Busca(TGrafo *G){
    int v;
    //para Cada v�rtice v de G fa�a
		//marque v como n�o visitado
    int *visitado = (int*)calloc(G->V, sizeof(int));

    // para Cada v�rtice v de G fa�a
    for(v=0;v<G->V;v++)
			if( !visitado[v] )
            Busca_prof(G,v,visitado);

    free(visitado);
}

void Busca_prof(TGrafo *G, int v, int *visitado){
		Pilha * aux;
		TNo *adjacente;
		aux = initPilha(G->V);
		addPilha(aux, v);
		while(!vazio(aux)){
			v = pop(aux);
			if(!visitado[v]){
				printf(" %d",v);
				visitado[v] = 1;
			}
    	for(adjacente = G->adj[v]; adjacente ;adjacente=adjacente->prox ){
        if( !visitado[adjacente->w])
          addPilha(aux, adjacente->w);
				}
		}
}

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

/*
mostraCaminho: funcao principal para alocar os vetores de visitados, caminho
e indice para chamar a printaCaminho.
*/
void mostraCaminho(TGrafo *G, int s, int t){
	int * visitado = (int *) calloc (G->V, sizeof(int)); // vetor visitados
	int idx = 0;
	int * caminho = (int *) calloc (G->V, sizeof(int));

	printaCaminho(G ,s, t, idx, visitado, caminho);
	}

/*
printaCaminho: busca o caminho recursivamente, e quando encontrado, printa
todos os valores guardados em um vetor auxiliar
*/
void printaCaminho(TGrafo *G, int s, int t,  int indice, int* visitado, int* caminho){
	TNo * adjacente; // no auxiliar
	visitado[s] = 1; // marca o s como visitado
	caminho[indice] = s; // vetor do caminho a ser printado
	indice++;

	if (s == t){
		printf("Foi encontrado um caminho: \n");
		for (int i = 0; i < indice; i++){
			printf("%d ",caminho[i]);
		}
		printf("\n");
	}else{
		for(adjacente = G->adj[s]; adjacente ;adjacente=adjacente->prox){
			if(!visitado[adjacente->w])
				printaCaminho(G, adjacente->w, t, indice, visitado, caminho);
		}
	}
	visitado[s] = 0;
	indice--;
}
