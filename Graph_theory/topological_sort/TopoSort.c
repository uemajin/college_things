/*
Programa implementa fun��es para criar e
manipular um grafo armazenado usando Listas de Adjacencias
-std=c99
*/

#include <stdio.h>
#include <stdlib.h> // calloc

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
void removeA(TGrafo *G, int v, int w);
void show(TGrafo *G);
void libera(TGrafo *G);
//Busca em profundidade
void Busca(TGrafo *G);
void Busca_prof(TGrafo *G, int v, int *visitado);

int main(void){
    // cria uma variavel ponteiro para armazenar um tipo TGrafo
    TGrafo *grafo;

    grafo = Init( 6 );// cria um grafo com 6 vertices

    insereA(grafo,0,2);
    insereA(grafo,0,3);
    insereA(grafo,0,4);
    insereA(grafo,2,4);
    insereA(grafo,3,4);
    insereA(grafo,3,5);
    insereA(grafo,4,5);
    insereA(grafo,5,1);
    insereA(grafo,1,2);
    insereA(grafo,1,4);

    show(grafo);
    printf("\nBusca em profundidade:");
    Busca(grafo);

    libera(grafo);
    return 0;
}
/*
Algoritmo Busca( G )
	Entrada: um grafo G representado em uma estrutura de dados.
	Sa�da:  visita todos os v�rtices do grafo em profundidade
*/
void Busca(TGrafo *G){
    int v;
    //para Cada v�rtice v de G fa�a
		//marque v como n�o visitado
    int *visitado = (int*)calloc(G->V, sizeof(int));

    // para Cada v�rtice v de G fa�a
    for(v=0;v<G->V;v++)
		// se v n�o foi visitado ent�o
		if( !visitado[v] ) // visitado[v] == 0
            //Busca-prof( G, v)
            Busca_prof(G,v,visitado);

    free(visitado);
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
    printf(" %d",v);

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
        if( w == aux->w)// ja existe o no
            return;
        ant = aux;
        aux = aux->prox;
    }
    // aux para com valor null
    // ant guarda o ultimo no da lista
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
Fun��o remove do grafo a aresta que tem ponta inicial v
e ponta final w. A fun��o sup�e que v e w s�o distintos,
positivos e menores que V. Se n�o existe a aresta v-w,
a fun��o n�o faz nada. A fun��o tamb�m atualiza a
quantidade de arestas no grafo.
*/
void removeA(TGrafo *G, int v, int w){

    TNo *aux = G->adj[v];
    TNo *ant = NULL;
    while( aux && w != aux->w ){ // enquanto nao cheguei ao final e nao achei o elemento
        ant = aux;
        aux = aux->prox;
    }
    // se nao achou elemento nao faz nada
    if( !aux )
        return;

    // testa se achou no inicio o ant  eh null
    if( !ant )
        G->adj[v] = aux->prox;
    else // remove do meio ou do final da lista
        ant->prox = aux->prox;

    free(aux);
    G->A--;
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
/*
Fun��o libera a mem�ria utilizado pelo grafo e pela
matriz de adjac�ncia.
*/
void libera(TGrafo *G){
    int v;
    // libera as listas
    for(v=0;v<G->V;v++){
        TNo *aux=G->adj[v];
        TNo *ant=NULL;
        while( aux ){ // aux != null
            ant = aux;
            aux = aux->prox;
            free(ant);
        }
    }
    // libera o vetor com entradas para listas
    free(G->adj);
    // libera o grafo
    free(G);
}
