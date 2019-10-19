#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#define MAX 100

typedef struct stack{
    int amount;
    Student student[MAX];
};


Stack *createStack(){
    Stack *st = (Stack*)malloc(sizeof(Stack));

    if(st != NULL)
        *st = NULL;
    return st;
}

int freeQueue(Queue *qu){
    if(qu != NULL){
        Element *node;
        while(qu->head != NULL){
            node = qu->head;
            qu->head = qu->head->next;
            free(node);
        }
        free(qu);
    }
    return 1;
}

int insertInTheQueue(Queue *qu, Student stud){
    if(qu == NULL)
        return 0;

    Element *node = (Element*) malloc(sizeof(Element));

    if(node == NULL)
        return 0;

    node->student = stud;

    node->next = NULL;

    if(qu->tail == NULL)//empty queue
        qu->head = node;
    else
        qu->tail->next = node;

    qu->tail = node;

    qu->amount++;

    return 1;
}