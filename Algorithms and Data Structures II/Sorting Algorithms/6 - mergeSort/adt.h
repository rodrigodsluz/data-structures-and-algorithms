#ifndef _HEAP_SORT_
#define _HEAP_SORT_

typedef struct itemType{
    int key;
    char name[100];
}itemType;

void heapSort(itemType *A, int n);

#endif