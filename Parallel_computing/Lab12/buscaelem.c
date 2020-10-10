#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define TAM_VET 11235

int main(void) {
    int *v = NULL;
    int busca = 2521;
    double start = omp_get_wtime();

    v = (int *)calloc(TAM_VET, sizeof(int));
    for(int i = 0; i < TAM_VET; i++){
        v[i] = TAM_VET - i;
    }
    #pragma omp parallel for
    for (int i=0; i<TAM_VET ;i++){
        if(v[i] == busca){
            printf("Procurado: %d\n Encontrado na Posicao %d do vetor\n", busca, i);
        }
    }

    printf("Tempo: %f\n", omp_get_wtime()-start);
    free(v);
    return 0;
}
