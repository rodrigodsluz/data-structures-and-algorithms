#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

void bubbleSort (itemType *A, int n){
    int i, j, min;
    itemType aux;

    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1; j++) {
            if (A[j].key > A[j+1].key) {
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }

    printf ("Sorted Array: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i].key);

}


