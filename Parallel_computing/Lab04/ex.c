#include <stdio.h>
//#include <cstdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    float altura;
}PESSOA;

void leNomeArquivoEntrada(char * s1){
  printf("Digite o nome do arquivo de entrada: ");
  fgets(s1);
}

int abreArquivoAEntrada(FILE *arq, char * s1){
  if ((arq = fopen(s1, "r")) == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int leDadosUmaPessoa(FILE * Arq ,PESSOA p){
  FILE * arq;
  arq = fopen (Arq, "r");
  char str1[50];
  if (fgetc(arq) != EOF){
  for (int i = 0; i < 3; i++){
    str1 = fgetc(arq);
    printf("%s",str1);
    strncpy(p.nome, str1, 50);
    str1 = fgetc(arq);
    printf("%d",atoi(str1));
    p.idade = atoi(str1);
    str1 = fgetc(arq);
    printf("%f",atof(str1));
    p.altura = atof(str1);
    return 1;
    }
  }else{
    return 0;
  }

}

void fechaArquivo(FILE * arq){
  fclose(arq);
}

void ordenaVetor(PESSOA Povo[], int tam){
  PESSOA aux;
  for (int i = 0; i < tam; i++){
      if (Povo[i].altura > Povo[i+1].altura){
        aux = Povo[i];
        Povo[i] = Povo[i+1];
        Povo[i+1] = aux;
      }
  }
}

void imprimeVetor(PESSOA Povo[], int tam){
  for (int i = 0; i < tam; i++){
    printf("%s\n", Povo[i].nome);
    printf("%d\n", Povo[i].idade);
    printf("%f\n\n", Povo[i].altura);
  }
}

int main()
{
     char S1[50];
     PESSOA Povo[10], P;
     FILE *Arq;
     int i;

     leNomeArquivoEntrada(S1);
     if (abreArquivoAEntrada(Arq, S1) == 1){
            do{
                    if (leDadosUmaPessoa(Arq ,P) == 1){ //pegar do arquivo e armazenar
                        Povo[i] = P;
                        i++;
                    }
                    else break;
            } while(1);
            fechaArquivo(Arq);
            ordenaVetor(Povo,i);
            imprimeVetor(Povo,i);
    }
    else printf("Erro na abertura do arquivo");
     return 0;

}
