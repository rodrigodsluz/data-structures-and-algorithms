#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#define MAX 100

struct queue{
    int head, tail, amount;
    Student data[MAX];
};

Queue *createQueue(){
    Queue *qu = (Queue*) malloc(sizeof(Queue));
    if(qu != NULL){
        qu->head = 0;
        qu->tail = 0;
        qu->amount = 0;
    }
    return qu;
}

int freeQueue(Queue *qu){
    free(qu); 
}

int insertInTheQueue(Queue *qu, Student stud){
    if(qu == NULL)
        return 0;

    if(qu->amount = MAX)
        return 0;

    qu->data[qu->tail] = stud;
    qu->tail = (qu->tail+1)%MAX;
    qu->amount++;
    
    return 1;
}