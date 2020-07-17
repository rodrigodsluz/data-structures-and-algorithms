#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int addStudentRegistration(Student *student);

int main(){

    List *li, *l1, *l2;

    Student student, student1, student2;   

    int choice, ok;

    do{
        printf("1 - Create list l1, l2 and li\n");
        printf("2 - Free list l1, l2 and li\n");
        printf("3 - Add new student at beginning of the list l1 and l2\n");
        printf("4 - Print List l1, l2 or li\n");
        printf("5 - Merge two list (l1 and l2) to li\n");
        printf("6 - Copy list l1 to l2, deleting repeated values\n");
        printf("7 - Reverse list l1  and store in list l2 \n");
        printf("8 - Verify if the list l1 is sort\n");
        printf("9 - What's the size of the list l1?\n");
        printf("10 - Exit\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
        case 1:
            
            li = createList();
            l1 = createList();
            l2 = createList();

            if(li!=NULL){
                printf("List li created successfully\n\n");
            }else{
                printf("List wasn't created");
            }

            if(l1!=NULL){
                printf("List l1 created successfully\n\n");
            }else{
                printf("List wasn't created");
            }

            if(l2!=NULL){
                printf("List l2 created successfully\n\n");
            }else{
                printf("List wasn't created");
            }

            break;
        
        case 2:
            ok = freeList(li);
            
            if(ok){
                printf("List li desallocated successfully\n\n");
            }else{
                printf("List wasn't deallocated");
            }

            ok = freeList(l1);
            if(ok){
                printf("List l1 desallocated successfully\n\n");
            }else{
                printf("List wasn't deallocated");
            }


            ok = freeList(l2);
            if(ok){
                printf("List l2 desallocated successfully\n\n");
            }else{
                printf("List wasn't deallocated");
            }
            break;

        case 3:

                printf("Insert in list l1\n");
                ok = addStudentRegistration(&student1);
                ok = insertAtBeginning(l1, student1);

                if(ok){
                    printf("Successful insertion\n\n");
                }else{
                    printf("Failed insertion");
                }

                printf("Insert in list l2\n");
                ok = addStudentRegistration(&student2);
                ok = insertAtBeginning(l2, student2);

                if(ok){
                    printf("Successful insertion\n\n");
                }else{
                    printf("Failed insertion");
                }

            break;

        case 4:
            {
                int k;
                printf("What do you want to print?\n");
                printf("[1] - Print L1?\n");
                printf("[2] - Print L2?\n");
                printf("[3] - Print Li (merged list)?\n");
                scanf("%d", &k);

                if(k==1){
                    ok = printList(l1);
                }else if(k==2){
                    ok = printList(l2);
                }else{
                    ok = printList(li);
                }

                if(ok == 0){
                    printf("List wasn't created\n");
                }
            
                break;
            }

        case 5:
            {  
            
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
            
             ok = copyList(l1, l2);

             if(ok){
                 printf("Successful copy\n\n");
             }else{
                 printf("Failed");
             }

            break;
        }
        
        case 7:
         {   

            ok = reverseList(l1, l2);

            if(ok){
                 printf("Successful reverse\n\n");
             }else{
                 printf("Failed");
             }

            break;
         }

        case 8:
         {   

            ok = isSort(l1);

            if(ok){
                 printf("The list is in increasing order\n\n");
             }else{
                 printf("The list isn't sort\n\n");
             }

            break;
         }
        case 9:
         {   
            
            ok = sizeOfList(l1);

            printf("The size of list l1 is: %d ", ok);
            printf("\n\n");
                 
             
            break;
         }
        case 10:
            printf("Thank you\n\n");
            break;

        default:
            printf("Invalid option\n\n");
            break;
        }

        
    }while(choice!=10);

    return 0;
}

int addStudentRegistration(Student *student){
    printf("Enter the registration number: ");
    scanf(" %d", &student->matricula);
    printf("Enter the name: ");
    scanf(" %[^\n]", student->nome);
    printf("Enter the note: ");
    scanf("%f", &student->nota);

    printf("\n");
    return 1;
}