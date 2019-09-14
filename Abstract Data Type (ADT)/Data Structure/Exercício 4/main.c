#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int createProduct(Produto *prod);

int main(){
    List *li;
    Produto prod;
    int choice=0, ok=0;
    
    do{
        printf("1 - Create list\n");
        printf("2 - Free list\n");
        printf("3 - Add new product\n");
        printf("4 - Print List\n");
        printf("5 - Exit\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
        case 1:
            
            li = createList();

            if(li!=NULL){
                printf("List created successfully\n\n");
            }else{
                printf("Error");
            }

            break;
        
        case 2:
            ok = freeList(li);

            if(ok){
                printf("List desallocated successfully\n");
            }else{
                printf("Error");
            }
            break;

        case 3:
            ok = createProduct(&prod);
            ok = insertAtBeginning(li, prod);

            if(ok){
                printf("Successful insertion\n\n");
            }else{
                printf("Error");
            }

            break;

        case 4:
        {
            int cont = 0;
            ok = printList(li, cont);

            if(ok == 0){
                printf("List doesn't exist\n");
            }
            

            break;
        }
        default:

            break;
        }
        
    }while(choice!=5);

    return 0;
}

int createProduct(Produto *prod){
    /*
    *prod = (Produto*)malloc(sizeof(Produto));

    if(*prod==NULL){
        return 0;
    }
    */

    printf("Type the product code: ");
    scanf("%d", &(prod)->codigo);
    printf("Type the product name ");
    scanf(" %[^\n]", &(prod)->nome);
    printf("Type the product price: ");
    scanf("%f", &(prod)->preco);
    printf("Type the product amount: ");
    scanf("%d", &(prod)->qtd);
    printf("\n");

    return 1;
}