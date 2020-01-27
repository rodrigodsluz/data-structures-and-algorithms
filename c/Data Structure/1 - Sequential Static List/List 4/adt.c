#include <stdio.h>
#include <stdlib.h>
#include "adt.h"
#define MAX 100

struct list{
    Produto product[MAX];
    int amount;
};

List *createList(){
    List *li = (List*)malloc(sizeof(List));

    if(li!=NULL){
        li->amount = 0;
        return li;
    }
    
}

int freeList(List *li){
    if(li==NULL){
        return 0;
    }

    free(li);

    return 1;
}

int insertAtBeginning(List *li, Produto prod){
    if(li==NULL||li->amount == MAX){
        return 0;
    }

    for(int i=li->amount-1; i>=0; i--){
        li->product[i+1] = li->product[i];
    }

    li->product[0] = prod;
    li->amount++;

    return 1;
}

int printList(List *li, int cont){
    
    if(li == NULL)
        return 0;

   printf("-----------------------------\n\n");

   if(cont == li->amount){
       return 0;
   }else{
        printf("Code: %d\n",li->product[cont].codigo);
        printf("Name: %s\n",li->product[cont].nome);
        printf("Price: %.2f\n",li->product[cont].preco);
        printf("Amount: %d\n\n", li->product[cont].qtd); 

        cont++;

        printList(li, cont);
   }

    return 1;
}

int searchCheaperProduct(List *li, Produto *cheaper){
    if(li == NULL || li->amount == 0){
        return 0;
    }

    (*cheaper) = li->product[0];

    for(int i=0; i<li->amount; i++){
        if(li->product[i].preco < (*cheaper).preco ){
            *cheaper = li->product[i];
        }
    }
  
    return 1;
}

int deleteNthElement(List *li, int n){
    if(li==NULL || li->amount == 0 || n<0 || n>li->amount){
       return 0; 
    }

    while(n--){
        li->amount--;
    }     

    return 1;
}

int swapByPosition(List *li, int p1, int p2){
    if(li==NULL || li->amount == 0 || p1 < 0 || p2 < 0 || p1 > li->amount-1 || p2 > li->amount-1){
        return 0;
    }

            //Just testing
            printf("Before swap\n");
            printf("p1:\n");
            printf("Code: %d\n",li->product[p1].codigo);
            printf("Name: %s\n",li->product[p1].nome);
            printf("Price: %.2f\n",li->product[p1].preco);
            printf("Amount: %d\n\n", li->product[p1].qtd);

            printf("p2:\n");
            printf("Code: %d\n",li->product[p2].codigo);
            printf("Name: %s\n",li->product[p2].nome);
            printf("Price: %.2f\n",li->product[p2].preco);
            printf("Amount: %d\n\n", li->product[p2].qtd);

    Produto temp = li->product[p1];
    li->product[p1] = li->product[p2];
    li->product[p2] = temp;

            //Just testing
            printf("After swap\n");
            printf("p1:\n");
            printf("Code: %d\n",li->product[p1].codigo);
            printf("Name: %s\n",li->product[p1].nome);
            printf("Price: %.2f\n",li->product[p1].preco);
            printf("Amount: %d\n\n", li->product[p1].qtd);

            printf("p2:\n");
            printf("Code: %d\n",li->product[p2].codigo);
            printf("Name: %s\n",li->product[p2].nome);
            printf("Price: %.2f\n",li->product[p2].preco);
            printf("Amount: %d\n\n", li->product[p2].qtd);

    return 1;
}