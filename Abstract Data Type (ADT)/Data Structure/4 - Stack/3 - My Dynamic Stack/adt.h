#ifndef _QUEUE_
#define _QUEUE_

typedef struct student{
    char name[30];
    int grade;
    int registration;;
}Student;

typedef struct element *Stack;

Stack *createStack();

int freeQueue(Queue *qu);

int insertInTheQueue(Queue *qu, Student stud);


#endif