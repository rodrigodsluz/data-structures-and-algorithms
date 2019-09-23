#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int createData(int *data);

int main(){

    List *li;

    int choice, ok, data;

    do{
        printf("1 - Create list\n");
        printf("2 - Free list\n");
        printf("3 - Insert new integer at beginning\n");
        printf("4 - Print List\n");
        printf("5 - --\n");
        printf("6 - --\n");
        printf("7 - --\n");
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
                printf("List wasn't created");
            }

            break;
        
        case 2:
            ok = freeList(li);

            if(ok){
                printf("List desallocated successfully\n\n");
            }else{
                printf("List wasn't deallocated");
            }
            break;

        case 3:
            ok = createData(&data);
            ok = insertAtBeginning(li, data);

            if(ok){
                printf("Successful insertion\n\n");
            }else{
                printf("Failed insertion");
            }

            break;

        case 4:
            {
                printf("Linked list:\n\n");
                ok = printList(li);

                if(ok == 0){
                    printf("List wasn't created\n");
                }
            
                break;
            }
/*
        case 5:
            {  
                Student student1, student2;

                List *l1 = createList();
                List *l2 = createList();
                //List *l3 = createList();

                ok = addStudentRegistration(&student1);
                ok = insertAtBeginning(l1, student1);

                if(ok){
                    printf("Successful insertion\n\n");
                }else{
                    printf("Failed insertion");
                }

                ok = addStudentRegistration(&student2);
                ok = insertAtBeginning(l2, student2);

                if(ok){
                    printf("Successful insertion\n\n");
                }else{
                    printf("Failed insertion");
                }

                ok = mergeLists(l1, l2, li);

                if(ok){
                    printf("Successful merge\n\n");
                }else{
                    printf("Failed merge");
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
         }*/
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

int createData(int *data){
    printf("Type the value: ");
    scanf("%d", data);

    printf("\n");
    return 1;
}