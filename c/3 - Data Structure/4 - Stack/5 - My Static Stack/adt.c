#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#define MAX 100

struct stack{
    int amount;
    Student student[MAX];
};


Stack *createStack(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    if(st != NULL)
        st->amount = 0;
    return st;
}

int freeStack(Stack *st){
    if(st == NULL){
        return 0;
    }

    free(st);

    return 1;
}

int stackUp(Stack *st, Student stud){
    if(st == NULL)
        return 0;

    if(st->amount == MAX)
        return 0;

    st->student[st->amount] = stud;
    st->amount++;

    return 1;
}