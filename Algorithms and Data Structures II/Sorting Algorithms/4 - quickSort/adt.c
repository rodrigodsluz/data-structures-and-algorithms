#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

void partition(int left, int right, int *i, int *j, itemType *A){
    itemType x, w;
    *i = left;
    *j = right;
    x = A[(*i + *j)/2]; //get the pivot
    do{
        while(x.key > A[*i].key) (*i)++;
        while(x.key < A[*j].key) (*j)--;
        if(*i <= *j){
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++; (*j)--;
        }
    } while(*i < *j);
}

void sort (int left, int right, itemType *A)
{
    int i, j;
    partition(left, right, &i, &j, A);
    if(left < j) sort(left, j, A);
    if(i < right) sort(i, right, A);
}

void quickSort(itemType *A, int n)
{
    sort(0, n, A);
}
