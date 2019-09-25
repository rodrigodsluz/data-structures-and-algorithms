#ifndef _STATIC_LIST_
#define _STATIC_LIST_

typedef struct student{
    char name[30];
    double grade;
    int registerNumber;
}Student;

typedef struct list List;

List *createList();

int freeList(List *li);

int printList(List *li);

int insertAtBeginning(List *li, Student stud);

int insertAtEnd(List *li, Student stud);

int insertIncreasingOrder(List *li, Student stud);

#endif