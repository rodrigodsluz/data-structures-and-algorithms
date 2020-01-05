#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

void remake(int left, int right, itemType *A)
{
  int i = left;
  int j; itemType x;
  j = i * 2;
  x = A[i];
  while (j <= right){
    if (j < right)
      if (A[j].key < A[j+1].key) j++;
    if (x.key >= A[j].key) break;
    A[i] = A[j];
    i = j;
    j = i*2;  
  }
  A[i] = x;
}

void build(itemType *A, int n)
{
  int left;
  left = n / 2 + 1;
  while (left > 1){
    left--;
    remake(left, n, A);
  }
}

void heapSort(itemType *A, int n)
{
    int left2, right2;
    itemType x;

    build(A, n);
    left2 = 1;
    right2 = n;
    while(right2 > 1){
        x = A[1];
        A[1] = A[right2];
        A[right2] = x;
        right2--;
        remake(left2, right2, A);
    }
}