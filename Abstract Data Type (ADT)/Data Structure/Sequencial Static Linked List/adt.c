#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#define MAX 100

struct list{
    int array[MAX];
    int amount;
};

List* createList(){
    List *li = (List*) malloc(sizeof(List));
    if(li != NULL)
        li->amount = 0;
    return li;
}

int freeList(List *li){
    if(li == NULL){
        return 0;
    }

    free(li);

    return 1;
   
}

int listSize(List *li){
    if(li==NULL){
        return -1;
    }else{
        return li->amount;
    }
}

int listIsEmpty(List *li){
    if(li == NULL){
        return -1;
    }

    if(li->amount == 0){
        return 1;
    }

    return 0;
}

int listIsFull(List *li){
    if(li==NULL){
        return -1;
    }

    if(li->amount == MAX){
        return 1;
    }

    return 0;
}

int printList(List *li){
    if(li == NULL)
        return 0;

    for(int i=0; i<li->amount; i++){
        printf("%d ",li->array[i]);
    }      
}

int insertAtBeginning(List *li, int data){
    if(li==NULL)
        return 0;
   
    if(listIsFull(li))
        return 0;

    for(int i=li->amount-1; i>=0; i--)
        li->array[i+1] = li->array[i];

    li->array[0] = data;
    li->amount++;

    return 1;
}




