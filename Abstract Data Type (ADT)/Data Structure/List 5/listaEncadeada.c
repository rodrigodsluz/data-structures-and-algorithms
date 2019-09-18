#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct element{ 
    Student student;
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
int insertAtBeginning(List *li, Student student){

    if(li == NULL)
        return 0;

    Element *node = (Element*) malloc(sizeof(Element));

    if(node == NULL)
        return 0;

    node->student = student;
    node->next = (*li);
    *li = node;

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
        printf("-------------------\n\n");

        printf("Registration number: %d\n", node->student.matricula);
        printf("Name: %s\n", node->student.nome);
        printf("Note: %.2f\n\n", node->student.nota);

        
        node = node->next;
    }

    return 1;
}

int mergeLists(List *l1, List *l2, List *li){
    if(l1 == NULL|| l2 == NULL||  li == NULL ){
        return 0;
    }

    Element *node = *l1;

    while((*l1)!=NULL){
        *l1 = (*l1)->next;
    }
    *l1 = *l2;
    *li = *l1;

    return 1;
}