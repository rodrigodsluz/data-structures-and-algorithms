#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* Insert(struct node* head, int x);

void Print(struct node* head);

int main(){
	struct node* head = NULL;
	
	int n, x;
	
	printf("How many numbers do you wish? ");
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
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	
	struct node* temp2  = head;
	
	temp1->data = x;
	
	temp1->next = NULL;
	
	if(head==NULL){
		head = temp1;
	}else{
		while(temp2->next != NULL){
			temp2 = temp2->next;
		}
		
		temp2->next = temp1;
	}
	
	return head;
}

void Print(struct node* head){
	if(head==NULL){
		printf("The list is empty!!!\n");
	}else{
		printf("The created list is: ");
		while(head!=NULL){
			printf("%d ", head->data);
			head = head->next;
		}
	}
}