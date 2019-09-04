#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main(){
    int ok, pos, dado;

    Node *head;
    Student *student; 

    head = createNode();

    if(head != NULL){
        printf("\n Linked list created successfully!");
    }else{
        printf("\n Error!");
    }

    ok = registration(&student); 

    ok = insertAtBeginning(li, produto);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

    //ok = freeNode(head);
    /*
    if(free){
        printf("\n Linked list successfully deallocated!");
    }else{
        printf("\n Error!");
    }
    */

    return 0;
}