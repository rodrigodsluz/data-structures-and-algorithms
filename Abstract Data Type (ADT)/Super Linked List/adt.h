typedef struct student Student;
typedef struct node *Node;

Node *createNode();

int freeNode(Node *head);

int registration(Student **student);