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
    int *A;
    int n=10, i;

    A = (int*) malloc(n*sizeof(int));
    printf("\nUnsorted Array: \n");
    for (i=0; i<n; i++){
        A[i] = rand() % 100;
        printf (" %d",A[i]);
    }

    printf("\n\n"); 

    //getchar(); //system("pause");

    mergeSort(A, 0, n-1);

    printf ("Sorted array: \n");
    for (i=0; i<n; i++)
        printf (" %d",A[i]);

    printf("\n\n"); 

    //getchar(); //system("pause")

    return 0;
}