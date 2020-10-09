/*
Programa implementa fun��es para criar e
manipular um grafo armazenado usando uma matriz de adjacencia
*/
#include <stdio.h>
#include <stdlib.h> // calloc

typedef struct _TNo{
	int w;
	struct _TNo *prox;
}TNo;

// definindo o tipo TGrafo
typedef struct{
	int V; // quantidade de v�rtices
	int A; // quantidade de arestas
	int **adj; //matriz de adjac�ncia
}TGrafo;

// declaracao de funcoes
TGrafo * Init( int V );
void insereA( TGrafo *G, int v, int w);
void removeA(TGrafo *G, int v, int w);
int ehSimetrico(TGrafo *G);
int ehEuleriano(TGrafo *G);
void show(TGrafo *G);
void libera(TGrafo *G);

int main(void){
    // cria uma variavel ponteiro para armazenar um tipo TGrafo
    TGrafo *grafo;

    grafo = Init( 6 );// cria um grafo com 4 vertices

    insereA(grafo,0,1);
		insereA(grafo,0,5);
    insereA(grafo,1,0);
    insereA(grafo,1,2);
		//insereA(grafo,1,4);
    insereA(grafo,2,1);
    insereA(grafo,2,3);
		insereA(grafo,3,2);
		insereA(grafo,3,4);
		insereA(grafo,4,3);
		//insereA(grafo,4,1);
		insereA(grafo,4,5);
		insereA(grafo,5,4);
		insereA(grafo,5,0);

		if(ehSimetrico(grafo)){
			printf("Simetrico\n");
		}else{
			printf("N Simetrico\n");
		}

		if(ehEuleriano(grafo)){
			printf("Euleriano\n");
		}else{
			printf("N Euleriano\n");
		}

    show(grafo);
    libera(grafo);
    return 0;
}
/*
Fun��o cria e devolve uma nova estrutura TGrafo,
inicializa os atributos da estrutura, cria uma matriz de
adjac�ncia para V v�rtices e zera os valores para arestas.
*/
TGrafo * Init( int V ){
    int i;
    TGrafo *g; //variavel ponteiro
    // aloca a inicializa a posicao de memoria com 0
    g = (TGrafo *) calloc(1, sizeof(TGrafo));
    g->V = V; // atualiza a quantidade de vertices
    g->A = 0; // zera o numero de arestas
    // alocar a matriz

    g->adj = (int**) calloc(g->V, sizeof(int *));
    for(i=0;i<g->V;i++)
        g->adj[i]=(int*) calloc(g->V, sizeof(int));

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
    if(G->adj[v][w]==0){// testa se nao tem aresta
        // insere aresta
        G->adj[v][w]=1;
        // incrementa qtd arestas
        G->A++;
    }
}
/*
Fun��o remove do grafo a aresta que tem ponta inicial v
e ponta final w. A fun��o sup�e que v e w s�o distintos,
positivos e menores que V. Se n�o existe a aresta v-w,
a fun��o n�o faz nada. A fun��o tamb�m atualiza a
quantidade de arestas no grafo.
*/
void removeA(TGrafo *G, int v, int w){
    if(G->adj[v][w]!=0){// testa se  tem aresta
        // remove aresta
        G->adj[v][w]=0;
        // decrementa qtd arestas
        G->A--;
    }
}

/*
Para cada v�rtice v do grafo, esta fun��o imprime,
em uma linha, todos os v�rtices adjacentes a v.
*/
void show(TGrafo *G){
    int v, w;
    printf("grafo V:%d A:%d\n",G->V,G->A);
    for( v=0; v<G->V;v++){
        printf("%d:",v);
        for( w=0; w<G->V;w++){
            if(G->adj[v][w]) //G->adj[v][w]==1
                printf(" %d",w);
        }
        printf("\n");
    }

}

int ehSimetrico(TGrafo * G){
	for (int i  = 0; i < G->V; i++){
		for (int j = 0; j < G->V; j++){
			if (G->adj[i][j] != G->adj[j][i]){
				return 0;
			}
		}
	}
	return 1;
}

int ehEuleriano(TGrafo * G){
	if (ehSimetrico(G)){
		int conta; // contador de grau do vertice
		for (int i  = 0; i < G->V; i++){
			conta = 0;
			for (int j = 0; j < G->V; j++){
				conta += G->adj[i][j];
			}
			if (conta%2 != 0){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

/*
Fun��o libera a mem�ria utilizado pelo grafo e pela
matriz de adjac�ncia.
*/
void libera(TGrafo *G){
    int i;

    for(i=0;i<G->V;i++)
        free(G->adj[i]);

    free(G->adj);
    free(G);
}
