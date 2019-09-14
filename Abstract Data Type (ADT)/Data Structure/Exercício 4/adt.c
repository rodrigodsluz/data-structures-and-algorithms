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
    

   /*
    if(li != NULL){
        *li = NULL;
    }else{
        return NULL;
    }  

    return li;
    */
}



int freeList(List *li){
    if(li==NULL){
        return 0;
    }

    free(li);

    return 1;
}
/*
Produto *insertProduct(){
    Produto *prod = (Produto*)malloc(sizeof(Produto));

    if(prod==NULL){
        return 0;
    }
    printf("Type the product code: ");
    scanf("%d", &(*prod)->codigo);
    printf("Type the product name ");
    scanf(" %[^\n]", &(*prod)->nome);
    printf("Type the product price: ");
    scanf("%f", &(*prod)->preco);
    printf("Type the product amount: ");
    scanf("%d", &(*prod)->qtd);

    return prod;
    //return 1;
}
*/
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
/*
void printProduct(Produto *prod){
    if(prod==NULL){
        return ;
    }
    printf("%d\n", prod->codigo);
    printf("%s\n", prod->nome);
    printf("%.2f\n", prod->preco);
    printf("%d\n", prod->qtd);


   // return 1;
}
*/

int printList(List *li, int cont){
    
    if(li == NULL)
        return 0;

    /*
    if(li->amount < 0 ){
        return 0;
    }else{
        printf("Code: %d\n",li->product[li->amount].codigo);
        printf("Name: %s\n",li->product[li->amount].nome);
        printf("Price: %.2f\n",li->product[li->amount].preco);
        printf("Amount: %d\n\n", li->product[li->amount].qtd); 

        printList(li, li->amount--);
    }
    */
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

    

    /*
    for(int i=0; i< li->amount; i++){
        printf("Code: %d\n",li->product[i].codigo);
        printf("Name: %s\n",li->product[i].nome);
        printf("Price: %.2f\n",li->product[i].preco);
        printf("Amount: %d\n\n", li->product[i].qtd);                                    
    }
    */

    return 1;
}

Produto searchCheaperProduct(List *li){

    Produto temp;
    float cheaper = li->product[0].preco;
    int i=0;
    for(i=0; i<li->amount; i++){
        if(li->product[i].preco < cheaper ){
            //cheaper = li->product[i].preco;
            temp = li->product[i];
        }else{
            temp = li->product[0];
        }
    }
    //temp = li->product[i];
    return temp;
}