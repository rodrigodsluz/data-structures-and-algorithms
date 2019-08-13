#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* Insert(struct node* head, int x);

void Print(struct node* head);

struct node* Delete(struct node* head, int p);

int Lenght(struct node* head);

int main(){
	struct node* head = NULL;
	
	int n, x, p;
	
	system("cls");
	printf("How many nodes do you wish? ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the values: ");
		scanf("%d", &x);
		
		head = Insert(head, x);
	}
	
	if(head==NULL){
		printf("The list is empty!!!");
	}else{
		
		do{
			system("cls");
			printf("Before delete: ");
			Print(head);
	
			printf("\n");
		
			printf("Enter the position to delete: ");
			scanf("%d", &p);
		}while(p>Lenght(head) || p==0 || p<0);			
		
		head = Delete(head, p);
	
		printf("After delete: ");
		Print(head);
	}

	return 0;
}

struct node* Insert(struct node* head, int x){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	
	struct node* temp2 = head;
	
	temp1->data = x;
	
	temp1->next = NULL;
	
	if(head==NULL){
		head = temp1;
	}else{
	
		while(temp2->next!=NULL){
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

struct node* Delete(struct node* head, int p){
	
	if(head==NULL){
		printf("The list is empty!!!");
	}
	
	struct node* temp1 = head;
	
	struct node* temp2;
	
	if(p==1){
		head = temp1->next;
		free(temp1);
	}else{
		for(int i=0; i<p-2; i++){
			temp1 = temp1->next;	
		}
		temp2 = temp1->next;
		temp1->next = temp2->next; 
		free(temp2); 
	}
	
	return head;
}

int Lenght(struct node* head){
	int count = 0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	
	return count;
}