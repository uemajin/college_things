/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex13.c
**************************************
*/

#include <stdio.h>
#include <string.h>


int main() {

  int pos;

  char nome[100] = "kswdjaoljwdlakrjklwjra4e2fqawfabawbabwewkewkdvdawakd-aib-amidfaw-ek2-ve-iawcawdjawhecnawho2 xuxaw2xr";

  for (int i = 0; i < 100; i++){;

    puts(nome);
    printf("Digite a posição do caractere a ser removido: ");
    scanf("%d",&pos);

    memmove(&nome[pos], &nome[pos+1], strlen(nome) - pos);

  }

  return 0;
}
