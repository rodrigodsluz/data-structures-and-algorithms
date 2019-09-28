#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

//[0] - Allocate node
node *allocateNode(int x);

//[1] - Print circular singly linked list
void printForward(node *front, node *rear);

//[2] - insert at END
void insertAtEnd(node **front, node **rear, int x);

int main(){
	node *front = NULL;
	node *rear = NULL;
	
	int n, x;
	do{
		printf("How many nodes do you want? ");
		scanf("%d", &n);
	}while(n<0);
	
	for(int i=0; i<n; i++){
		printf("Enter the values: ");
		scanf("%d", &x);
		
		//[2] - insert at END
		insertAtEnd(&front, &rear, x);
		
		//[3] - insert at BEGINNING
		
	}
	
	//[1] - Print circular singly linked list
	printForward(front, rear);
	
	return 0;
}

//[0] - Allocate node
node *allocateNode(int x){
	node *newNode = (node*)malloc(sizeof(node));
	if(newNode==NULL){
		printf("Insufficient memory!");
	}
	newNode->data = x;
	newNode->next = NULL;
	
	return newNode;
}

//[1] - Print circular singly linked list
void printForward(node *front, node *rear){
	if(front==NULL){
		printf("Empty.");
	}else{
		while(front!=rear){
			printf("%d ", front->data);
			front = front->next;
		}
		printf("%d ", front->data);

		
	}
	
}

//[2] - insert at END
void insertAtEnd(node **front, node **rear, int x){
	node *newNode = allocateNode(x);
	if(*rear==NULL){
		*front=*rear=newNode;
	}else{
		(*rear)->next=newNode;
		*rear=newNode;
	}
	
	(*rear)->next=*front;
	
}