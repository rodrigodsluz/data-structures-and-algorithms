#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

/*
Time complexity

Worst case: 
O(n²)

average case:


Best Case:
O(n)


*/

int main (int argc, char *argv[])
{
    itemType *A;
    int n = 10, i;

    //Why the professor put 2*n?
    A = calloc(sizeof(itemType), 2*n); //+1 para a sentinela em P[0]
    printf("\nUnsorted Array: \n");
    for (i=1; i<=n; i++){
        A[i].key = rand() % 100;
        printf (" %d",A[i].key);
    }

    printf("\n\n"); 

    //getchar(); //system("pause");

    heapSort(A, n);

    printf ("Sorted array: \n");
    for (i=1; i<=n; i++)
        printf (" %d",A[i].key);

    printf("\n\n");

    //getchar(); //system("pause");
    
    return 0;
}