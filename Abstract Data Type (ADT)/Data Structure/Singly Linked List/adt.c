#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

struct list{
    int d;
    struct list *next;
};

List *createList(){
    /*
    List *li = (List*)malloc(sizeof(List));

    if(li!=NULL){
        *li = NULL;
    }

    return li;

    */
   return NULL;
}

List * insertAtBeginning(List *li, int data){
    
    List *temp = (List*) malloc(sizeof(List));
    temp->d = data;
    temp->next = li;
    
    return temp;
}

int printList(List *li){
    
    while(li!=NULL){
        printf("%d ", li->d);
        li = li->next;
    }

    return 1;
}