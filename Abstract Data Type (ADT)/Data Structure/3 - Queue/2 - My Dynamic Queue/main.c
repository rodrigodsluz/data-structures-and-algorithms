#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int createStudent(Student *stud);

int main(){
    Queue *qu;
    Student stud;

    int choice, ok;

    do{
        printf("1 - Create queue\n");
        printf("2 - Free queue\n");
        printf("3 - Enqueue\n");
        printf("4 - Print queue\n");
        printf("5 - Dequeue\n");
        printf("6 - Consult the first element\n"); 
        printf("7 - Exit\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                qu  = createQueue();

                if(qu != NULL){
                    printf("Queue created successfully!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 2:{
                ok = freeQueue(qu);

                if(ok){
                    printf("Queue deallocated successfully!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 3:{
                ok = createStudent(&stud);
                ok = insertInTheQueue(qu, stud);

                if(ok){
                    printf("Successful enqueue!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 4:{
                ok = printQueue(qu);

                if(!ok){
                    printf("Queue not found!\n");
                }

                break;
            }

            case 5:{
                ok = dequeue(qu);

                if(ok){
                    printf("Successful dequeue!\n");
                }else{
                    printf("Failed!\n");
                }

                break;
            }

            case 6:{
                Student temp;
                ok = consultFirstElement(qu, &temp);

                if(ok){
                    printf("The first element of queue is: ");
                    printf(" %s\n", temp.name); 
                    printf(" %d\n", temp.registration);
                    printf(" %d\n", temp.grade);
                    
                }else{
                    printf("Failed!\n");
                }

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