#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

/*
Time complexity

Worst case:
O(n²)

average case:
O(n log n)

Best Case:
O(n log n)


*/

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

    quickSort(A, n);

    printf ("Sorted array: \n");
    for (i=1; i<=n; i++)
        printf (" %d",A[i].key);

    printf("\n\n");

    //getchar(); //system("pause");
    
    return 0;
}