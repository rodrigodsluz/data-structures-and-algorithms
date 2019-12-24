#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main (int argc, char *argv[])
{
    itemType *A;
    int n = 10, i;

    A = calloc(sizeof(itemType), n);
    printf("\nUnsorted Array: \n");
    for (i=0; i<n; i++){
        A[i].key = rand() % 100;
        printf (" %d",A[i].key);
    }

    printf("\n\n"); 

    //getchar(); //system("pause");

    insertionSort(A, n);

    printf("\n\n");

    //getchar(); //system("pause");
    
    return 0;
}
