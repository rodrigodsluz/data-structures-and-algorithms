#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

//[1] - Print forward
void PrintForward(struct node* head);

//[2] - Inserting at beginning
struct node* InsertAtHead(struct node* head, int x);

//[3] - Insert at tail
struct node* InsertAtTail(struct node* head, int x);

//[4] - Insert at nth position
struct node* InsertAtNthPosition(struct node* head, int x, int p);

//[5] - Delete from beginning
struct node* DeleteFromBeginning(struct node* head);

//[6] - Delete from end
struct node* DeleteFromEnd(struct node* head);

//[7] - Delete at nth position
struct node* DeleteAtNthPosition(struct node* head, int p);

//[8] - Reverse a linked list - Iterative Method\n");
struct node* reverseIterativeMethod(struct node* head);

int main(){
	struct node* head = NULL;
	
	int n, x, p;
	
	printf("How many nodes do you want? ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the value: ");
		scanf("%d", &x);
		
		//head = InsertAtHead(head, x);
		
		head = InsertAtTail(head, x);
		
	}
	
	//printf("[2] - Insert at beginning: ");
	//PrintForward(head);
	
	printf("[3] - Insert at tail: ");
	PrintForward(head);
	
	/*//[4] - Insert at nth position
	printf("How many values of nodes do you want change? ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("Enter the new value: ");
		scanf("%d", &x);
		printf("Enter the new position: ");
		scanf("%d", &p);
		head = InsertAtNthPosition(head, x, p);
	}
	printf("[4] - Insert at nth position: ");
	PrintForward(head);
	*/
	
	//printf("[5] - Delete from beginning: ");
	//head = DeleteFromBeginning(head);
	//PrintForward(head);
	
	//printf("[6] - Delete from end: ");
	//head = DeleteFromEnd(head);
	//PrintForward(head);
	
	/*//[7] - Delete at nth position
	printf("How many values do you want to delete? ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("Enter the position to delete: ");
		scanf("%d", &p);
		head = DeleteAtNthPosition(head, p);
	}
	printf("[7] - Delete at nth position: ");
	PrintForward(head);
	*/
	
	printf("[8] - Reverse a linked list - Iterative Method\n");
	head = reverseIterativeMethod(head);
	printReverse(head);
	
	//
	
	return 0;
}

//[1] - Print Forward
void PrintForward(struct node* head){
	if(head == NULL){
		printf("Empty!\n");
	}else{
		while(head!=NULL){
			printf("%d ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

//[2] - Inserting at beginning
struct node* InsertAtHead(struct node* head, int x){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	
	temp1->data = x;
	temp1->next = head;
	head = temp1;
	
	return head;
}

//[3] - Insert at tail
struct node* InsertAtTail(struct node* head, int x){
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

//[4] - Insert at nth position
struct node* InsertAtNthPosition(struct node* head, int x, int p){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	
	struct node* temp2 = head;
	
	temp1->data = x;
	//temp1->next = NULL;
	
	if(p==1){
		temp1->next = head;
		head = temp1;
	}else{
		for(int i=0; i<(p-2); i++){ //for(int i=1; i<=(p-2); i++){  or for(int i=1; i<(p-1); i++){
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}
	
	return head;
}

//[5] - Delete from beginning
struct node* DeleteFromBeginning(struct node* head){
	if(head==NULL){
		return 0;
	}else{
		struct node* temp1 = head;
	
		head = head->next;
		free(temp1);
	}
	
	return head;
}

//[6] - Delete from end
struct node* DeleteFromEnd(struct node* head){
	struct node* temp1, *temp2;
	
	if(head==NULL){
		return 0;
	}else if(head->next==NULL){
		temp1 = head;
		head = NULL;
		free(temp1);
	}else{
		temp2 = head;
		temp1 = head->next;
		while(temp1->next!=NULL){
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = NULL;
		free(temp1);
	}
	
	return head;
}

//[7] - Delete at nth position
struct node* DeleteAtNthPosition(struct node* head, int p){
	struct node* temp1, *temp2;
	
	if(head==NULL){
		printf("Impossible to delete what doesn't exist!!!\n");
	}else if(p==1){
		temp1 = head;
		head = head->next;
		free(temp1);
	}else{
		temp1 = head;
		for(int i=0; i<(p-2); i++){
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
	
	return head;
}

//[8] - Reverse a linked list - Iterative Method\n");
struct node* reverseIterativeMethod(struct node* head){
	struct node *prev, *current, *next;
	current = head;
	prev = NULL;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	
	return head;
}