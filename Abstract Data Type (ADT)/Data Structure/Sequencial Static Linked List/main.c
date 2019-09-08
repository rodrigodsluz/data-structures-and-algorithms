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
        printf("\n8 - Delete nth position");
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
/*

      case 9:

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        produto = buscar_lista_posicao(li, pos);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ");
          imprimir_produto(produto);
        }else{
          printf("\n Posição não existe!");
        }

        break;

      case 10:

        // busca elemento pelo dado
        printf("\n Código do produto a ser buscado: ");
        scanf("%d", &dado);

        produto = buscar_lista_dado(li, dado);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento com código %d na lista: ", dado);
          imprimir_produto(produto);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;*/

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

