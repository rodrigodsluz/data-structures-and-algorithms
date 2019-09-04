#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main(){
    int n, x;
    printf("How many values do you want? ");
    scanf("%d", &n);

    List *li = createList();

    for(int i=0; i<n; i++){
        printf("Enter the value: ");
        scanf("%d", &x);

        insertAtBeginning(li, x);

    }

    printList(li);

    void freeList(List *li);

    return 0;
}
