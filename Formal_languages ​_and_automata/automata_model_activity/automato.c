/*
Jin Uema - 3184382-4
Tharcísio Néles - 3189120-9
Salomon Asher Motoryn - 4182512-8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scanner(char palavra[]);

int scanner(char palavra[]){
  int i;
  i = -1;
  q0: i++;
    switch (palavra[i]){
      case '-':
        goto q3;
        break;
      case '.':
        goto q4;
        break;
      case '0':
        goto q2;
        break;
      case '1':
        goto q1;
        break;
      case '2':
        goto q1;
        break;
      case '3':
        goto q1;
        break;
      case '4':
        goto q1;
        break;
      case '5':
        goto q1;
        break;
      case '6':
        goto q1;
        break;
      case '7':
        goto q1;
        break;
      case '8':
        goto q1;
        break;
      case '9':
        goto q1;
        break;
    }
    return(0);

  q1: i++;
    switch (palavra[i]){
      case '\0':
        return(1);
        break;
      case '.':
        goto q5;
        break;
      case '0':
        goto q2;
        break;
      case '1':
        goto q1;
        break;
      case '2':
        goto q1;
        break;
      case '3':
        goto q1;
        break;
      case '4':
        goto q1;
        break;
      case '5':
        goto q1;
        break;
      case '6':
        goto q1;
        break;
      case '7':
        goto q1;
        break;
      case '8':
        goto q1;
        break;
      case '9':
        goto q1;
        break;
    }
    return (0);
  q2: i++;
    switch (palavra[i]){
      case '.':
        goto q4;
        break;
    }
    return (0);
  q3: i++;
    switch (palavra[i]){
      case '0':
        goto q2;
        break;
      case '1':
        goto q6;
        break;
      case '2':
        goto q6;
        break;
      case '3':
        goto q6;
        break;
      case '4':
        goto q6;
        break;
      case '5':
        goto q6;
        break;
      case '6':
        goto q6;
        break;
      case '7':
        goto q6;
        break;
      case '8':
        goto q6;
        break;
      case '9':
        goto q6;
        break;
    }
    return (0);
  q4: i++;
    switch (palavra[i]){
      case '0':
        goto q4;
        break;
      case '1':
        goto q4;
        break;
      case '2':
        goto q4;
        break;
      case '3':
        goto q4;
        break;
      case '4':
        goto q4;
        break;
      case '5':
        goto q4;
        break;
      case '6':
        goto q4;
        break;
      case '7':
        goto q4;
        break;
      case '8':
        goto q4;
        break;
      case '9':
        goto q4;
        break;
      case '\0':
        return(2);
        break;
    }
    return (0);
  q5: i++;
    switch(palavra[i]){
      case '0':
        goto q5;
        break;
      case '1':
        goto q5;
        break;
      case '2':
        goto q5;
        break;
      case '3':
        goto q5;
        break;
      case '4':
        goto q5;
        break;
      case '5':
        goto q5;
        break;
      case '6':
        goto q5;
        break;
      case '7':
        goto q5;
        break;
      case '8':
        goto q5;
        break;
      case '9':
        goto q5;
        break;
      case '\0':
        return(2);
        break;
    }
    return(0);
  q6: i++;
    switch(palavra[i]){
      case '0':
        goto q6;
        break;
      case '1':
        goto q6;
        break;
      case '2':
        goto q6;
        break;
      case '3':
        goto q6;
        break;
      case '4':
        goto q6;
        break;
      case '5':
        goto q6;
        break;
      case '6':
        goto q6;
        break;
      case '7':
        goto q6;
        break;
      case '8':
        goto q6;
        break;
      case '9':
        goto q6;
        break;
      case '\0':
        return(1);
        break;
      case '.':
        goto q7;
        break;
    }
    return (0);
  q7: i++;
    switch (palavra[i]){
      case '0':
        goto q7;
        break;
      case '1':
        goto q7;
        break;
      case '2':
        goto q7;
        break;
      case '3':
        goto q7;
        break;
      case '4':
        goto q7;
        break;
      case '5':
        goto q7;
        break;
      case '6':
        goto q7;
        break;
      case '7':
        goto q7;
        break;
      case '8':
        goto q7;
        break;
      case '9':
        goto q7;
        break;
      case '\0':
        return(1);
        break;
    }
    return (0);
}

int main(void) {
  int resposta;
  char * palavra;
  char palavras[60] = "21 +45.67 0.123 .456 -42 xx 00.123";
  palavra = strtok(palavras, " ");
  while( palavra != NULL ) {
    resposta = scanner(palavra);
      switch (resposta){
        case 0:
          printf("<ERRO>\n");
          break;
        case 1:
          printf("<INTEIRO>\n");
          break;
        case 2:
          printf("<P.FLUTUANTE>\n");
          break;
  }

    palavra = strtok(NULL, " ");
}
  return(0);
}
/*
Jin Uema - 3184382-4
Tharcísio Néles - 3189120-9
Salomon Asher Motoryn - 4182512-8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scanner(char palavra[]);

int scanner(char palavra[]){
  int i;
  i = -1;
  q0: i++;
    switch (palavra[i]){
      case '-':
        goto q3;
        break;
      case '.':
        goto q4;
        break;
      case '0':
        goto q2;
        break;
      case '1':
        goto q1;
        break;
      case '2':
        goto q1;
        break;
      case '3':
        goto q1;
        break;
      case '4':
        goto q1;
        break;
      case '5':
        goto q1;
        break;
      case '6':
        goto q1;
        break;
      case '7':
        goto q1;
        break;
      case '8':
        goto q1;
        break;
      case '9':
        goto q1;
        break;
    }
    return(0);

  q1: i++;
    switch (palavra[i]){
      case '\0':
        return(1);
        break;
      case '.':
        goto q5;
        break;
      case '0':
        goto q2;
        break;
      case '1':
        goto q1;
        break;
      case '2':
        goto q1;
        break;
      case '3':
        goto q1;
        break;
      case '4':
        goto q1;
        break;
      case '5':
        goto q1;
        break;
      case '6':
        goto q1;
        break;
      case '7':
        goto q1;
        break;
      case '8':
        goto q1;
        break;
      case '9':
        goto q1;
        break;
    }
    return (0);
  q2: i++;
    switch (palavra[i]){
      case '.':
        goto q4;
        break;
    }
    return (0);
  q3: i++;
    switch (palavra[i]){
      case '0':
        goto q2;
        break;
      case '1':
        goto q6;
        break;
      case '2':
        goto q6;
        break;
      case '3':
        goto q6;
        break;
      case '4':
        goto q6;
        break;
      case '5':
        goto q6;
        break;
      case '6':
        goto q6;
        break;
      case '7':
        goto q6;
        break;
      case '8':
        goto q6;
        break;
      case '9':
        goto q6;
        break;
    }
    return (0);
  q4: i++;
    switch (palavra[i]){
      case '0':
        goto q4;
        break;
      case '1':
        goto q4;
        break;
      case '2':
        goto q4;
        break;
      case '3':
        goto q4;
        break;
      case '4':
        goto q4;
        break;
      case '5':
        goto q4;
        break;
      case '6':
        goto q4;
        break;
      case '7':
        goto q4;
        break;
      case '8':
        goto q4;
        break;
      case '9':
        goto q4;
        break;
      case '\0':
        return(2);
        break;
    }
    return (0);
  q5: i++;
    switch(palavra[i]){
      case '0':
        goto q5;
        break;
      case '1':
        goto q5;
        break;
      case '2':
        goto q5;
        break;
      case '3':
        goto q5;
        break;
      case '4':
        goto q5;
        break;
      case '5':
        goto q5;
        break;
      case '6':
        goto q5;
        break;
      case '7':
        goto q5;
        break;
      case '8':
        goto q5;
        break;
      case '9':
        goto q5;
        break;
      case '\0':
        return(2);
        break;
    }
    return(0);
  q6: i++;
    switch(palavra[i]){
      case '0':
        goto q6;
        break;
      case '1':
        goto q6;
        break;
      case '2':
        goto q6;
        break;
      case '3':
        goto q6;
        break;
      case '4':
        goto q6;
        break;
      case '5':
        goto q6;
        break;
      case '6':
        goto q6;
        break;
      case '7':
        goto q6;
        break;
      case '8':
        goto q6;
        break;
      case '9':
        goto q6;
        break;
      case '\0':
        return(1);
        break;
      case '.':
        goto q7;
        break;
    }
    return (0);
  q7: i++;
    switch (palavra[i]){
      case '0':
        goto q7;
        break;
      case '1':
        goto q7;
        break;
      case '2':
        goto q7;
        break;
      case '3':
        goto q7;
        break;
      case '4':
        goto q7;
        break;
      case '5':
        goto q7;
        break;
      case '6':
        goto q7;
        break;
      case '7':
        goto q7;
        break;
      case '8':
        goto q7;
        break;
      case '9':
        goto q7;
        break;
      case '\0':
        return(1);
        break;
    }
    return (0);
}

int main(void) {
  int resposta;
  char * palavra;
  char palavras[60] = "21 +45.67 0.123 .456 -42 xx 00.123";
  palavra = strtok(palavras, " ");
  while( palavra != NULL ) {
    resposta = scanner(palavra);
      switch (resposta){
        case 0:
          printf("<ERRO>\n");
          break;
        case 1:
          printf("<INTEIRO>\n");
          break;
        case 2:
          printf("<P.FLUTUANTE>\n");
          break;
  }

    palavra = strtok(NULL, " ");
}
  return(0);
}
