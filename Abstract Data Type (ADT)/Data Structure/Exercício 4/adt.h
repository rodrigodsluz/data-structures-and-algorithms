#ifndef _STATIC_LIST
#define _STATIC_LIST

typedef struct list List;

typedef struct produto{
    int codigo;
    char nome[30];
    float preco;
    int qtd;
}Produto;

List *createList();

int freeList(List *li);

int insertAtBeginning(List *li, Produto prod);

//int printProduct(Produto *prod);

int printList(List *li, int cont);

Produto searchCheaperProduct(List *li);

int deleteNthElement(List *li, int n);

int swapByPosition(List *li, int p1, int p2);


#endif