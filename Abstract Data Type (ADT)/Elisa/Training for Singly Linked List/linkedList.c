#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef struct element{
    Student student;
    struct element *next;
}Element;

List *createList(){
    List *li = (List*)malloc(sizeof(List));

    if(li == NULL){
        return 0;
    }

    (*li) = NULL;

    return li;
}

int freeList(List *li){
    if(li == NULL){
        return 0;
    }

    Element *node;

    while((*li)!=NULL){
        node = (*li);
        (*li) = (*li)->next;
        free(node);
    }

    free(li);

    return 1;
}

int printList(List *li){
    if(li == NULL){
        return 0;
    }

    if(*li == NULL){
        printf("The list is empty!!!\n\n");
    }

    Element *node = *li;

    while(node!=NULL){
        printf("%s\n", node->student.name);
        printf("%.2lf\n", node->student.grade);
        printf("%d\n\n", node->student.registerNumber);
        node = node->next;
    }

    return 1;
}

int insertAtBeginning(List *li, Student stud){
    if(li == NULL){
        return 0;
    }

    Element *node = (Element*)malloc(sizeof(Element));

    if(node == NULL){
        return 0;
    }

    node->student = stud;
    node->next = *li;

    *li = node;



    return 1;
}

int insertAtEnd(List *li, Student stud){
    if(li == NULL){
        return 0;
    }

    Element *node = (Element*)malloc(sizeof(Element));

    if(node == NULL){
        return 0;
    }

    node->student = stud;
    node->next = NULL;

    Element *temp;

    if(*li == NULL){ 
        *li = node;
    }else{
        temp = *li;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
    }

    return 1;
}

int insertIncreasingOrder(List *li, Student stud){
    if(li == NULL){
        return 0;
    }

    Element *node = (Element*)malloc(sizeof(Element));
    if(node == NULL){
        return 0;
    }

    node->student = stud;

    if(*li == NULL){
        node->next = NULL;
        *li = node;
    }else{
        Element *prev, *current;
        current = *li;
        while(current != NULL && current->student.registerNumber < stud.registerNumber){
                prev = current;
                current = current->next;
        }

        if(current == *li){
            node->next = *li;
            *li = node;
        }else{
            node->next = current;
            prev->next = node;
        }
        
    }
    return 1;
}

int deleteAtBeginning(List *li){
    if(li == NULL){
        return 0;
    }

    if(*li == NULL){
        return 0;
    }

    Element *temp = *li;
    *li = (*li)->next;

    free(temp);

    return 1;
}

int deleteAtEnd(List *li){
    if(li == NULL){
        return 0;
    }

    if(*li == NULL){
        return 0;
    }

    /*
    Element *temp = *li;

    while(temp->next != NULL){
        temp = temp->next;
    }

    if(temp == *li){
        *li = (*li)->next;
        free(temp);
    }else{
        Element *prev = *li;;
        while(prev->next != temp){
            prev = prev->next;
        }
        prev->next = NULL;
        free(temp);
    }
    */

    //Another way

    

    return 1;
}

int deleteAnyValue(List *li, int p){
    if(li == NULL){
        return 0;
    }

    if(*li == NULL){
        return 0;
    }


    Element *temp = *li;
    Element *prev;

    
    while(temp != NULL && temp->student.registerNumber != p){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return 0;
    }

    if(temp == *li){
        *li = (*li)->next;
    }else{
        prev->next = temp->next;
    }

    free(temp);

    return 1;
}