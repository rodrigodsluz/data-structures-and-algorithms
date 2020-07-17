#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#define MAX 100

void merge(int *A, int left, int mid, int right)
{
    int aux[MAX];
    int i=left, j=mid+1, k=0;

    while(i<=mid && j<=right)
        if(A[i] <= A[j])
            aux[k++] = A[i++];
        else
            aux[k++] = A[j++];

    while(i <= mid)
        aux[k++] = A[i++];
    while(j <= right)
        aux[k++] = A[j++];

    for(i=left, k=0; i<=right; i++, k++)
        A[i] = aux[k];
}

void mergeSort(int *A, int left, int right)
{
    int mid = (left + right)/2;
    if(left < right){
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}