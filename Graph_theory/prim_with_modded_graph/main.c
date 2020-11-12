#include <stdio.h>
#include <stdlib.h> // calloc
#include <math.h>

typedef struct{
	float ponto_x; // ponto x
  float ponto_y; // ponto y
}TPonto;

typedef struct{
	int V; // quantidade de v�rtices
	int A; // quantidade de arestas
  TPonto *pontos; //
	float **adj; //matriz de adjac�ncia
}TGrafo;

TGrafo * Init( int V );
void preenchePonto(TGrafo * G, int v, float x, float y);
void insereA( TGrafo *G, int v, int w);
float * prim(TGrafo *G, int v);

TGrafo * Init( int V ){
  int i;
  TGrafo *grafo=(TGrafo*)calloc(1,sizeof(TGrafo));
  grafo->A=0;
  grafo->V=V;
	grafo->pontos=(TPonto*)calloc(grafo->V,sizeof(TPonto));
  grafo->adj=(float**)calloc(grafo->V,sizeof(float*));
  for (i=0;i<grafo->V;i++)
    grafo->adj[i] = (float*)calloc(grafo->V,sizeof(float));
  return grafo;
}

void preenchePonto(TGrafo * G, int v, float x, float y){
  TPonto *ponto = (TPonto*)calloc(1,sizeof(TPonto));
  ponto->ponto_x = x;
  ponto->ponto_y = y;
  G->pontos[v] = *ponto;
}

void insereA(TGrafo * G, int v, int w){
  float ponto_xv, ponto_yv, ponto_xw, ponto_yw, distancia;
  TPonto *ponto_v = &G->pontos[v];
  TPonto *ponto_w = &G->pontos[w];
  ponto_xv = ponto_v->ponto_x;
  ponto_yv = ponto_v->ponto_y;
  ponto_xw = ponto_w->ponto_x;
  ponto_yw = ponto_w->ponto_y;
  distancia = sqrt(pow((ponto_xw - ponto_xv),2) + pow((ponto_yw - ponto_yv),2));
  G->adj[v][w] = G->adj[w][v] = distancia;
  G->A++;

}

void show(TGrafo *G){
    int v, w;
    printf("grafo V:%d A:%d\n",G->V,G->A);
    for(v=0; v<G->V;v++){
        TPonto *ponto_v = &G->pontos[v];
        printf("(%d,%d):",(int)ponto_v->ponto_x,(int)ponto_v->ponto_y);
        for( w=0; w<G->V;w++){
            if(G->adj[v][w]) //G->adj[v][w]==1
                printf(" %f",G->adj[v][w]);
        }
        printf("\n");
    }

}

float * prim(TGrafo *G, int v){

  int u;
  float val;
  int tamanho = 0; // len de arestras[]
  float * arestas = (float *)calloc(G->V-1,sizeof(float));// Peso de arestra U-V
  int * visitado = (int *)calloc(G->V, sizeof(int)); // vetor de vertice visitado (B)
  visitado[v] = 1;

  while (tamanho < G->V-1){

    val = INFINITY;
    int var_u;

    for(v=0;v < G->V; v++){
      if (visitado[v]){ // anda pelas arestas adjacentes a V
        for(u=0;u<G->V;u++){
          if (!visitado[u] && G->adj[v][u]){ // se ainda nao esta em B e tem peso na matriz
            if (val > G->adj[v][u]){
              val = G->adj[v][u];
              //printf("V = %d; U = %d; val = %f\n",v,u,G->adj[v][u]);
              var_u = u;
            }
          }
        }
      }
    }
    arestas[tamanho] = val; // guarda o peso da aresta em um conjunto
    visitado[var_u] = 1; // marca o vertice como visitado
    tamanho++;
  }


  printf("\n\nArestas retornadas:\n\n");
  for (int i=0;i < G->V-1; i++){
    printf("%d : %f\n",i,arestas[i]);
  }

  printf("\n\nVisitados:\n\n");
  for (int i=0;i < G->V; i++){
    printf("%d : %d\n",i,visitado[i]);
  }


  return arestas;
}

int main(){
  float * arestas;
  TGrafo *grafo;
  grafo = Init(6);
  preenchePonto(grafo, 0, 5, 2);
  preenchePonto(grafo, 1, 3, 2);
  preenchePonto(grafo, 2, 6, 3);
  preenchePonto(grafo, 3, 1, 4);
  preenchePonto(grafo, 4, 8, 5);
  preenchePonto(grafo, 5, 9, 8);
  insereA(grafo,1,2);
  insereA(grafo,3,5);
  insereA(grafo,1,3);
  insereA(grafo,5,4);
  insereA(grafo,3,0);

  show(grafo);

  arestas = prim(grafo, 1);

  return 0;
}
