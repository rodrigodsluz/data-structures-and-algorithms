#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//CASE 1
void f1 ();
void f2 ();

//CASE 2
int factorial(int n);

//CASE 3
int add(int pk,int pm);

//CASE 4
int fibonacci(int i);

//CASE 5

//CASE 6

//CASE 7
struct node{
	int data;
	struct node *link;
};

struct node *insert(struct node *p, int n);
void printlist ( struct node *p );

//CASE 8
struct node *insert2(struct node *p, int n);
void printlist2 ( struct node *p );

//CASE 9
struct node *insert3(struct node *p, int n);
void printlist3 ( struct node *p );
struct node *reverse(struct node *p);
struct node *sortlist(struct node *p);
struct node *delet ( struct node *p, int node_no );
int length ( struct node *p );

//CASE 10

//CASE 11
int *Add(int *x, int *y);
void PrintHelloWorld();

//CASE 12
int Add2(int a, int b);
void PrintHello(char *name);

//CASE 13
void A();
void B(void (*ptr)());

//CASE 14
int compare(int a, int b);
int absolute_compare(int a, int b);
void BubbleSort(int *A, int n, int (*compare)(int ,int));

//CASE 15
int compare2(const void *a, const void *b);

//CASE 16
int cash = 100;
void Play(int bet);

//CASE 17
struct node1{
	int data;
	struct node1* next;
};

//CASE 18
struct node2{
	int data;
	struct node2 *next;
};

/*struct node2 *head;    You can do this statement(global variable)*/

struct node2* Insert(struct node2 *head, int x);
void Print(struct node2 *head);

//CASE 19
struct node3{
	int data;
	struct node3* next;	
};

//struct node3* head;	

struct node3* Insert2(struct node3* head, int data, int n);
void Print2(struct node3* head);
//case 21
struct node3* ReverseList(struct node3* head);

//case 22
void PrintUsingRecursion(struct node3* head);

//case 23
struct node3* ReverseUsingRecursion(struct node3* head);

//CASE 20
struct node4{
	int data;
	struct node4* next;
};

struct node4* Insert3(struct node4* head, int data); //Insert an integer at end of the list
void Print4(struct node4* head); //Print all elements in the list
struct node4* Delete2(struct node4* head, int n);  //Delete node at postion n
//CASE 21
//Go to CASE 19

//CASE 22
//go to CASE 19

//CASE 23
//go to CASE 19

//CASE 24
struct node5{
	int data;
	struct node5* next;
	struct node5* prev;
};

struct node5* GetNewNode(int x);
struct node5* InsertAtHead5(struct node5* head, int x);
struct node5* InsertAtTail5(struct node5* head, int x);
void Print5(struct node5* head);
void ReversePrint5(struct node5* head);
//CASE 25
struct queue{
	int data;
	struct queue* next;
};

void Enqueue(struct queue** front, struct queue** rear, int x);

void Dequeue(struct queue** front, struct queue** rear);

void PrintQueue(struct queue* front);

int FrontQueue(struct queue **front);

//CASE 26
struct stack{
	int data;
	struct stack* next;
};

struct stack* Push(struct stack* top, int x);

struct stack* Pop(struct stack* top);

void PrintStack(struct stack* pop);

int main()
{
    int menu;
    do{
		system("cls");
        printf("|--------------------------------------------------------|\n");
        printf("|       Hello human being, what do you want to do?       |\n");
        printf("|[01] - THE SEQUENCE OF EXECUTION DURING A FUNCTION CALL |\n");
        printf("|[02] - FACTORIAL BY USING RECURSION                     |\n");
        printf("|[03] - STRANGE RECURSION                                |\n");
        printf("|[04] - FIBONACCI SERIES USING RECURSION                 |\n");
        printf("|[05] - MALLOC OR CALLOC (DYNAMIC MEMORY ALLOCATION)     |\n");
        printf("|[06] - REALLOC AND FREE   (DYNAMIC MEMORY ALLOCATION)   |\n");
        printf("|[07] - LINKED LIST (CIRCULAR LIST)                      |\n");
        printf("|[08] - INSERTING A NODE BY USING RECURSIVE PROGRAMS     |\n");
        printf("|[09] - SORTING, REVERSING AND DELETING A LINKED LIST    |\n");
        printf("|[10] - MALLOC, CALLOC, REALLOC AND FREE                 |\n");
        printf("|[11] - POINTERS AS FUNCTION RETURNS IN C                |\n");
        printf("|[12] - FUNCTION POINTERS                                |\n");
        printf("|[13] - FUNCTION POINTERS AND CALLBACKS                  |\n");
        printf("|[14] - SORTING ARRAY WITH CALLBACKS                     |\n");
        printf("|[15] - CALLBACKS (QUICKSORT)                            |\n");
        printf("|[16] - MEMORY LEAK                                      |\n");
		printf("|[17] - LINKED LIST - IMPLEMENTATION IN  C               |\n");
		printf("|[18] - INSERTING A NODE AT BEGINNING                    |\n");
		printf("|[19] - INSERT A NODE AT Nth POSITION                    |\n");
		printf("|[20] - INSERT AT THE END, DELETE A NODE AT Nth POSITION |\n");
		printf("|[21] - REVERSE A LINKED LIST - ITERATIVE METHOD         |\n");
		printf("|[22] - PRINT IN FORWARD/REVERSE ORDER USING RECURSION   |\n");
		printf("|[23] - REVERSE A LINKED LIST USING RECURSION            |\n");
		printf("|[24] - DOUBLY LINKED LIST - IMPLEMENTATION              |\n");
		printf("|[25] - IMPLEMENTATION OF QUEUE USING LINKED LIST        |\n");
		printf("|[26] - IMPLEMENTATION OF STACKS USING LIKED LIST        |\n");
		printf("|[27] -                                                  |\n");
		printf("|[28] -                                                  |\n");
		printf("|[29] -                                                  |\n");
        printf("|[0] - Exit                                              |\n");
        printf("|--------------------------------------------------------|\n");
        printf("\n\n");
        printf("Choice: ");
        scanf("%d", &menu);  //scanf(" %[^\n]", &string);
        switch(menu){
            case 1:
                {
                    //printf("\e[H\e[2J");
					system("cls");
                    int b;
                    do{

                        printf ("1 \n"); // 1
                        printf ("2 \n"); // 2
                        printf ("3 \n"); // 3
                        printf ("4 \n"); // 4
                        printf ("5 \n"); // 5
                        f1 ( );
                        printf ("6 \n"); // 6
                        printf ("7 \n"); // 7
                        printf ("8 \n"); // 8

                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);

                    break;
                }
            case 2:
                {
                    //printf("\e[H\e[2J");
					system("cls");
                    int n, k, b;
                    do{
					printf("Enter the value to get the respective factorial: ");
					scanf("%d", &n);
					system("cls");
					}while(n<0);
					k = factorial(n);
					do{
						printf("The factorial of number %d is: %d", n, k);
						
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
                    break;
                }
            case 3:
                {
                    //printf("\e[H\e[2J");
					system("cls");
                    int b;
					int k , i, m;
                    do{
						
						m=2;
						k=3;
						i=add(k,m);
						printf("The value of addition is %d\n",i);

					
						printf("\n\nBack[0]-> ");
						scanf("%d", &b);
						//printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
                    break;
                }
            case 4:
                {
                    //printf("\e[H\e[2J");
					system("cls");
                    int b;
					int i;
                    do{

						for (i = 0; i < 10; i++) {
							printf("%d\n", fibonacci(i));
						}
	
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
					system("cls");
                    }while(b!=0);
                    break;
                }
            case 5:
                {
                    //printf("\e[H\e[2J");
					system("cls");
                    int b;
					char name[100];
					char *description;
                    do{              

						strcpy(name, "Zara Ali");

						/* allocate memory dynamically */
						description = malloc( 200 * sizeof(char) );
						//description = calloc(200, sizeof(char));
						if( description == NULL ) {
							fprintf(stderr, "Error - unable to allocate required memory\n");
						} else {
							strcpy( description, "Zara ali a DPS student in class 10th");
						}
   
						printf("Name = %s\n", name );
						printf("Description: %s\n", description );

                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
					system("cls");
                    }while(b!=0);
                    break;
                }
			case 6:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					char name[100];
					char *description;
                    do{
                       						
						strcpy(name, "Zara Ali");

						/* allocate memory dynamically */
						description = malloc( 30 * sizeof(char) );
	
						if( description == NULL ) {
							fprintf(stderr, "Error - unable to allocate required memory\n");
						} else {
							strcpy( description, "Zara ali a DPS student.");
						}
	
						/* suppose you want to store bigger description */
						description = realloc( description, 100 * sizeof(char) );
	
						if( description == NULL ) {
							fprintf(stderr, "Error - unable to allocate required memory\n");
						} else {
							strcat( description, "She is in class 10th");
						}
   
						printf("Name = %s\n", name );
						printf("Description: %s\n", description );

						/* release memory using free() function */
						free(description);
						
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
					system("cls");
                    }while(b!=0);
					break;
				}
			case 7:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int n;
					int x;
					struct node *start = NULL ;                   
                do{       						
					printf("Enter the nodes to be created \n");
					scanf("%d",&n);
					system("cls");
					while ( n-- >0 ){
						printf( "Enter the data values to be placed in a node\n");
						scanf("%d",&x);
						start = insert ( start, x );
					}
					system("cls");
					//do{	
						printf("The created list is\n\n");
						printlist ( start );
						
						printf("\n\nAgain[Any key]");
                        printf("\nBack[0]\n");
						printf("-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 8:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int n;
					int x;
					struct node *start = NULL ;
					
                    do{
											
						printf("Enter the nodes to be created \n");
						scanf("%d",&n);
						system("cls");
						while ( n-- > 0 ){
							printf( "Enter the data values to be placed in a node\n");
							scanf("%d",&x);
							start = insert2 ( start, x );
						}
						system("cls");
						printf("The created list is\n");
						printlist2 ( start );
						
                        printf("\n\nAgain[Any key]");
                        printf("\nBack[0]\n");
						printf("-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 9:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int n;
					int x;
					struct node *start = NULL ;
					int d;
						
                    do{
                       					
						printf("Enter the nodes to be created \n");
						scanf("%d",&n);
						system("cls");
						while ( n-- > 0 ){
							printf( "Enter the data values to be placed in a node\n");
							scanf("%d",&x);
							start = insert3 ( start,x);
						}
						system("cls");
						printf("The created list is\n");
						printlist3 ( start );
						start = sortlist(start);
						printf("The sorted list is\n");
						printlist3 ( start );
						start = reverse(start);
						printf("The reversed list is\n");
						printlist3 ( start );
						
						printf("% \n Enter the node TO DELETE \n");
						scanf ( " %d",&d);
						start = delet (start , d );
						printf(" The list after deletion is\n");
						printlist3 ( start );
						
                        printf("\n\nAgain[Any key]");
                        printf("\nBack[0]\n");
						printf("-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 10:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int a;
					int *p;
					
					
					int n;
					int *array;
					int *array2;
					
					//int n;
					
                    do{
                       
						//MALLOC AND FREE
						//MALLOC INITIALIZE THE VARIABLE WITH GARBAGE MEMORY
						p = (int *) malloc(sizeof(int));
						*p = 10;
						printf("%d\n", *p);
						free(p);
						
						p = (int *) malloc(sizeof(int));
						*p = 20;
						printf("%d\n", *p);
						free(p);
						
						p = (int *) malloc(3*sizeof(int));
						*p = 2;
						*(p+1) = 4;
						*(p+2) = 6;
						for(int i=0; i<3; i++){
							printf("%d\n", *(p+i));
						}
						free(p);
						
						//CALLOC
						//CALLOC INITIALIZE THE VARIABLE WITH 0
						p = (int *) calloc(1, sizeof(int));
						*p = 10;
						printf("%d\n", *p);
						free(p);
						
						p = (int *) calloc(3, sizeof(int));
						*p = 2;
						*(p+1) = 4;
						*(p+2) = 6;
						for(int i=0; i<3; i++){
							printf("%d\n", *(p+i));
						}
						//free(p);
						
						//REALLOC
						p = (int*)realloc(p, 5*sizeof(int));
						*p = 2;
						*(p+1) = 4;
						*(p+2) = 6;
						*(p+3) = 8;
						*(p+4) = 10;
						for(int i=0; i<5; i++){
							printf("%d\n", *(p+i));
						}
						free(p);
						
						//Dynamically Allocated Array
						
						printf("Enter the size of array: ");
						scanf("%d", &n);
						//int a[n];   NOOO
						
						array = (int*)malloc(n*sizeof(int));
						for(int i=0; i<n; i++){
							array[i] = i + 1;
						}
						
						for(int i=0; i<n; i++){
							printf("%d \n", array[i]);
						}
						//free(array);
						//array = NULL; //After free, adjust pointer to NULL
						array2 = (int*) realloc(array, 2*n*sizeof(int));
						/*The realloc or can creat a new block and copy the elements of the previos to the new
						or can just extend the current block of memory to the new size*/
						printf("Previous block address = %d and new address = %d\n", array, array2);
						printf("The array with double size: \n");
						for(int i=0; i<2*n; i++){
							printf("%d \n", array2[i]);
						}
						
						array2 = (int*) realloc(array2, (n/2)*sizeof(int));
						printf("The array with half size: \n");
						for(int i=0; i<(n/2); i++){
							printf("%d \n", array2[i]);
						}
						
						/*
						This is equivalent to using free()
						array2 = (int*) realloc(array2, 0);
						*/
						
						/*
						This is equivalent to using malloc()
						array2 = (int*) realloc(NULL, n*sizeof(int));
						*/
                        printf("\n\nAgain[Any key]");
                        printf("\nBack[0]\n");
						printf("-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 11:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int x;
					int y;
					int *ptr;
					
                    do{
                       
						x = 2;
						y = 4;
						ptr = Add(&x, &y);
						PrintHelloWorld();
						printf("Sum = %d\n", *ptr);
						free(ptr);
						printf("Sum = %d\n", *ptr);
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 12:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int c;
					int (*p)(int, int);
					void (*ptr)(char*);
					
                    do{
                       
						p = &Add2; //&(ampersand) It's not necessary
						c = (*p)(2, 3); //*(asterisk) It's not necessary
						printf("%d\n", c);
						
						ptr = PrintHello;
						ptr("Tom");
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 13:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					void (*p)();
										
					
                    do{
                       
						p = A;		
						B(p);
						//You can simply write B(A)
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 14:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int i, A[] = {-31, 22, -1, 50, -6, 4};
					
					
                    do{
                      
						BubbleSort(A, 6, absolute_compare);
						for(i =0; i<6; i++){
							printf("%d \n", A[i]);
						}
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 15:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int i, A[] = {-31, 22, -1, 50, -6, 4};

					
                    do{
                       
						qsort(A, 6, sizeof(int), compare2);
						for(i =0; i<6; i++){
							printf("%d ", A[i]);
						}
						
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 16:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					int bet;
					
                    do{
						
						printf("**Welcome to the Virtual Casino**\n\n");
						printf("Total cash = $%d\n", cash);
						while(cash>0){
							printf("What's your bet? $");
							scanf("%d", &bet);
							if(bet==0 || bet> cash){
								break;
							}
							Play(bet);
							printf("\n*******************************\n");
						}
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 17:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					struct node1 *A;
					struct node1 *temp;
					struct node1 *temp2;
					
                    do{
                       
						A = NULL; //empty list
						temp = (struct node1*)malloc(sizeof(struct node1));
						//(*temp).data = 2;
						//(*temp).next = NULL;
						temp -> data = 2;
						temp -> next = NULL;
						A = temp;
						//printf("%d\n", A->data);
						
						temp = (struct node1*)malloc(sizeof(struct node1));
						temp -> data = 4;
						temp -> next = NULL;
						
						temp2 = A;
						while(temp2->next!=NULL){
							temp2 = temp2->next;
							//printf("%d\n", temp->data);
						}
						
						temp2 -> next = temp;
						
						temp = (struct node1*)malloc(sizeof(struct node1));
						temp -> data = 6;
						temp -> next = NULL;
						
						temp2 = A;
						while(temp2->next!=NULL){
							temp2 = temp2->next;
							//printf("%d\n", temp->data);
						}
						
						temp2 -> next = temp;
						
						while(A!=NULL){
							printf("%d\n", A->data);
							A = A->next;	
							
						}
						
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 18:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
															
                    do{
                       
						struct node2 *head = NULL; //empty list
						
						printf("How many numbers?");
						int n, x;
						scanf("%d", &n);
						
						for(int i=0; i<n; i++){
							printf("Enter the number:\n");
							scanf("%d", &x);
							head = Insert(head, x); 
							//You could have passed this particular variable head by reference
							//Insert(&head, x);
							Print(head);
						}
					   
                        printf("\n\nAgain[Any key]");
                        printf("\nBack[0]\n");
						printf("-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 19:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					
					
                    do{
                       
						struct node3* head = NULL; //empty list
						head = Insert2(head, 2,1); //List: 2
						head = Insert2(head, 3,2); //List: 2 3	
						head = Insert2(head, 4,1); //List: 4 2 3	
						head = Insert2(head, 5,2); //List: 4 5 2 3
						Print2(head);
						printf("Reversing using iterative method\n");
						head = ReverseList(head);  //List: 3 2 5 4
						Print2(head);
						
						printf("Print using recursion\n");
						PrintUsingRecursion(head);
						/*To print int reverse order you need only change the order inside the function,
						that is, the recusion function call come first and the printf after*/
						printf("Reversing using recursion\n");
						head = ReverseUsingRecursion(head);
						PrintUsingRecursion(head);
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 20:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					
					
                    do{
                       
						struct node4* head = NULL; //empty list
						
						head = Insert3(head, 2);
						head = Insert3(head, 4);
						head = Insert3(head, 6);
						head = Insert3(head, 5); //List: 2, 4, 6, 5
						Print4(head);
						int n;
						printf("Enter a position to delete: ");
						scanf("%d", &n);
						head = Delete2(head, n);
						Print4(head);
					   
                        printf("\n\nAgain[Any key]");
                        printf("\nBack[0]\n");
						printf("-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 21:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
                    do{
						//struct node* head = NULL;
						//head = Reverse(head);
					    //Here is only the function to reverse, if you want to look up to it, it's being used in the 19th case
						printf("//Here is only the function to reverse, , if you want to look up to it, it's being used in the 19th case");
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 22:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					
					
                    do{
						//struct node* head = NULL;
						//PrintUsingRecursion(head);
					    //Here is only the function USING RECURSION, if you want to look up to it, it's being used in the 19th case
						printf("//Here is only the function USING RECUSION, , if you want to look up to it, it's being used in the 19th case");
						
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 23:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					
					
                    do{
                       
						//struct node* head = NULL;
						//head = ReverseUsingRecursion(head);
					    //Here is only the function to REVERSE USING RECURSION, if you want to look up to it, it's being used in the 19th case
						printf("//Here is only the function to REVERSE USING RECUSION, , if you want to look up to it, it's being used in the 19th case");
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 24:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					
					
                    do{
                       
						struct node5* head = NULL;
						
						head = InsertAtHead5(head, 2);
						head = InsertAtHead5(head, 4);
						head = InsertAtHead5(head, 6);  //List: 2, 4, 6
						
						head = InsertAtTail5(head, 1);
						head = InsertAtTail5(head, 3);
						head = InsertAtTail5(head, 5); //List: 2, 4, 6, 1, 3, 5

						Print5(head);
						
						ReversePrint5(head);
						
					   
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 25:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
							
                    do{
						struct queue* front = NULL;
						struct queue* rear = NULL;
					   
						Enqueue(&front, &rear, 2);
						Enqueue(&front, &rear, 4);
						Enqueue(&front, &rear, 6);
						
						printf("After insert a queue: ");
						PrintQueue(front);
						
						printf("After delete a queue: ");
						Dequeue(&front, &rear);
						
						PrintQueue(front);
						
						printf("After insert again: ");
						Enqueue(&front, &rear, 8);
						PrintQueue(front);
						
						
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}
			case 26:
				{
					//printf("\e[H\e[2J");
					system("cls");
                    int b;
					
					
					
                    do{
                       
						struct stack* top = NULL;
						
						top = Push(top, 2);
						top = Push(top, 2);
						top = Push(top, 2);
						PrintStack(top);
						
						top = Pop(top);
						PrintStack(top);

						
                        printf("\n\nBack[0]-> ");
                        scanf("%d", &b);
                        //printf("\e[H\e[2J");
						system("cls");
                    }while(b!=0);
					break;
				}	
            default:
                {
					system("cls");
					printf("\n\nThank you human!!!\nSee you soon!!!\n\n");
                    break;
                }
        }
    }while(menu!=0);
	//system("pause");
    return 0;
}

//CASE 1
void f1 ()
{
printf ("f1-9 \n"); // 9
printf ("f1-10 \n"); // 10
f2 ( );
printf ("f1-11 \n"); // 11
printf ("f1-12 \n"); // 12
}
void f2 ()
{
printf ("f2-13 \n"); // 13
printf ("f2-14 \n"); // 14
printf ("f3-15 \n"); // 15
}

//CASE 2
int factorial(int n){
    if (n==0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

//CASE 3
int add(int pk,int pm){
	if(pm==0){
		return(pk);
	}
	else{
		return(1+add(pk,pm-1));
	}		
}

//CASE 4
int fibonacci(int i) {

   if(i == 0) {
      return 0;
   }
	
   if(i == 1) {
      return 1;
   }
   return fibonacci(i-1) + fibonacci(i-2);
}

//CASE 5

//CASE 6

//CASE 7
struct node *insert(struct node *p, int n){
	struct node *temp;
	/* if the existing list is empty then insert a new node as the
	starting node */
	if(p==NULL){
		p=(struct node *)malloc(sizeof(struct node)); /* creates new node
		data value passes
		as parameter */
		if(p==NULL){
			printf("Error\n");
			exit(0);
		}
		p-> data = n;
		p-> link = p; /* makes the pointer pointing to itself because it
		is a circular list*/
	}else{
		temp = p; 
		/* traverses the existing list to get the pointer to the last node of
		it */
		while (temp-> link != p)
			temp = temp-> link;
		temp-> link = (struct node *)malloc(sizeof(struct node)); /*
			creates new node using
			data value passes as
			parameter and puts its
			address in the link field
			of last node of the
			existing list*/
		if(temp -> link == NULL){
			printf("Error\n");
			exit(0);
		}
		temp = temp-> link;
		temp-> data = n;
		temp-> link = p;
	}

	return (p);
}
void printlist ( struct node *p ){
	struct node *temp;
	temp = p;
	printf("The data values in the list are\n");
	if(p!= NULL){
		do{
			printf("%d\t",temp->data);
			temp=temp->link;
		} while (temp!= p);
	}else
		printf("The list is empty\n\n");
}

//CASE 8

struct node *insert2(struct node *p, int n){
	struct node *temp;
	if(p==NULL){
		p=(struct node *)malloc(sizeof(struct node));
		if(p==NULL){
			printf("Error\n");
			exit(0);
		}
		p-> data = n;
		p-> link = NULL;
	}else
		p->link = insert2(p->link,n);/* the while loop replaced by
		recursive call */
	return (p);
}
void printlist2 ( struct node *p ){
	printf("The data values in the list are\n");

	while (p!= NULL){
		printf("%d\t",p-> data);
		p = p-> link;
	}
}

//CASE 9
struct node *insert3(struct node *p, int n){
	struct node *temp;
	if(p==NULL){
		p=(struct node *)malloc(sizeof(struct node));
		if(p==NULL){
			printf("Error\n");
			exit(0);
		}
		p-> data = n;
		p-> link = NULL;
	}else{
		temp = p;
		while (temp-> link!= NULL)
			temp = temp-> link;
		temp-> link = (struct node *)malloc(sizeof(struct node));
		if(temp -> link == NULL){
			printf("Error\n");
			exit(0);
		}
		temp = temp-> link;
		temp-> data = n;
		temp-> link = NULL;
	}
	return(p);
}

void printlist3 ( struct node *p ){
	printf("The data values in the list are\n");
	while (p!= NULL){
		printf("%d\t",p-> data);
		p = p-> link;
	}
	printf("\n");
}

/* a function to sort reverse list */
struct node *reverse(struct node *p){
	struct node *prev, *curr;
	prev = NULL;
	curr = p;
	while (curr != NULL){
		p = p-> link;
		curr-> link = prev;
		prev = curr;
		curr = p;
	}
	//HERE, you need to think for yourself first how to revese two nodes
	//and after you need to draw down this thoughts (how to reverse onde node and two nodes

	return(prev);
}

/* a function to sort a list */
struct node *sortlist(struct node *p){
	struct node *temp1,*temp2,*min,*prev,*q;
	q = NULL;
	while(p != NULL){
		prev = NULL;
		min = temp1 = p;
		temp2 = p -> link;
		while ( temp2 != NULL ){
			if(min -> data > temp2 -> data){
				min = temp2;
				prev = temp1;
			}
			temp1 = temp2;
			temp2 = temp2-> link;
		}
		if(prev == NULL)
			p = min -> link;
		else
			prev -> link = min -> link;
		min -> link = NULL;
		if( q == NULL)
			q = min; /* moves the node with lowest data value in the list
pointed to by p to the list
pointed to by q as a first node*/
		else{
			temp1 = q;
/* traverses the list pointed to by q to get pointer to its
last node */
			while( temp1 -> link != NULL)
				temp1 = temp1 -> link;
			temp1 -> link = min; /* moves the node with lowest data value
in the list pointed to
by p to the list pointed to by q at the end of list pointed by
q*/
		}
	}
	return (q);
}

/* a function to delete the specified node*/
struct node *delet ( struct node *p, int node_no ){
	struct node *prev, *curr ;
	int i;
	if (p == NULL ){
		printf("There is no node to be deleted \n");
	}else{
		if ( node_no > length (p)){
			printf("Error\n");
		}else{
			prev = NULL;
			curr = p;
			i = 1 ;
			while ( i < node_no ){
				prev = curr;
				curr = curr-> link;
				i = i+1;
			}
			if ( prev == NULL ){
				p = curr -> link;
				free ( curr );
			}else{
				prev -> link = curr -> link ;
				free ( curr );
			}
		}
	}
	return(p);
}
/* a function to compute the length of a linked list */
int length ( struct node *p ){
	int count = 0 ;
	while ( p != NULL ){
		count++;
		p = p->link;
	}
	return ( count ) ;
}

//CASE 10

//CASE 11
int *Add(int *x, int *y){
	int *z = (int*)malloc(sizeof(int));
	*z = (*x) + (*y);
	return z;
}

void PrintHelloWorld(){
	printf("Hello World\n");
}

//CASE 12
int Add2(int a, int b){
	return a + b;
}
void PrintHello(char *name){
	printf("Hello %s\n", name);
}

//CASE 13
void A(){
	printf("Hello\n");
}
void B(void (*ptr)()){
	ptr();
}

//CASE 14
int compare(int a, int b){
	if(a>b){
		return -1;	
	}else{
		return 1;
	}
	/*//Now, you need only change the sign to choose if you 
	want to put the array in increasing order or decreasing*/
}
int absolute_compare(int a, int b){
	if(abs(a) > abs(b)){
		return 1;
	}
	return -1;
}
void BubbleSort(int *A, int n, int (*compare)(int ,int)){
	int i, j, temp;
	for(i =0; i<n ;i++){
		for(j = 0; j<n-1; j++){
			if(compare(A[j], A[j+1]) > 0){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

//CASE 15
int compare2(const void *a, const void *b){
	int A = *((int*)a);
	int B = *((int*)b);
	return A-B;
}

//CASE 16
void Play(int bet){
	//char C[3] = {'J', 'Q', 'K'};
	char *C = (char*)malloc(3*sizeof(char));
	C[0] = 'J';
	C[1] = 'Q';
	C[2] = 'K';
	printf("Shuffling . . .\n");
	srand(time(NULL));
	for(int i=0; i<5; i++){
		int x = rand() % 3;
		int y = rand() % 3;
		int temp = C[x];
		C[x] = 	C[y];
		C[y] = temp;		
	}
	int playerGuess;
	printf("What's the position of Queen, 1, 2 or 3? ");
	scanf("%d", &playerGuess);
	if(C[playerGuess - 1] == 'Q'){
		cash += 3*bet;
		printf("You win! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
	}else{
		cash -= bet;
		printf("You Loose! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
	}
	free(C);
}

//CASE 17

//CASE 18
/*
	You need do use void if you want statement head as a global variable or if you
	pass the address of head as reference, like this:
	void Insert(struct node2** pointerToHead, int x){...
	And all places you will must dereference pointerToHead, that is, *pointerToHead
*/
struct node2* Insert(struct node2 *head, int x){ 
	struct node2 *temp = (struct node2*)malloc(sizeof(struct node2));
	temp -> data = x;
   /*temp -> next = NULL;
	if(head!=NULL){
		temp->next = head;
	}*/
	temp -> next = head;
	head = temp;
	return head;
}

void Print(struct node2 *head){
	//struct node2 *temp = head; If you statement head as a global variable you need to do this
	printf("Lists is: ");
	while(head!=NULL){
		printf(" %d", head->data);
		head = head -> next;
	}
	printf("\n");
}
//CASE 19
struct node3* Insert2(struct node3* head, int data, int n){
	struct node3* temp1 = (struct node3*)malloc(sizeof(struct node3));
	temp1->data = data;
	temp1->next = NULL;
	if(n==1){
		temp1->next = head;
		head = temp1;
		return head;
	}
	struct node3* temp2 = head;
	for(int i=1; i<n-1; i++){
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
	return head;
}

void Print2(struct node3* head){
	//struct node3* temp = head;
	while(head!=NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
//case  21
struct node3* ReverseList(struct node3* head){
	struct node3 *current, *prev, *next;
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

//case 22
void PrintUsingRecursion(struct node3* head){ //Recursion Tree
	if(head==NULL){ //Exit condition
		printf("\n");
		return;
	}
	/*To print int reverse order you need only change the order, that is,
	the recusion function call come first and the printf after*/
	//PrintUsingRecursion(head->next); //Recursive call
	printf("%d ", head->data); //First print the value in the node
	PrintUsingRecursion(head->next); //Recursive call
}

//case 23
struct node3* ReverseUsingRecursion(struct node3* head){
	struct node3* temp = head;
	if(temp->next==NULL){
		head = temp;
		return head;
	}
	head = ReverseUsingRecursion(temp->next);
	//temp->next->next = temp;
	struct node3* q = temp->next;
	q->next = temp;
	temp->next = NULL;
	
	return head;
}

//CASE 20
struct node4* Insert3(struct node4* head, int data){ //Insert an integer at end of the list
	struct node4* temp1 = (struct node4*)malloc(sizeof(struct node4));
	temp1->data = data;
	temp1->next = NULL;
	if(head==NULL){
		//temp1->next = NULL;
		head = temp1;
		return head;
	}
	struct node4* temp2 = head;
	while(temp2->next!=NULL){
		temp2 = temp2->next;
	}
	temp2->next = temp1;
	//temp1->next = NULL;
	
	return head;
	
}

void Print4(struct node4* head){ //Print all elements in the list
	while(head!=NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

struct node4* Delete2(struct node4* head, int n){  //Delete node at postion n
	struct node4* temp1 = head;
	if(n==1){
		head = temp1->next;
		free(temp1);
		return head;
	}
	for(int i=0; i<n-2; i++){
		temp1 = temp1->next;	//temp1 points to (n-1)th node
	}
	struct node4* temp2 = temp1->next; //nth node
	temp1->next = temp2->next; //(n+1)th node
	free(temp2); ////delete temp2 == nth node
	return head;
}

//CASE 21
//Go to CASE 19

//CASE 22
//go to CASE 19

//CASE 23
//go to CASE 19

//CASE 24
struct node5* GetNewNode(int x){
	struct node5* newNode = (struct node5*)malloc(sizeof(struct node5));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;
}

struct node5* InsertAtHead5(struct node5* head, int x){
	struct node5* newNode = GetNewNode(x);
	if(head == NULL){
		head = newNode;
		return head;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
	
	return head;
}

struct node5* InsertAtTail5(struct node5* head, int x){
	struct node5* temp = head;
	struct node5* newNode = GetNewNode(x);
	if(head == NULL){
		head = newNode;
		return head;
	}
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	
	return head;
}

void Print5(struct node5* head){
	printf("Forward: ");
	while(head!=NULL){
		printf("%d", head->data);
		head = head->next;
	}
	printf("\n");
}

void ReversePrint5(struct node5* head){
	if(head == NULL){
		return;
	}
	while(head->next !=NULL){
		head = head->next;
	}
	
	printf("Reverse: ");
	while(head!=NULL){
		printf("%d", head->data);
		head = head->prev;
	}
	printf("\n");
}

//CASE 25
void Enqueue(struct queue** front, struct queue** rear, int x){
	struct queue* temp1 = (struct queue*)malloc(sizeof(struct queue));
	temp1->data = x;
	temp1->next = NULL;
	
	if(*front == NULL && *rear == NULL){
		*front = *rear = temp1;
		//return;
	}else{
		(*rear)->next = temp1;
		*rear = temp1;
		//return;
	}
	
}

void Dequeue(struct queue** front, struct queue** rear){
	struct queue* temp1 = *front;
	if(*front==NULL){
		printf("Ei, what do you want to do is impossible, because the list is empty, ie, there's no way to delete what doesn't exist!!!\n");
	}else if(*front == *rear){
		*front = *rear = NULL;
	}else{
		*front = (*front)->next;
	}
	free(temp1);
}

void PrintQueue(struct queue* front){
	if(front==NULL){
		printf("The queue is empty!!!\n");
	}else{
		printf("The queue is: ");
		while(front!=NULL){
			printf("%d ", front->data);
			front = front->next;
		}
		printf("\n");
	}
}

int FrontQueue(struct queue **front){
	if(*front == NULL) {
		printf("Queue is empty\n");
	}else{
		return (*front)->data;
	}
}
//CASE 26
struct stack* Push(struct stack* top, int x){
	struct stack* temp1 = (struct stack*)malloc(sizeof(struct stack));
	
	temp1->data = x;
	temp1->next = top;
	top = temp1;
	
	return top;
}

struct stack* Pop(struct stack* top){
	if(top==NULL){
		printf("The stack is empty!!!");
	}else{
		struct stack* temp1 = top;
	
		top = top->next;
		free(temp1);
	}
	
	return top;
}

void PrintStack(struct stack* top){
	if(top==NULL){
		printf("The stack is empty!!!");
	}else{
		printf("The created stack is: ");
		while(top!=NULL){
			printf("%d ", top->data);
			top = top->next;
		}
		printf("\n");
	}
}

/*
int IsEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int Top()
{
    return (top->data);

}

*/