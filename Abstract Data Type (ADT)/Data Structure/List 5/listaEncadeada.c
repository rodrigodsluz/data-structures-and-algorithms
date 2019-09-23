#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct element{ 
    Student student;
    struct element *next;
}Element;

List *createList(){
    List* li = (List*) malloc(sizeof(List));
    if(li != NULL)
        *li = NULL;
    return li;
}

int freeList(List *li){
    if(li!=NULL){
        Element *node;
        while((*li)!=NULL){
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        free(li);
        return 1;
    }

    return 0;
}
int insertAtBeginning(List *li, Student student){

    if(li == NULL)
        return 0;

    Element *node = (Element*) malloc(sizeof(Element));

    if(node == NULL)
        return 0;

    node->student = student;
    node->next = (*li);
    *li = node;

    return 1;
    
}

int printList(List *li){
    if(li == NULL)
        return 0;

    if(*li == NULL){
        printf("Empty list\n\n");
    }

    Element *node = *li;
    while(node != NULL){
        printf("-------------------\n\n");

        printf("Registration number: %d\n", node->student.matricula);
        printf("Name: %s\n", node->student.nome);
        printf("Note: %.2f\n\n", node->student.nota);

        
        node = node->next;
    }

    return 1;
}

int mergeLists(List *l1, List *l2, List *li){
    if(l1 == NULL|| l2 == NULL||  li == NULL ){
        return 0;
    }

    Element *node = *l1;

    while(node->next!=NULL){
        node = node->next;
    }

    node->next = *l2;
    *li = node;

    return 1;
}

int copyList(List *l1, List *l2){
    if(l1 == NULL || l2 == NULL){
        return 0;
    }

    /*Dada uma lista L1, crie e retorne uma cópia dela em L2 eliminando os valores repetidos
(matrícula do aluno)*/

    Element *anterior, *corrente, *seguinte;

    for(corrente = *l1; corrente != NULL; corrente = corrente -> next){
        anterior = NULL;

        for(seguinte = corrente -> next; seguinte != NULL; ){
            if(corrente -> student.matricula == seguinte -> student.matricula){
                if(anterior == NULL)
                    corrente -> next = seguinte -> next;
                else
                    anterior -> next = seguinte -> next;

                Element* remover = seguinte;
                seguinte = seguinte -> next;
                free(remover);
            }else {
                anterior = seguinte;
                seguinte = seguinte->next;
            }
        }
    }

     *l2 = *l1;


    return 1;
}

int reverseList(List *l1, List *l2){
    if(l1 == NULL || l2 == NULL || *l1 == NULL){
        return 0;
    }

    /*Dada uma lista L1, inverta a lista e armazene em L2. A função deve retornar a lista L2.*/

    Element *prev, *current, *next;
	current = *l1;
	prev = NULL;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*l1 = prev;
    *l2 = *l1;

    return 1;
}

int isSort(List *l1){
    /*Verique se a lista está ordenada ou não (crescente ou decrescente), de acordo com a
matrícula do aluno.*/
    if(l1==NULL || *l1 == NULL){
        return 0;
    }

    
    Element *node = *l1;
    while (node->next != NULL){
        if (node->student.matricula > node->next->student.matricula)
            return 0;
        node = node->next;
    }
    

    return 1;
}

int sizeOfList(List *l1){
    
    if(l1==NULL){
        return 0;
    }

    /*Calcule e retorne o tamanho da lista dinâmica encadeada. A função deve ser recursiva.*/
   /* int size=0;
    Element *node = *l1;

    if(node->next==NULL){
        return 0;
    }else{
        while(node!=NULL){
            size = sizeOfList(node->next);
        }
    }*/

    int size = 0;
    int aux = 0;
    int cont = 0;
    Element *node = *l1;

    if((*l1)==NULL){
        return 0;
    }else{
        while((*l1)!=NULL){
            aux++;
            (*l1) = (*l1)->next;
            cont = sizeOfList(l1);      
            size = cont + aux;
        }
    }
    

    return size;
}
