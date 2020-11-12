

#include <stdio.h>
#include <stdlib.h> // calloc

typedef struct{
	int linha;
  int coluna;
	int **adj; //matriz de adjac�ncia
}TMatriz;

typedef struct{
    int first;
    int last;
    int N;
    int *elementos;
}TFila;

TMatriz * Init(int,int);
TMatriz * Carrega(char*);
void printaMatriz(TMatriz*,int,int);
int verifyPos(TMatriz*,int,int,int);
void valida(TMatriz * mapa, TFila * fila_x, TFila * fila_y,TFila * fila_nx,TFila * fila_ny, int a_x,int a_y,int val, int l, int c);
TFila * InitFila(int N);
void Insere (TFila *fila, int elemento);
int Retira (TFila *fila);
int estaVazia(TFila *fila);
int estaCheia(TFila *fila);

TMatriz * Init(int l, int c){
    TMatriz *g; //variavel ponteiro

    g = (TMatriz *) calloc(1, sizeof(TMatriz));
    g->linha = l; // atualiza a quantidade de vertices
    g->coluna = c; // zera o numero de arestas
    // alocar a matriz

    g->adj = (int**) calloc(l, sizeof(int *));
    for(int i=0;i<c;i++)
        g->adj[i]=(int*) calloc(c, sizeof(int));

    // retorna o grafo
    return g;
}

TFila * InitFila(int N){
    TFila *fila = (TFila*) calloc(1, sizeof(TFila));
    fila->elementos = (int*) calloc(N, sizeof(int));
    fila->N = N;
    fila->first = 0;
    fila->last = 0;
    return fila;
}

void Insere (TFila *fila, int elemento){
    if(!estaCheia(fila))
        fila->elementos[fila->last++] = elemento;
}

int estaVazia(TFila *fila){
    return fila->first == fila->last;
}

int estaCheia(TFila *fila){
    return fila->last == fila->N;
}

int Retira (TFila *fila){
    int ret = -1;
    if( !estaVazia(fila ))
        ret = fila->elementos[fila->first++];

    return ret;
}

TMatriz * Carrega(char* arq){
  int l=0, c=0;
  FILE * arquivo = fopen(arq, "r");
  fscanf(arquivo, "%d %d", &l, &c);
  TMatriz * mat = Init(l,c);
  for(l = 0; l < mat->linha; l++){
    for(c = 0; c < mat->coluna; c++){
      fscanf(arquivo, "%d", &mat->adj[l][c]);
    }
  }
  fclose(arquivo);
  return mat;
}

int verifyPos(TMatriz* mat,int x,int y, int status){
  if (mat->adj[x][y] != 0){
    printf("\nPosicao Invalida!\n");
    return 1;
  }else{
    if (status==0){
      mat->adj[x][y] = -2;
    }
    return 0;
  }
}

void printaMatriz(TMatriz * mapa, int x, int y){
  int l,c;
  for (l=0; l < mapa->linha; l++){
    for (c=0; c < mapa->coluna; c++){
      if (mapa->adj[l][c] == -2){
        printf("A ");
      }else if(l == x && y == c){
        printf("B ");
      }else{
        printf("%d ", mapa->adj[l][c]);
      }
    }
    printf("\n");
  }
}

void addPontos(TMatriz * mapa,int x, int y, int val){
  // printf("\n\nX: %d Y: %d, Valor ponto : %d",x,y,mapa->adj[x][y]);
  if (mapa->adj[x][y] == 0){
  //  printf("\nAdicionado\n");
    mapa->adj[x][y] = val;
  }
  //  printf("\nNao Adicionado\n");
}


void InsereF(TMatriz * mapa,TFila * fila_x, TFila * fila_y, int x, int y){
  if (mapa->adj[x][y] == 0){
    Insere(fila_x, x);
    Insere(fila_y, y);
  }
}

void valida(TMatriz * mapa, TFila * fila_x, TFila * fila_y,TFila * fila_nx,TFila * fila_ny, int a_x,int a_y,int val, int l, int c){

  if (a_x >= 0 && a_x <= l && a_y >=0 && a_y <= c){ // Se esta dentro da matriz
    if (a_x == 0){ // se linha superior
      InsereF(mapa, fila_x, fila_y, a_x+1, a_y);
      addPontos(mapa, a_x+1, a_y, val);
      if (a_y == 0){ // se canto superior esq
        InsereF(mapa, fila_x, fila_y, a_x, a_y+1);
        addPontos(mapa, a_x, a_y+1, val);
      } else if(a_y == c-1){ // se canto superior dir
        InsereF(mapa, fila_x, fila_y, a_x, a_y-1);
        addPontos(mapa, a_x, a_y-1, val);
      } else {
        InsereF(mapa, fila_x, fila_y, a_x, a_y+1);
        addPontos(mapa, a_x, a_y+1, val);
        InsereF(mapa, fila_x, fila_y, a_x, a_y-1);
        addPontos(mapa, a_x, a_y-1, val);
      }
    }else if (a_x == l-1){ // se linha inferior
      InsereF(mapa, fila_x, fila_y, a_x-1, a_y);
      addPontos(mapa, a_x-1, a_y, val);
      if (a_y == 0){ // se linha inferior esq
        InsereF(mapa, fila_x, fila_y, a_x, a_y+1);
        addPontos(mapa, a_x, a_y+1, val);
      }else if (a_y == c-1){ // se linha inferior dir
        InsereF(mapa, fila_x, fila_y, a_x, a_y-1);
        addPontos(mapa, a_x, a_y-1, val);
      }else{
        InsereF(mapa, fila_x, fila_y, a_x, a_y+1);
        addPontos(mapa, a_x, a_y+1, val);
        InsereF(mapa, fila_x, fila_y, a_x, a_y-1);
        addPontos(mapa, a_x, a_y-1, val);
      }
    }else if (a_y == 0){ // se linha esq
      InsereF(mapa, fila_x, fila_y, a_x-1, a_y);
      addPontos(mapa, a_x-1, a_y, val);
      InsereF(mapa, fila_x, fila_y, a_x, a_y+1);
      addPontos(mapa, a_x, a_y+1, val);
      InsereF(mapa, fila_x, fila_y, a_x+1, a_y);
      addPontos(mapa, a_x+1, a_y, val);
    }else if (a_y == c-1){ // se linha dir
      InsereF(mapa, fila_x, fila_y, a_x-1, a_y);
      addPontos(mapa, a_x-1, a_y, val);
      InsereF(mapa, fila_x, fila_y, a_x, a_y-1);
      addPontos(mapa, a_x, a_y-1, val);
      InsereF(mapa, fila_x, fila_y, a_x+1, a_y);
      addPontos(mapa, a_x+1, a_y, val);
    }else{
      InsereF(mapa, fila_x, fila_y, a_x-1, a_y);
      addPontos(mapa, a_x-1, a_y, val);
      InsereF(mapa, fila_x, fila_y, a_x, a_y-1);
      addPontos(mapa, a_x, a_y-1, val);
      InsereF(mapa, fila_x, fila_y, a_x+1, a_y);
      addPontos(mapa, a_x+1, a_y, val);
      InsereF(mapa, fila_x, fila_y, a_x, a_y+1);
      addPontos(mapa, a_x, a_y+1, val);
    }

  }

  //printaMatriz(mapa);
  //printf("\n\nPressione enter para continuar\n\n");
  //getchar();

}

int matFull(TMatriz * map){
  int l,c;
  for (l=0; l < map->linha; l++){
    for (c=0; c < map->coluna; c++){
      if (map->adj[l][c] == 0){
        return 0;
      }
    }
  }
  return 1;
}

int main(){
  int l, c;
  TFila * fila_x = InitFila(5000000);
  TFila * fila_y = InitFila(5000000);
  TFila * fila_nx = InitFila(5000000);
  TFila * fila_ny = InitFila(5000000);
  FILE * matriz= fopen("input.txt", "r");
  fscanf(matriz, "%d %d", &l, &c);
  fclose(matriz);
  TMatriz * mapa = Carrega("input.txt");

  int a_x,a_y;
  int b_x,b_y;
  int input_a = 1;
  int input_b = 1;
  int v = 1;

  while (input_a){
  printf("\nDigite a posicao do ponto A: X Y\n");
  scanf("%d%d", &a_x, &a_y);
  input_a = verifyPos(mapa, a_x, a_y, 0);
  }

  while (input_b){
  printf("\nDigite a posicao do ponto B: X Y\n");
  scanf("%d%d", &b_x, &b_y);
  input_b = verifyPos(mapa, b_x, b_y, 1);
  }

  printaMatriz(mapa,b_x,b_y);
  printf("\n\nPressione enter para continuar\n\n");
  getchar();

  valida(mapa,fila_x,fila_y,fila_nx,fila_ny,a_x,a_y,v,l,c);

  //printf("\n\nPressione enter para continuar\n\n");
  //getchar();

  v++;

  while (!matFull(mapa)){

    int new_x = Retira(fila_x);
    int new_y = Retira(fila_y);
    //printf("x: %d\n",new_x);
    //printf("y: %d\n\n",new_y);

    valida(mapa,fila_x,fila_y,fila_nx,fila_ny,new_x,new_y,v,l,c);

    new_x = Retira(fila_x);
    new_y = Retira(fila_y);
    //printf("x: %d\n",new_x);
    //printf("y: %d\n\n",new_y);

    valida(mapa,fila_x,fila_y,fila_nx,fila_ny,new_x,new_y,v,l,c);

    new_x = Retira(fila_x);
    new_y = Retira(fila_y);
    //printf("x: %d\n",new_x);
    //printf("y: %d\n\n",new_y);

    valida(mapa,fila_x,fila_y,fila_nx,fila_ny,new_x,new_y,v,l,c);

    new_x = Retira(fila_x);
    new_y = Retira(fila_y);
    //printf("x: %d\n",new_x);
    //printf("y: %d\n\n",new_y);

    valida(mapa,fila_x,fila_y,fila_nx,fila_ny,new_x,new_y,v,l,c);

    v++;

  }

  printaMatriz(mapa,b_x,b_y);
  printf("\nA distancia entre o ponto A e o ponto B e de %d casas.",mapa->adj[b_x][b_y]);

  return 0;
}
