#ifndef _INSERTION_SORT_
#define _INSERTION_SORT_

typedef struct TipoItem{
    int Chave;
    char name[100];
} TipoItem;

void insertionSort (TipoItem *A, int n);



#endif