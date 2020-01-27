#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

typedef struct element{
    Student student;
    struct element *next;
}Element;


Stack *createStack(){
    Stack *st = (Stack*)malloc(sizeof(Stack));

    if(st != NULL)
        *st = NULL;
    return st;
}

int freeStack(Stack *st){
    if(st != NULL){
        Element* node;
        while((*st) != NULL){
            node = *st;
            *st = (*st)->next;
            free(st);
        }
        free(st);
    }
}

int stackUp(Stack *st, Student stud){
    if(st == NULL)
        return 0;
    Element* node;
    node = (Element*) malloc(sizeof(Element));
    if(node == NULL)
        return 0;
    node->student = stud;
    node->next = (*st);
    *st = node;
    return 1;
}