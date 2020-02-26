#ifndef _SELECTION_SORT_
#define _SELECTION_SORT_

typedef struct itemType{
    int key;
    char name[100];
}itemType;

void selectionSort (itemType *A, int n);

#endif