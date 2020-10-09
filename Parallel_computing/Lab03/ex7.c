/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: ex7.c
**************************************
*/

#include <stdio.h>
#include <string.h>

int main() {

  struct pessoa{
    char nome[20];
    int idade;
    float peso;
  };

  struct pessoa vals[3];

  for (int i = 0; i < 3; ++i){
    printf("Digite o nome da pessoa:");
    scanf("%s", vals[i].nome);
    printf("\nDigite a idade da pessoa:\n");
    scanf("%d",&vals[i].idade);
    printf("Digite o peso da pessoa:\n");
    scanf("%f",&vals[i].peso);
  }

  printf("Dados inseridos: \n");

  for (int i = 0; i < 3; i++){
    printf("Nome: ");
    puts(vals[i].nome);
    printf("Idade: %d\n", vals[i].idade);
    printf("Peso: %f\n\n", vals[i].peso);
  }

  return 0;
}
