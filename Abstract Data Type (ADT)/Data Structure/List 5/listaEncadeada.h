#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota;
}Student; 

typedef struct list *List;

List *createList();

int insertAtBeginning(List *head, Student student);

int printList(List *head);

#endif