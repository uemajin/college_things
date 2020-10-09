/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex12.c
**************************************
*/

#include <stdio.h>
#include <string.h>

int stringsearch(char *pal, char bus){

  char * ponto;
  int pos;

  ponto = strchr(pal, bus);
  if (ponto == NULL){
    return -1;
  }

  pos = ponto - pal;

  return pos;
}

int main() {

  char * nome = "Suco de maracuja";

  printf("O caractere está na %d posição",stringsearch(nome, 'c'));

  return 0;
}
