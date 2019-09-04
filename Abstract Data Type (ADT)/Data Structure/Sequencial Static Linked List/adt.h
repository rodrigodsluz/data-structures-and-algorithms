#define MAX 100

typedef struct list List;

List *createList();

void freeList(List *li);

int insertAtBeginning(List *li, int x);

void printList(List *li);