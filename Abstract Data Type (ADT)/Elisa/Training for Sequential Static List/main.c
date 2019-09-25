#include <stdio.h>
#include <stdlib.h>
#include "staticList.h"

int addStudent(Student *stud);

int main(){
    int choice, ok;

    List *li;

    Student stud;
    
    do{
        printf("1 - Create List\n");
        printf("2 - Free List\n");
        printf("3 - Print List\n");
        printf("4 - Insert at beginning\n");
        printf("5 - Create List\n");
        printf("6 - Create List\n");
        printf("7 - Create List\n");
        printf("8 - Create List\n");
        printf("9 - Create List\n");
        printf("10 - Create List\n");
        printf("11 - Create List\n");
        printf("12 - Create List\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:{
                li = createList();

                if(li!=NULL){
                    printf("Sequential Static List Successfully created!!!\n");
                }else{
                    printf("Failed\n");
                }

                break;
            }

            case 2:{
                ok = freeList(li);

                if(ok){
                    printf("Deallocated Successfully!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 3:{
                ok = printList(li);

                if(!ok){
                    printf("List not found!!!\n");
                }

                break;
            }

            case 4:{
                ok = addStudent(&stud);
                ok = insertAtBeginning(li, stud);

                if(ok){
                    printf("Successful insertion at beginning!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 5:{


                break;
            }

            case 6:{


                break;
            }

            case 7:{


                break;
            }

            case 8:{


                break;
            }

            case 9:{


                break;
            }

            case 10:{


                break;
            }

            case 11:{


                break;
            }

            case 12:{
                printf("Thank you!!!");

                break;
            }

            default: {
                printf("Invalid Option!!!");
            }
        }
    }while(choice != 12);


    return 0;
}

int addStudent(Student *stud){
    printf("What's the student name? ");
    scanf(" %[^\n]", stud->name);
    printf("What's the student grade? ");
    scanf("%lf", &stud->grade);
    printf("What's the student registration number?");
    scanf("%d", &stud->registerNumber);

    return 1;
}