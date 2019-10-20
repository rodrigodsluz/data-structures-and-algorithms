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

int printQueue(Queue *qu){
    if(qu == NULL)
        return 0;

    Element* node = qu->head;
    while(node != NULL){
        printf("Registration: %d\n",node->student.registration);
        printf("Name: %s\n",node->student.name);
        printf("Grade: %d\n",node->student.grade);
        printf("-------------------------------\n");
        node = node->next;
    }

    return 1;
}

int dequeue(Queue *qu){
    if(qu == NULL)
        return 0;

    if(qu->head == NULL)//empty queue
        return 0;

    Element *node = qu->head;
    qu->head = qu->head->next;
    if(qu->head == NULL)//queue became empty
        qu->tail = NULL;
    free(node);
    qu->amount--;


    return 1;
}

int consultFirstElement(Queue *qu, Student *stud){
    if(qu == NULL)
        return 0;

    if(qu->head == NULL)//empty queue
        return 0;

    *stud = qu->head->student;
    return 1;
}