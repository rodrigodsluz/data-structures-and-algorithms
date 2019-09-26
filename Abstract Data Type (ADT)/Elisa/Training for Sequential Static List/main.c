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
        printf("5 - Insert at end\n");
        printf("6 - Insert student in increasing order\n");
        printf("7 - Delete at beginning\n");
        printf("8 - Delete at end\n");
        printf("9 - Delete any value\n");
        printf("10 - Search value by position\n");
        printf("11 - Search position by value\n");
        printf("12 - --\n");
        printf("13 - Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){

            case 1:{
                li = createList();

                if(li!=NULL){
                    printf("Sequential Static List Successfully created!!!\n\n");
                }else{
                    printf("Failed\n\n");
                }

                break;
            }

            case 2:{
                ok = freeList(li);

                if(ok){
                    printf("Deallocated Successfully!!!\n\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 3:{
                ok = printList(li);

                if(!ok){
                    printf("List not found!!!\n\n");
                }

                break;
            }

            case 4:{
                ok = addStudent(&stud);
                ok = insertAtBeginning(li, stud);

                if(ok){
                    printf("Successful insertion at beginning!!!\n\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 5:{
                ok = addStudent(&stud);
                ok = insertAtEnd(li, stud);

                if(ok){
                    printf("Successful insertion at end!!!\n\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 6:{
                ok = addStudent(&stud);
                ok = insertIncreasingOrder(li, stud);

                if(ok){
                    printf("Successful insertion at end!!!\n\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 7:{
                ok = deleteAtBeginning(li);

                if(ok){
                    printf("Successful deletion!!!\n\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 8:{
                ok = deleteAtEnd(li);

                if(ok){
                    printf("Successful deletion!!!\n\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 9:{
                int p;
                printf("Enter the value to delete: ");
                scanf("%d", &p);
                ok = deleteAnyValue(li, p);

                if(ok){
                    printf("Successful deletion!!!\n\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 10:{
                int p, v;
                printf("Enter the position to find the value: ");
                scanf("%d", &p);

                ok = searchValueByPosition(li, p, &v);

                if(ok){
                    printf("Successful search!!!\n\n");
                    printf("The value at %dth position is: %d", p, v);
                    printf("\n");
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 11:{
                int v, p;
                printf("Enter the value to find the position: ");
                scanf("%d", &v);

                ok = searchPositionByValue(li, v, &p);

                if(ok){
                    printf("Successful search!!!\n\n");
                    printf("The value %d it's at %dth position!!!\n", v, p);
                }else{
                    printf("Failed!!!\n\n");
                }

                break;
            }

            case 12:{
                

                break;
            }

            case 13:{
                printf("Thank you!!!\n\n");

                break;
            }

            default: {
                printf("Invalid Option!!!\n\n");
            }
        }
    }while(choice != 13);


    return 0;
}

int addStudent(Student *stud){
    printf("What's the student name? ");
    scanf(" %[^\n]", stud->name);
    printf("What's the student grade? ");
    scanf("%lf", &stud->grade);
    printf("What's the student registration number?");
    scanf("%d", &stud->registerNumber);
    printf("\n");

    return 1;
}