#ifndef _MERGE_SORT_
#define _MERGE_SORT_

typedef struct itemType{
    int key;
    char name[100];
}itemType;

void mergeSort(int *A, int left, int right);

#endif