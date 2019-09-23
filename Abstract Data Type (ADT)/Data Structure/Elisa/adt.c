#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

typedef struct element{ 
    int data;
    struct element *next;
}Element;

List *createList(){
    List* li = (List*) malloc(sizeof(List));
    if(li != NULL)
        *li = NULL;
    return li;
}

int freeList(List *li){
    if(li!=NULL){
        Element *node;
        while((*li)!=NULL){
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        free(li);
        return 1;
    }

    return 0;
}
int insertAtBeginning(List *li, int data){

    if(li == NULL) //Robson
        return 0;

    Element *node = (Element*) malloc(sizeof(Element)); //João

    if(node == NULL) //Leal
        return 0;

    node->data = data;          //Rodrigo
    node->next = (*li);
    *li = node;             //Matheus

    return 1;
    
}

int printList(List *li){
    if(li == NULL)
        return 0;

    if(*li == NULL){
        printf("Empty list");
    }

    Element *node = *li;
    while(node != NULL){

        printf("%d ", node->data);

        
        node = node->next;
    }
    printf("\n\n");

    return 1;
}

