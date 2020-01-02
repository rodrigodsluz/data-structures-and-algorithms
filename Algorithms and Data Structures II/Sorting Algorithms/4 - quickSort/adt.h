#ifndef _QUICK_SORT_
#define _QUICK_SORT_

typedef struct itemType{
    int key;
    char name[100];
}itemType;

void quickSort(itemType *A, int n);

#endif