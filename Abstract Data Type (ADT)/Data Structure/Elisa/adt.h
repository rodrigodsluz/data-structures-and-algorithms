#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct element *List;

List *createList();

int freeList(List *li);

int insertAtBeginning(List *li, int data);

int printList(List *li);

#endif