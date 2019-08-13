#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* Insert(struct node* head, int x);

struct node* GetNewNode(int x);

void Print(struct node* head);

int main(){
	struct node* head = NULL;
	
	int n, x;
	
	printf("How many nodes do you wish? ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the value: ");
		scanf("%d", &x);
		
		head = Insert(head, x);
	}
	
	Print(head);
	
	return 0;
}

struct node* Insert(struct node* head, int x){
	struct node* newNode = GetNewNode(x);
	if(head == NULL){
		head = newNode;
	}else{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	
	return head;
}

struct node* GetNewNode(int x){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;
	
}

void Print(struct node* head){
	if(head == NULL){
		printf("The list is empty!!!\n");
	}else{
		printf("The created list is: ");
		while(head!=NULL){
			printf("%d ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}