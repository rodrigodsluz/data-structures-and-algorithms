#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

typedef struct element{
    Student student;
    struct element *next;
}Element;

struct queue{
    struct element *head;
    struct element *tail;
    int amount;
};

Queue *createQueue(){
    Queue *qu = (Queue*)malloc(sizeof(Queue));

    if(qu != NULL){
        qu->head = NULL;
        qu->tail = NULL;
        qu->amount = 0;
    }

    return qu;
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