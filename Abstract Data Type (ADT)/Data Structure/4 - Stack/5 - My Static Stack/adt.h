#ifndef _STACK_
#define _STACK_

typedef struct student{
    char name[30];
    int grade;
    int registration;;
}Student;

typedef struct stack Stack;

Stack *createStack();

int freeStack(Stack *st);

int stackUp(Stack *st, Student stud);


#endif