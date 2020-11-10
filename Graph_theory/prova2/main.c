#include <stdio.h>
#include <stdlib.h> // calloc

typedef struct{
	int V; // quantidade de v�rtices
	int A; // quantidade de arestas
	int **adj; //matriz de adjac�ncia
}TGrafo;

typedef struct{
	int w; // vertice representado pela matriz
	int ponto_x; // ponto x
  int ponto_y; // ponto y
}Tponto;

TGrafo * Init( int V );
void insereA( TGrafo *G, int v, int w);
void removeA(TGrafo *G, int v, int w);

int main(){
  TGrafo *grafo;
  grafo = Init(6);

}
