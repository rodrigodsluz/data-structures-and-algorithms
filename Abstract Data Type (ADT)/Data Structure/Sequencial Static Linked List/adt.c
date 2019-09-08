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

int insertAtEnd(List *li, int data){
    if(li==NULL){
        return 0;
    }

    if(listIsFull(li)){
        return 0;
    }

    li->array[li->amount] = data;
    li->amount++;

    return 1;
}

int insertSortedList(List *li, int data){
    if(li == NULL){
        return 0;
    }

    if(listIsFull(li)){
        return 0;
    }

    li->array[li->amount] = data;
    li->amount++;

    int temp = 0 ;
    for(int i=0; i<li->amount; i++){
        for(int j=i+1; j<li->amount; j++){
            if(li->array[j] < li->array[i]){
                temp = li->array[i];
                li->array[i] = li->array[j];
                li->array[j] = temp;
            }
        }
    }

    return 1;
}

int deleteFromBeginning(List *li){
    if(li == NULL){
        return 0;
    }

    if(listIsEmpty(li)){
        return 0;
    }

    for(int i=0; i< li->amount; i++){   //You have to decide
        li->array[i-1] = li->array[i]; 
    }

    for(int i=0; i< li->amount-1; i++){
        i->dados[i] = li->dados[i+1];
    }

    li->amount--;

    return 1;
}

