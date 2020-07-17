#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

void selectionSort (itemType *A, int n){
    int i, j, min;
    itemType aux;

    for (i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++)
            if (A[j].key < A[min].key)
                min = j;

        aux = A[min];
        A[min] = A[i];
        A[i] = aux;
    }

    printf ("Sorted Array: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i].key);

}


