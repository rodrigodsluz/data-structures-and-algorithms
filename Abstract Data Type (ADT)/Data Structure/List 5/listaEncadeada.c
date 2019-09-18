#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

struct list{ //rename element
    Student student;
    struct list *next;
};

typedef struct list Elem; //fix

List *createList(){
    List* head = (List*) malloc(sizeof(List));
    if(head != NULL)
        *head = NULL;
    return head;

}
int insertAtBeginning(List *head, Student student){

    if(head == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->student = student;
    no->next = (*head);
    *head = no;
    return 1;
    
}

int printList(List *head){
    if(head == NULL)
        return 0;
    Elem* no = *head;
    while(no != NULL){
        printf("Registration number: %d\n", no->student.matricula);
        printf("Name: %s\n", no->student.nome);
        printf("Note: %.2f\n", no->student.nota);
        

        no = no->next;
    }

    return 1;
}