#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* RecursiveInsert(struct node* head, int x);

void RecursivePrint(struct node* head);

struct node* RecursiveReverse(struct node* head);

void RecursivePrintReverse(struct node* head);

int main(){
	struct node* head = NULL;
	
	int n, x;
	
	printf("How many nodes do you wish? ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the values: ");
		scanf("%d", &x);
		
		head = RecursiveInsert(head, x);
	}
	
	if(head==NULL){
		printf("The list is empty!!!\n");
	}else{
	
		printf("The created list is: ");
		RecursivePrint(head);
	
		head = RecursiveReverse(head);
	
		printf("The created list is: ");
		RecursivePrintReverse(head);
	}
	
	return 0;
}

struct node* RecursiveInsert(struct node* head, int x){
	struct node* temp;
	
	if(head==NULL){
		head = (struct node*)malloc(sizeof(struct node));
		
		head->data = x;
	
		head->next = NULL;
	}else{
		head->next = RecursiveInsert(head->next, x);
	}
	
	return head;
}

void RecursivePrint(struct node* head){
	if(head==NULL){ 
		printf("\n");
	}else{
		printf("%d ", head->data); 
		RecursivePrint(head->next);
	}
}

struct node* RecursiveReverse(struct node* head){
	struct node* temp = head;
	if(temp->next==NULL){
		head = temp;
	}else{
		head = RecursiveReverse(temp->next);
		//temp->next->next = temp;
		struct node* q = temp->next;
		q->next = temp;
		temp->next = NULL;
	}
	
	return head;
}

void RecursivePrintReverse(struct node* head){
	if(head==NULL){ 
		//printf("\n");
	}else{
		RecursivePrintReverse(head->next); 
		printf("%d ", head->data); 
	}
}