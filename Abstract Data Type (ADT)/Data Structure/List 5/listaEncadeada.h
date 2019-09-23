#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota;
}Student; 

typedef struct element *List;

List *createList();

int freeList(List *li);

int insertAtBeginning(List *li, Student student);

int printList(List *li);

int mergeLists(List *l1, List *l2, List *li);

int copyList(List *l1, List *l2);

int reverseList(List *l1, List *l2);

int isSort(List *l1);

int sizeOfList(List *l1);

#endif