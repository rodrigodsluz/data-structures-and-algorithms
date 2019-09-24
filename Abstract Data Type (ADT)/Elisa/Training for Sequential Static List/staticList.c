#include <stdio.h>
#include <stdlib.h>
#include "staticList.h"
#define MAX 100

struct list{
    Student student[MAX];
    int amount;
}

List *createList(){
    List li = (List*)malloc(sizeof(List));

    if(li == NULL){
        return 0;
    }

    li->amount = 0;

    return li;
    
}
