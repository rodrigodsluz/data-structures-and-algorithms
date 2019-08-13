#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* Insert(struct node* head, int x);

void Print(struct node* head);

struct node* Sort(struct node* head);

int main(){
	struct node* head = NULL;
	
	int n, x;
	
	printf("How many nodes do you want? ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the value: ");
		scanf("%d", &x);
		
		head = Insert(head, x);
	}
	
	printf("Disorder linked list: ");
	Print(head);
	
	printf("Sorted linked list: ");
	head = Sort(head);
	Print(head);
	return 0;
}

struct node* Insert(struct node* head, int x){
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	
	temp1->data = x;
	temp1->next = head;
	
	head = temp1;
	
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
		printf("\n");
	}
}

struct node* Sort(struct node* head){
	struct node *temp1,*temp2,*min,*prev,*q;
	
	q = NULL;
	
	while(head != NULL){
		prev = NULL;
		min = temp1 = head;
		temp2 = head -> next;
		
		while ( temp2 != NULL ){
			if(min -> data > temp2 -> data){
				min = temp2;
				prev = temp1;
			}
			
			temp1 = temp2;
			temp2 = temp2-> next;
		}
		
		if(prev == NULL){
			head = min -> next;
		}else{
			prev -> next = min -> next;
		}
		
		min -> next = NULL;
		
		if( q == NULL){
			q = min;
		}else{
			temp1 = q;	
			while( temp1 -> next != NULL){
				temp1 = temp1 -> next;
			}
			temp1 -> next = min;
		}
	}
	return q;
}

//INSERTING A NEW NODE IN A SORTED LIST
/* a function to insert a node with data value n in a sorted list
pointed to by p*/
struct node *SortInsert(struct node *head, int x){
	struct node *curr, *prev;
	curr =p;
	prev = NULL;

	while(curr ->data < x){
		prev = curr;
		curr = curr->next;
	}
	
	/* the element is to be inserted at the start of
	the list because
	it is less than the data value of the first node*/
						
	if ( prev == NULL){ 
	curr = (struct node *) malloc(sizeof(struct node));
		if( curr == NULL){
			printf("error cannot allocate\n");
			exit(0);
		}
		curr->data = x;
		curr->link = head;
		head = curr;
	}else{
		curr->data = x;
		curr->next = prev->next;
		prev->next = curr;
	}
	return head;
}