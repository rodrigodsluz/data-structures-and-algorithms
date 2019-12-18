#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main (int argc, char *argv[])
{
    TipoItem *A;
    int n=10, i;

    A = calloc(sizeof(TipoItem), n);
    printf("\nVetor Criado: \n");
    for (i=0; i<n; i++){
        A[i].Chave = rand() % 100;
        printf (" %d",A[i].Chave);
    }

    printf("\n\n"); //system("pause");
    getchar();

    insertionSort(A, n);

    printf("\n\n"); //system("pause");
    getchar();
    return 0;
}
