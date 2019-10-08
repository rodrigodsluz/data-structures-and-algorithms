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
        *qu = NULL;
    }

    return qu;
}