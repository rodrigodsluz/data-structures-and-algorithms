#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

void insertionSort (TipoItem *A, int n)
{
    int i, j, min;
    TipoItem aux;

    for(i=1; i<n; i++){
        aux = A[i];
        j = i;
        while((aux.Chave < A[j-1].Chave)&&j>0){
            A[j] = A[j-1];
            j--;
        }
        A[j] = aux;
    }

    printf ("\nVETOR ORDENADO INSERTIONSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i].Chave);

}





