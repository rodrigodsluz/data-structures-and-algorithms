#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int createStudent(Student *stud);

int main(){
    Stack *st;
    Student stud;

    int choice, ok;

    do{
        printf("1 - Create stack\n");
        printf("2 - Free stack\n");
        printf("3 - Stack Up\n");
        printf("4 - Print stack\n");
        printf("5 - Unstack\n");
        printf("6 - Size of stack\n"); //Consult the first element
        printf("7 - Exit\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                st  = createStack();

                if(st != NULL){
                    printf("Stack created successfully!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 2:{
                ok = freeStack(st);

                if(ok){
                    printf("Stack deallocated successfully!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 3:{
                ok = createStudent(&stud);
                ok = stackUp(st, stud);

                if(ok){
                    printf("Successful stack up!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 4:{
                
                break;
            }

            case 5:{
                
                break;
            }

            case 6:{
                
                break;
            }

            case 7:{
                printf("Program finished!!!\n");
                printf("Thank you, good lucky in your life!!!\n");
                break;
            }            

            default:{
                printf("Invalid option!!!\n");
                break;
            }

        }

    }while(choice!=7);

    return 0;
}

int createStudent(Student *stud){
    printf("Enter the student name: ");
    scanf(" %[^\n]", stud->name);
    printf("Enter the grade: ");
    scanf("%d", &stud->grade);
    printf("Enter the registration number: ");
    scanf("%d", &stud->registration);

    return 1;
}