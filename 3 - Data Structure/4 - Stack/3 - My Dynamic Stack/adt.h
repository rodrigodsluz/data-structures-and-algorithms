#ifndef _QUEUE_
#define _QUEUE_

typedef struct student{
    char name[30];
    int grade;
    int registration;;
}Student;

typedef struct element *Stack;

Stack *createStack();

int freeStack(Stack *st);

int stackUp(Stack *st, Student stud);


#endif