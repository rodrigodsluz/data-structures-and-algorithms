#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

void Refaz(int left, int right, itemType *A)
{
  int i = left;
  int j; itemType x;
  j = i * 2;
  x = A[i];
  while (j <= right){
    if (j < right)
      if (A[j].Chave < A[j+1].Chave) j++;
    if (x.Chave >= A[j].Chave) break;
    A[i] = A[j];
    i = j;
    j = i*2;
  }
  A[i] = x;
}

void Constroi(itemType *A, int n)
{
  int left;
  left = n / 2 + 1;
  while (left > 1){
    left--;
    Refaz(left, n, A);
  }
}

void heapSort(itemType *A, int n)
{
    int esq, dir;
    itemType x;

    Constroi(A, n);
    esq = 1;
    dir = n;
    while(dir > 1){
        x = A[1];
        A[1] = A[dir];
        A[dir] = x;
        dir--;
        Refaz(esq, dir, A);
    }
}