#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

struct student{
    int ID;
    char name[30];  
    char course[30];
};

struct node{
  Student *student;
  struct node *next;
};

typedef struct node Temp;
typedef Temp *Node;

Node *createNode(){
    Node *head = (Node*) malloc(sizeof(Node));  

    if(head != NULL){
        *head = NULL;
    }else{
        return NULL;
    }  

    return head;
}

int freeNode(Node *head)
{
    if(head == NULL){
        return 0;    
    } 

    if((*head) != NULL){
        Temp *no, *help;
        no = *head;

    while( no->next !=  (*head) ){
        help = no;
        no = no-> next;
        free(help);
    }

    free(no);

    free(head);   
  }

    return 1;
}

int registration(Student **student){  
    *student = (Student*) malloc(sizeof(student));  

    printf("\n Código: ");
    scanf("%d", &(*produto)->codigo);

    printf(" Descrição: ");
    scanf(" %[^\n]", &(*produto)->descricao);

    printf(" Preço: ");
    scanf("%f", &(*produto)->preco);

    printf(" Quantidade: ");
    scanf("%d", &(*produto)->qtd);

    return 1;
}