#include <stdio.h>
#include <stdlib.h>
#include "listaCircularDuplaEnc.h"
#include "listaCircularEnc.h"
#include "listaDuplaEnc.h"
#include "listaEncadeada.h"

int addStudentRegistration(Student *student);

int main(){

    List *head = createList();

    Student student;

    int n, ok;

    printf("How many elements do you want? ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Create the student registration:\n");

        ok = addStudentRegistration(&student);
        ok = insertAtBeginning(head, student);
    }

    printList(head);

    return 0;
}

int addStudentRegistration(Student *student){
    printf("Enter the registration number: ");
    scanf(" %d", &student->matricula);
    printf("Enter the name: ");
    scanf(" %[^\n]", student->nome);
    printf("Enter the note: ");
    scanf("%f", &student->nota);

    return 1;
}