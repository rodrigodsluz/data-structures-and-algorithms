#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int createProduct(Produto *prod);

int main(){
    List *li;
    Produto prod;
    int choice, ok;
    
    do{
        printf("1 - Create list\n");
        printf("2 - Free list\n");
        printf("3 - Add new product at beginning\n");
        printf("4 - Print List\n");
        printf("5 - Search the cheaper product\n");
        printf("6 - Delete the nth last elements\n");
        printf("7 - Swap two elements by position\n");
        printf("8 - Exit\n");
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
                printf("List desallocated successfully\n\n");
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
                printf("Printing all products in the list:\n\n");
                ok = printList(li, cont);

                if(ok == 0){
                    printf("List doesn't exist\n");
                }
            
                break;
            }

        case 5:
            {  
                Produto cheaper;
                
                ok = searchCheaperProduct(li, &cheaper);

                if(ok){
                    printf("Successful search\n\n");
                    
                    printf("The cheaper product is:\n");
                    printf("Code: %d\n",cheaper.codigo);
                    printf("Name: %s\n",cheaper.nome);
                    printf("Price: %.2f\n",cheaper.preco);
                    printf("Amount: %d\n\n", cheaper.qtd);
                }else{
                    printf("Fail");
                }


                break;
            }

        case 6:
        {
            int n;
            printf("How many elements from end do you want do delete? ");
            scanf("%d", &n);
            printf("\n");

            ok = deleteNthElement(li, n);

            if(ok){
                printf("Successful deletion\n\n");
            }else{
                printf("Fail\n\n");
            }

            break;
        }
        case 7:
         {   
            int p1, p2; 

            printf("Type the first position: "); 
            scanf("%d", &p1);
            printf("Type the second position: "); 
            scanf("%d", &p2);

            ok = swapByPosition(li, p1, p2);

            if(ok){
                printf("Successful swap\n\n");
            }else{
                printf("Fail");
            }

            break;
         }
        case 8:
            printf("Thank you\n\n");
            break;

        default:
            printf("Invalid option\n\n");
            break;
        }

        
    }while(choice!=8);

    return 0;
}

int createProduct(Produto *prod){
    printf("Type the product code: ");
    scanf("%d", &(prod)->codigo);
    printf("Type the product name ");
    scanf(" %[^\n]", (prod)->nome);
    printf("Type the product price: ");
    scanf("%f", &(prod)->preco);
    printf("Type the product amount: ");
    scanf("%d", &(prod)->qtd);
    printf("\n");

    return 1;
}