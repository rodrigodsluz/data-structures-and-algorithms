#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
//#include <unistd.h>

struct node{
	int data;
	struct node* next;
};

struct node* Insert(struct node* head, int p, int x);

void Print(struct node* head);

int Lenght(struct node* head);

struct node* Delete(struct node* head, int p);

int main(){
	struct node* head = NULL;
	
	int n, x, p;
	
	printf("How many number do you wish? ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		
		do{
			
			system("cls");
			printf("Enter the position of the node: ");
			scanf("%d", &p);
		}while(p>Lenght(head)+1 || p==0 || p<0);
		
		printf("Enter the value: ");
		scanf("%d", &x);
		
		head = Insert(head, p, x);
	}
	
	//Print(head);
	//Sleep(2000);
	
	do{
		system("cls");
		Print(head);
		printf("Enter the position of the node to insert a new value: ");
		scanf("%d", &p);
	}while(p>Lenght(head)+1 || p==0 || p<0);
	printf("Enter the value: ");
	scanf("%d", &x);
	
	system("cls");
	printf("The old list is: ");
	Print(head); 
	
	head = Insert(head, p, x);
	
	if(Lenght(head) == 1){
		printf("The new linked list is: ");
	}else{
		printf("The new linked list is: ");
		head = Delete(head, (p+1));
	}
	
	Print(head);
	
	return 0;
}

int Lenght(struct node* head){
	int count=0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	
	return count;
}

struct node* Insert(struct node* head, int p, int x){
	/*
	if(p>Lenght(head)+1 || p==0){
		printf("This position doesn't exist!!!");
	}
	*/
	
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	
	struct node* temp2 = head;
	
	temp1->data = x;
	
	temp1->next = NULL;
	
	if(p==1){
		temp1->next = head;
		head = temp1;
	}else{
		for(int i=0; i<(p-2); i++){
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}
	
	return head;
}

void Print(struct node* head){
	if(head==NULL){
		printf("The list is empty!!!\n");
		//Sleep(2000);
	}else{
		//printf("The created list is: ");
		while(head!=NULL){
			printf("%d ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

struct node* Delete(struct node*head, int p){
	struct node* temp1 = head;
	
	if(p == 1){
		head = temp1->next;
		free(temp1);
	}else{
		for(int i=0; i<p-2; i++){
			temp1 = temp1->next;
		}
		struct node* temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
	
	return head;
}