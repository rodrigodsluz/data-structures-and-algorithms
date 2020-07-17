#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#define MAX 100

struct list{
    int array[MAX];
    int amount;
};

List* createList(){
    List *li = (List*) malloc(sizeof(List));
    if(li != NULL)
        li->amount = 0;
    return li;
}

int freeList(List *li){
    if(li == NULL){
        return 0;
    }

    free(li);

    return 1;
   
}

int listSize(List *li){
    if(li==NULL){
        return -1;
    }else{
        return li->amount;
    }
}

int listIsEmpty(List *li){
    if(li == NULL){
        return -1;
    }

    if(li->amount == 0){
        return 1;
    }

    return 0;
}

int listIsFull(List *li){
    if(li==NULL){
        return -1;
    }

    if(li->amount == MAX){
        return 1;
    }

    return 0;
}

int printList(List *li){
    if(li == NULL)
        return 0;

    for(int i=0; i<li->amount; i++){
        printf("%d ",li->array[i]);
    }      
}

int insertAtBeginning(List *li, int data){
    if(li==NULL)
        return 0;
   
    if(listIsFull(li))
        return 0;

    for(int i=li->amount-1; i>=0; i--)
        li->array[i+1] = li->array[i];

    li->array[0] = data;
    li->amount++;

    return 1;
}

int insertAtEnd(List *li, int data){
    if(li==NULL){
        return 0;
    }

    if(listIsFull(li)){
        return 0;
    }

    li->array[li->amount] = data;
    li->amount++;

    return 1;
}

int insertSortedList(List *li, int data){
    if(li == NULL){
        return 0;
    }

    if(listIsFull(li)){
        return 0;
    }

    /*
    li->array[li->amount] = data;
    li->amount++;
    */

    int temp = 0 ;
    for(int i=0; i<li->amount; i++){
        for(int j=i+1; j<li->amount; j++){
            if(li->array[j] < li->array[i]){
                temp = li->array[i];
                li->array[i] = li->array[j];
                li->array[j] = temp;
            }
        }
    }
    

    int j = 0;
    while(j<li->amount && li->array[j] < data)
        j++;

    for(int i=li->amount-1; i >= j; i--)
        li->array[i+1] = li->array[i];

    li->array[j] = data;
    li->amount++;
    
    return 1;
}

int deleteFromBeginning(List *li){
    if(li == NULL){
        return 0;
    }

    if(listIsEmpty(li)){
        return 0;
    }

    for(int i=0; i< li->amount-1; i++){
        li->array[i] = li->array[i+1];
    }

    li->amount--;

    return 1;
}

int deletionFromEnd(List *li){
    if(li==NULL){
        return 0;
    }

    if(listIsEmpty(li)){
        return 0;
    }

   //Only this is enough
    li->amount--;

    return 1;
}

int deleteNthPosition(List *li, int data){
    if(li==NULL){
        return 0;
    }

    if(listIsEmpty(li)){
        return 0;
    }

    int j = 0;
    while(j<li->amount && li->array[j] != data)
        j++;

    if(j == li->amount)
        return 0;

    for(int i=j; i< li->amount-1; i++)
        li->array[i] = li->array[i+1];
    

    li->amount --;

    /*
    //Optimized
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    //
    */
   
    return 1;
}

int searchElementByPosition(List *li, int pos, int *data){
    if(li==NULL|| listIsEmpty(li) || pos < 0 ||  pos > li->amount-1){
        return 0;
    }

    *data = li->array[pos];

    return 1;

}

int searchElementByValue(List *li, int data, int *pos){
    if(li==NULL|| listIsEmpty(li)){
        return 0;
    }

    int j=0;
    while(j<li->amount && li->array[j] != data){
        j++;
    }

    if(j == li->amount){
        return 0;
    }

    *pos = j;

    return 1;
}