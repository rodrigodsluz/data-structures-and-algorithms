#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main(){
    int data, ok;

    List *li = createList();
    /*
    if(li != NULL){
        printf("\n Linked list created successfully!");
    }else{
        printf("\n Error!");
    }
    */

    printf("Enter the value: ");
    scanf("%d", &data);


    int n = 5;
    for(int i=0; i<n; i++){
    
    li = insertAtBeginning(li, i);
    }
    ok = printList(li);

    return 0;
}