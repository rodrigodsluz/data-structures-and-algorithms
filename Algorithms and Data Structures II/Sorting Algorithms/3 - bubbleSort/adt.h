#ifndef _BUBBLE_SORT_
#define _BUBBLE_SORT_

typedef struct itemType{
    int key;
    char name[100];
}itemType;

void bubbleSort (itemType *A, int n);

#endif