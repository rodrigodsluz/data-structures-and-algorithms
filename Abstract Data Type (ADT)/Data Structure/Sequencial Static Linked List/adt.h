#ifndef _STATIC_LIST
#define _STATIC_LIST

typedef struct list List;

List *createList();

int freeList(List *li);

int listSize(List *li);

int listIsEmpty(List *li);

int listIsFull(List *li);

int printList(List *li);

int insertAtBeginning(List *li, int data);

int insertAtEnd(List *li, int data);

int insertSortedList(List *li, int data);

int deleteFromBeginning(List *li);

int deletionFromEnd(List *li);

int deleteNthPosition(List *li, int data);

int searchElementByPosition(List *li, int pos, int *data);

int searchElementByValue(List *li, int data, int *pos);

#endif