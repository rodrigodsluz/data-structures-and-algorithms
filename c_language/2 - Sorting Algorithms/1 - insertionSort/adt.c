#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

void insertionSort (itemType *A, int n)
{
    int i, j, min;
    itemType aux;

    for(i=1; i<n; i++){
        aux = A[i];
        j = i;
        while((aux.key < A[j-1].key)&&j>0){
            A[j] = A[j-1];
            j--;
        }
        A[j] = aux;
    }

    printf ("Sorted Array: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i].key);

}





