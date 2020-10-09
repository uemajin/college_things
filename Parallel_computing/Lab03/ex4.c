/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex4.c
**************************************
*/

#include <stdio.h>
#include <string.h>

int main() {

  int num_nomes, i, j;
  char nomes[50][50];
  char zz[50];

  printf("Quantos nomes vao ser inseridos no sistema: ");
  scanf("%d", &num_nomes);

  printf("Digite os nomes 1 por linha: \n");
  for(i = 0; i < num_nomes; i++){
    scanf("%s",nomes[i]);
  }for(i = 0; i < num_nomes; i++){
    for(j = i+1; j < num_nomes; j++){
      //Bubble sort nos nomes em ordem alfabetica
      if (strcmp(nomes[i],nomes[j])>0){
        strcpy(zz, nomes[i]);
        strcpy(nomes[i], nomes[j]);
        strcpy(nomes[j], zz);
      }
    }
  }

  printf("\n\nOrdem alfabetica dos nomes: \n");
    for(i = 0; i <= num_nomes; i++){
      printf("%s \n",nomes[i]);
    }

  return 0;
}
