#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int createData(int *data);

int main(){
    List *li; 

    int choice, data, ok, pos;

    do{
        printf("\n\nOptions Menu");
        printf("\n1 - Create List");
        printf("\n2 - Free List");
        printf("\n3 - Insert at beginning");
        printf("\n4 - Insert at end");
        printf("\n5 - Insert in a sorted list");
        printf("\n6 - Delete from beginning");
        printf("\n7 - Delete from end");
        printf("\n8 - Delete element by value");
        printf("\n9 - Buscar elemento pela posição");
        printf("\n10 - Buscar elemento pelo dado");
        printf("\n11 - Imprimir lista");
        printf("\n12 - Sair");
        printf("\nOpção: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                li = createList();

                if(li != NULL){
                    printf("\n Linked list created successfully!");
                }else{
                    printf("\n Error!");
                }

                break;

            case 2:
                ok = freeList(li);

                if(ok){
                    printf("\n Linked list deallocated successfully");
                }else{
                    printf("\n Error!");
                }

                break;

            case 3:
                ok = createData(&data);
                ok = insertAtBeginning(li, data);

                if(ok){    
                    printf("\n Successful insertion!");
                }else{
                    printf("\n Error!");
                }

                break;

            case 4:
                ok = createData(&data);
                ok = insertAtEnd(li, data);

                if(ok){
                    printf("\n Successful insertion!");
                }else{
                    printf("\n Error!");
                }

                break;

            case 5:
                ok = createData(&data);
                ok = insertSortedList(li, data);

                if(ok){
                    printf("\n Successful insertion!");
                }else{
                    printf("\n Error!");
                }

                break;

            case 6:
                ok = deleteFromBeginning(li);

                if(ok){
                    printf("\n Successful deletion!");
                }else{
                    printf("\n Error!");
                }
                break;

            case 7:
                ok = deletionFromEnd(li);

                if(ok){
                    printf("\n Successful deletion!");
                }else{
                    printf("\n Error!");
                }
                break;

            case 8:
                printf("\n Enter the value to be removed: ");
                scanf("%d", &data);

                ok = deleteNthPosition(li, data);

                if(ok){
                    printf("\n Successful deletion!");
                }else{
                    printf("\n Error!");
                }
                break;

            case 9:
            
                printf("\n Type the element position to be searched: ");
                scanf("%d", &pos);

                ok = searchElementByPosition(li, pos, &data);

                if(ok){
                    printf("\n Successful search!");
                    printf("\n Element of %dth position is: ", pos);
                    printf("%d", data);
                }else{
                    printf("\n This position doesn't exist!");
                }

                break;

            case 10:

            printf("\n Type the element value to be searched: ");
            scanf("%d", &data);

            ok = searchElementByValue(li, data, &pos);

            if(ok){
                printf("\n Successful search!");
                printf("\n The element value of %dth position is: ", pos);
                printf("%d", data);
            }else{
                printf("\n This element doesn't exist!");
            }

                break;

            case 11:
                printf("\n Static list: ");
                ok = printList(li);

                break;

            case 12:

                // libera memória e finaliza programa
                // liberar_lista(li);
                printf("\nFinalizando...");
                break;

            default:
                printf("\nOpção inválida!");
                break;
    }

  }while(choice != 12);

  return 0;
}

int createData(int *data){
    printf("\nEnter a value: ");
    scanf("%d", data);

    return 1;
}

