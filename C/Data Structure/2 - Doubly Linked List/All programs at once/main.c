#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}node;

//[0] - Allocate node
node *allocateNode(node *head, int x);

//[1] - Print doubly linked list
void printForward(node *head);

//[2] - Insert at beginning
node *insertAtBeginning(node *head, int x);

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
	
	printForward(head);
	
	return 0;
}

//[0] - Allocate node
node *allocateNode(node *head, int x){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->next = NULL;
	
	return newNode;
}

//[1] - Print doubly linked list
void printForward(node *head){
	if(head==NULL){
		printf("Empty.");
	}else{
		while(head!=NULL){
			printf("%d ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

//[2] - Insert at beginning
node *insertAtBeginning(node *head, int x){
	node *temp = head;
	
	head = allocateNode(head, x);
	
	head->next = temp;

	return head;
}
	//You need to test with number 0 and put the error if the memory is insufficient