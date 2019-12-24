#ifndef _INSERTION_SORT_
#define _INSERTION_SORT_

typedef struct itemType{
    int key;
    char name[100];
}itemType;

void insertionSort (itemType *A, int n);

#endif