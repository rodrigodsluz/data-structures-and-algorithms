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

//[9] - Lenght of linked list
int length(struct node *head);

//[10] - Reverse Print
void printReverse(struct node *head);

//[11] - Recursive Insert at end
struct node* recursiveInsert(struct node* head, int x);

//[12] - Recursive print
void recursivePrint(struct node* head);

//[13] - Recursive reverse
struct node* recursiveReverse(struct node* head);

//[14] - Recursive print reverse
void recursivePrintReverse(struct node* head);

//[15] - Sorting Linked List
struct node* sortLinkedList(struct node* head);

//[16] - Sort insert
struct node* sortInsert(struct node* head, int x);

int main(){
	struct node* head = NULL;
	
	int n, x, p;
	
	printf("How many nodes do you want? ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the value: ");
		scanf("%d", &x);
		
		 /*Hello, you need to choose what to do*/
		 
		//head = InsertAtHead(head, x);
		
		//head = InsertAtTail(head, x);
		
		//head = recursiveInsert(head, x);
		
		//head = sortInsert(head, x);
		
		
	}
	
	//printf("[2] - Insert at beginning: ");
	//PrintForward(head);
	
	//printf("[3] - Insert at tail: ");
	//PrintForward(head);
	
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
	
	/*
	printf("[8] - Reverse a linked list - Iterative Method:\n");
	head = reverseIterativeMethod(head);
	
	printf("Print forward: ");
	PrintForward(head);
		
	//[9] - Length
	
	printf("[10] - Reverse print:\n");
	printReverse(head);
	*/
	
	
	//printf("[11] - Recursive Insert at end: ");
	//PrintForward(head);
	
	//printf("[12] - Recursive print: ");
	//recursivePrint(head);
	
	//printf("[13] - Recursive reverse: ");
	//head = recursiveReverse(head);
	//recursivePrint(head);
	
	//printf("[14] - Recursive print reverse: ");
	//recursivePrintReverse(head);
	
	/*
	printf("[15] - Sorting a Linked List: ");
	head = sortLinkedList(head);
	PrintForward(head);
	
	
	printf("[16] - Sorting insert: ");
	printf("Enter the value to be inserted: ");
	scanf("%d",&x);
	head = sortInsert(head, x);
	PrintForward(head);
	*/
	
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

//[9] - Lenght of linked list
int length(struct node* head){
	int length=0;
	while(head!=NULL){
		length++;
		head = head->next;
	}
	
	return length;
}

//[10] - Reverse Print
void printReverse(struct node *head){	
	//int length = length(head);
	int j = 0; 
    struct node *current = head; 
    while (current != NULL) { 
  
        // For each node, print proper number 
        // of spaces before printing it 
        for (int i = 0; i < (length(head) - j); i++){
            printf(" "); 
		}			
  
        // use of carriage return to move back 
        // and print. 
        printf("%d\r", current->data); // \r
  
        current = current->next; 
        j++; 
    } 
}

//[11] - Recursive Insert at end
struct node* recursiveInsert(struct node* head, int x){
	
	if(head==NULL){
		head = (struct node*)malloc(sizeof(struct node));
		
		head->data = x;
	
		head->next = NULL;
	}else{
		head->next = recursiveInsert(head->next, x);
	}
	
	return head;
}

//[12] - Recursive print
void recursivePrint(struct node* head){
	if(head==NULL){ 
		printf("\n");
	}else{
		printf("%d ", head->data); 
		recursivePrint(head->next);
	}
}

//[13] - Recursive reverse
struct node* recursiveReverse(struct node* head){
	struct node* temp = head;
	if(temp->next==NULL){
		head = temp;
	}else{
		head = recursiveReverse(temp->next);
		//temp->next->next = temp;
		struct node* q = temp->next;
		q->next = temp;
		temp->next = NULL;
	}
	
	return head;
}

//[14] - Recursive print reverse
void recursivePrintReverse(struct node* head){
	if(head==NULL){ 
		printf("");
	}else{
		recursivePrintReverse(head->next); 
		printf("%d ", head->data); 
	}
}

//[15] - Sorting Linked List
struct node* sortLinkedList(struct node* head){
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
	
	return head;
}

//[16] - Sort insert
struct node* sortInsert(struct node* head, int x){
	
	//INSERTING A NEW NODE IN A SORTED LIST
/* a function to insert a node with data value n in a sorted list
pointed to by head*/
	
	struct node* new_node =(struct node*) malloc(sizeof(struct node)); 
	/* put in the data  */
    new_node->data  = x; 
    new_node->next =  NULL; 
	
	struct node* current; 
    /* Special case for the head end */
    if (head == NULL || head->data >= new_node->data) 
    { 
        new_node->next = head; 
        head = new_node; 
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = head; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
	
	return head;
}
