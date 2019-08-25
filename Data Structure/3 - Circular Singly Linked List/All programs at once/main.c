#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

//[0] - Allocate node
node *allocateNode(node *head, int x);

int main(){
	node *head = NULL;
	
	int n, x;
	do{
		printf("How many nodes do you want? ");
		scanf("%d", &n);
	}while(n<0);
	
	for(int i=0; i<n; i++){
		printf("Enter the values: ");
		scanf("%d", &x);
		
		head = insertAtBeginning(head, x);
		
	}
	
	return 0;
}

//[0] - Allocate node
node *allocateNode(node *head, int x){
	node *newNode = (node*)malloc(sizeof(node));
	if(node==NULL){
		printf("Insufficient memory!");
	}
	newNode->data = x;
	newNode->next = NULL;
	
	return newNode;
}