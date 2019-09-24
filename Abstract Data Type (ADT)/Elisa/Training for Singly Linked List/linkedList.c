#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef struct element{
    Student student;
    struct element *next;
}Element;

List *createList(){
    List *li = (List*)malloc(sizeof(List));

    if(li == NULL){
        return 0;
    }

    (*li) = NULL;

    return li;
}

int freeList(List *li){
    if(li == NULL){
        return 0;
    }

    Element *node;

    while((*li)!=NULL){
        node = (*li);
        (*li) = (*li)->next;
        free(node);
    }

    free(li);

    return 1;
}

int printList(List *li){
    if(li == NULL){
        return 0;
    }

    if(*li == NULL){
        printf("The list is empty!!!\n");
    }

    Element *node = *li;

    while(node!=NULL){
        printf("%s\n", node->student.name);
        printf("%.2lf\n", node->student.grade);
        printf("%d\n", node->student.registerNumber);
        node = node->next;
    }

    return 1;
}