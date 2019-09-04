#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

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

int insertAtBeginning(List *li, int x){
    if(li==NULL)
        return 0;
    
    if(li->amount == MAX)
        return 0;

    for(int i=li->amount-1; i>=0; i--)
        li->array[i+1] = li->array[i];

    li->array[0] = x;
    li->amount++;

    return 1;
}

void printList(List *li){
    if(li == NULL)
        return;

    printf("The values are: ");
    for(int i=0; i<li->amount; i++){
        printf("%d ",li->array[i]);
    }       
}

void freeList(List *li){
    free(li);
}