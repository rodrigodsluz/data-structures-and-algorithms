#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main(){
    Queue *qu;
    Student stud;

    int choice, ok;

    do{
        printf("1 - Create queue\n");
        printf("2 - Free queue\n");
        printf("3 - Insert element in the queue\n");
        printf("4 - Print queue\n");
        printf("5 - Remove element of the queue\n");
        printf("6 - Size of queue\n");
        printf("7 - Exit\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                qu  = createQueue();

                if(qu != NULL){
                    printf("Queue successfully created!!!\n");
                }else{
                    printf("Failed!!!\n");
                }

                break;
            }

            case 2:{
                
                break;
            }

            case 3:{
                
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