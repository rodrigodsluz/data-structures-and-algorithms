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

//[3] - Insert at end
node *insertAtEnd(node *head, int x);

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
		
		//[2] - Insert at beginning
		head = insertAtBeginning(head, x);
		
		//[3] - Insert at end
		//head = insertAtEnd(head, x);
		
	}
	
	//[1] - Print doubly linked list
	printForward(head);
	
	return 0;
}

//[0] - Allocate node
node *allocateNode(node *head, int x){
	node *newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL){
		printf("Insufficient memory!");
	}
	newNode->data = x;
	newNode->prev = NULL;
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
	node *newNode = allocateNode(head , x);
	
	if(head==NULL){
		head = newNode;
	}else{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}

	return head;
}

//[3] - Insert at end
node *insertAtEnd(node *head, int x){
	node *newNode = allocateNode(head, x);
	
	if(head == NULL){
		head = newNode;
	}else{
		node *temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	
	return head;
}
