#include <stdio.h>
#include <stdlib.h>
#include "staticList.h"
#define MAX 100

struct list{
    Student student[MAX];
    int amount;
};

List *createList(){
    List *li = (List*)malloc(sizeof(List));

    if(li == NULL){
        return 0;
    }

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

int printList(List *li){
    if(li == NULL){
        return 0;
    }

    if(li->amount == 0){
        printf("The list is empty!!!\n\n");
    }

    for(int i=0; i<li->amount; i++){
        printf("%s\n", li->student[i].name);
        printf("%.2lf\n", li->student[i].grade);
        printf("%d\n\n", li->student[i].registerNumber);
    }

    return 1;
}

int insertAtBeginning(List *li, Student stud){
    if(li == NULL){
        return 0;
    }

    if(li->amount == MAX){
        return 0;
    }

    for(int i = li->amount-1; i >= 0; i--){
        li->student[i+1] = li->student[i];
    }

    li->student[0] = stud;
    li->amount++;

    return 1;
}

int insertAtEnd(List *li, Student stud){
    if(li == NULL){
        return 0;
    }

    if(li->amount == MAX){
        return 0;
    }

    li->student[li->amount] = stud;
    li->amount++;

    return 1;
}

int insertIncreasingOrder(List *li, Student stud){
    if(li == NULL){
        return 0;
    }

    if(li->amount == MAX){
        return 0;
    }

    int j=0;
    while(j < li->amount && li->student[j].registerNumber < stud.registerNumber){
        j++;
    }

    for(int i=li->amount-1; i>=j; i--){
        li->student[i+1] = li->student[i];
    }

    li->student[j] = stud;

    li->amount++;
    return 1;
}

int deleteAtBeginning(List *li){
    if(li == NULL){
        return 0;
    }

    if(li->amount == 0){
        return 0;
    }

    for(int i=0; i<li->amount-1; i++){
        li->student[i] = li->student[i+1];
    }

    li->amount--;
    return 1;
}

int deleteAtEnd(List *li){
    if(li == NULL){
        return 0;
    }

    if(li->amount == 0){
        return 0;
    }

    li->amount--;

    return 1;
}

int deleteAnyValue(List *li, int p){
    if(li == NULL){
        return 0;
    }

    if(li->amount == 0){
        return 0;
    }

    int j=0;
    while(j < li->amount && li->student[j].registerNumber != p){
        j++;
    }

    if(j == li->amount){
        return 0;
    }

    for(int i=j; i<li->amount-1; i++){
        li->student[i] = li->student[i+1];
    }

    li->amount--;

    return 1;
}

int searchValueByPosition(List *li, int p, int *v){
    if(li ==  NULL || li->amount == 0){
        return 0;
    }
/*
    if(p<0 || p>=li->amount){
        printf("This position doesn't exist!!!\n\n");
        return 0;
    }

    *v = li->student[p].registerNumber;
*/

    //Ignoring the 0th position
    if(p<=0 || p>li->amount){
        printf("This position doesn't exist!!!\n\n");
        return 0;
    }

    *v = li->student[p-1].registerNumber;

    return 1;
}

int searchPositionByValue(List *li, int v, int *p){
    if(li == NULL){
        return 0;
    }

    if(li->amount == 0){
        return 0;
    }

    int j=0;
    while(j < li->amount && li->student[j].registerNumber != v){
        j++;
    }

    if(j == li->amount == MAX){
        return 0;
    }

    *p = j;

    return 1;
}