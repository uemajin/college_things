/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex14.c
**************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adiciona_string(char palavra[], char insere[], int pos){
  char pal[100] = {0};
    strncpy(pal, palavra, pos);
    int len = strlen(pal);
    strcpy(pal+len, insere);
    len += strlen(insere);
    strcpy(pal+len, palavra+pos);
    strcpy(palavra, pal);
}

int main() {

  char nome[100] = "A";
  adiciona_string(nome, "valor", 1);

  puts(nome);

  return 0;
}
