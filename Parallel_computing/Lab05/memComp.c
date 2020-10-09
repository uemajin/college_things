/*
**************************************
* Autor: Jin Uema
* TIA: 3184382-4
* ARQUIVO: memComp.c
**************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SHMSIZE 300

int main(int argc, char *argv[]){
  int shmid, paiid, status;
  int *shm;
  key_t chave = 5678;
  shmid = shmget(chave, SHMSIZE, 0666 | IPC_CREAT);
  shm = shmat(shmid, NULL, 0);
  paiid = fork();

  if (paiid == 0){

    *shm = *shm + 2;
    printf("Filho: %d\n", *shm);
    shmdt(shm);

  }else{
    *shm = 1;
    printf("Começo: %d\n", *shm);
    wait(&status);
    *shm = *shm * 4;
    printf("Final: %d\n\n", *shm);
    }
    return 0;
}
