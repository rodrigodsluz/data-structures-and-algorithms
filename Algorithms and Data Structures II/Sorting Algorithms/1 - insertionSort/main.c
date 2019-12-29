#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

//Time complexity

/*Best-case:
    Sorted array: 1,2,3,4,5
    T(n) = (c1+c3)(n-1)
    T(n) = an + b

    O(n)
*/

/*Worst-case:
    Reverse sorted: 5, 4, 3, 2, 1
    T(n) = (c1 + c3)(n+1) + {1,2,3...n-1}c2
    T(n) = (c1 + c3)(n+1) + ((n(n-1))/2)c2
    T(n) = an² + bn + c

    O(n²)
*/

/*Average case for ith position, it will make i/2 shifts
and it will be O(n²) as well, and this insertin Sort is 
better than selection and bubble sort*/

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
