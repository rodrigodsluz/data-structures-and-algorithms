// ADT for linked binary tree

//Libraries in the system
#include <stdio.h>
#include <stdlib.h>
//Library in the project
#include "adt.h"

// Definition of struct node
struct node{
  int value;
  struct node *left;
  struct node *right;
};

// Function to allocate memory
BinaryTree* createBinaryTree()
{
  // 'root' is a pointer to pointer of type node
  BinaryTree *root = (BinaryTree*) malloc(sizeof(BinaryTree));  

  // if the allocation is correct 'root' points to NULL (empty binary tree)
  if(root != NULL){
    *root = NULL;
  }

  return root;
}

// Function to deallocate memory of one node of Binary Tree
void freeNode(Node *node)
{
  if(node == NULL)
    return;

  freeNode(node->left);
  freeNode(node->right);
  free(node);
  node = NULL;
}


// Function to deallocat memory of Binary Tree
int freeBinaryTree(BinaryTree *root){
  if(root == NULL)
    return 0;

  freeNode(*root); //free each node
  free(root); // free the root

  return 1;
}

// Function to insert elements in a Binary Search Tree
int insertNode(BinaryTree *root, int value){
  if(root == NULL)
    return 0;

  // Create a node
  Node *new = (Node*) malloc(sizeof(Node));

  // Verify if the memory was correct allocated
  if(new == NULL){
    return 0;
  }  

  // Fill fields of new created node 
  new->value = value;
  new->left = NULL;
  new->right = NULL;

  // If the tree is empty, root get the new node
  if(*root == NULL){
    *root = new;

  }else{
    Node *current = *root;
    Node *previous = NULL;

    // travel through the tree until find the NULL position according with the desired order
    while(current != NULL){

      previous = current;

      // Verify if the value already exists in the tree
      if(value == current->value){
        free(new);
        return 0; 
      }
      
      // Identify which subtree will travel 
      if(value < current->value){
        current = current->left;
      }else{
        current = current->right;
      }
    }

    // Verify for which child will assign the new node
    if(value < previous->value){
      previous->left = new;
    }else{
      previous->right = new;
    }
  }

  return 1;

}

// Function for remotion of root
int removeFather(Node *current)
{
  Node *node1, *node2;

  // Verify if the current there's no left child 
  if(current->left == NULL){
    node2 = current->right;
    free(current); // Free memory of current node

    // return node2, right child, as subtstitute node of removed node
    return node2;
  }
  
  node1 = current;
  node2 = current->left;

  // Search the node rightmost of current node, node2     
  while(node2->right != NULL){
    node1 = node2;      // Store the father of node 2
    node2 = node2->right;
  }

  // verifica se o pai do nó mais a direita é diferente do atual, a ser removido
  if(no1 != atual){
    // subarvore da esquerda do "no2" se torna a subarvore da direita do "no1"
    no1->dir = no2->esq;

    // subarvore da esquerda do "atual" se torna a subarvore da esquerda do "no2"
    no2->esq = atual->esq;
  }

  // subarvore da direita do "atual" se torna a subarvore da direita do "no2"
  no2->dir = atual->dir;

  free(atual); // libera memória do nó atual

  // retorna "no2" como nó substituto do nó removido
  return no2;
}

// Function for remotion of Binary Search Tree elements
int removeNode(BinaryTree *root, int value){
    if(root == NULL)
    return 0;

    Node *previous = NULL;    // father node of current node 
    Node *current = *root; // current node

    // Walk through the binary tree until find the node to be removed 
    while(current != NULL){

    // Verify if the searched value was found  
    if(value == current->value){

      // Verify if the node to be removed is the own root 
      if(current == *root){
      *root = removeFather(current); // remove the main father and update the tree 

      }else{

        if(ant->dir == atual){
          ant->dir = remover_no(atual); // remove o nó e atualiza a arvore
        }else{
          ant->esq = remover_no(atual); // remove o nó e atualiza a arvore
        }   
             
      }

      // nó a ser removido foi encontrado e removido corretamente
      return 1;
    }

    // se o nó atual não é o nó procurado
    // "ant" recebe "atual" e "atual" recebe um de seus filhos
    ant = atual;

    // verifica em qual subarvore o valor procurado pode estar
    // e atualiza o nó atual para o filho da direita ou da esquerda
    if(valor > atual->valor){
      atual = atual->dir;
    }else{
      atual = atual->esq;
    }

  }

  // nó a ser removido não existe na árvore
  return 0;
}

// função calcula o total de nós da arvore binaria
int quantidade_nos_arvore_binaria(ArvoreBin *raiz)
{
  // se o ponteiro for nulo ou se a arvore estiver vazio
  if(raiz == NULL || *raiz == NULL)
    return 0;

  // calcula o numero de nos na subarvore esquerda
  int total_esq = quantidade_nos_arvore_binaria(&((*raiz)->esq));

  // calcula o numero de nos na subarvore direita
  int total_dir = quantidade_nos_arvore_binaria(&((*raiz)->dir));

  // total é a quantidade de nos das subarvores mais a raiz  
  return (total_esq + total_dir + 1);
}


// funcao que calcula a altura da arvore binaria
int altura_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 0;

  // calcula a altura da subarvore esquerda
  int alt_esq = altura_arvore_binaria(&((*raiz)->esq));

  // calcula a altura da subarvore direita
  int alt_dir = altura_arvore_binaria(&((*raiz)->dir));

  // altura da arvore é a altura da maior subarvore mais a raiz 
  if(alt_esq > alt_dir) 
    return (alt_esq + 1);
  else
    return (alt_dir + 1);
}

// funcao retorna 1 se não houver nós na arvore
int esta_vazia_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL || *raiz == NULL)
    return 1;

  return 0;
}








// função para buscar elementos na arvore binaria
int consultar_arvore_binaria(ArvoreBin *raiz, int valor)
{
  if(raiz == NULL)
    return 0;
  
  No *atual = *raiz;

  // percorre a arvore binaria até encontrar o valor desejado   
  while(atual != NULL){

    // retorna 1 quando encontra o valor
    if(valor == atual->valor){
      return 1;
    }

    // identifica a subarvore pela qual irá percorrer
    if(valor < atual->valor){
      atual = atual->esq;
    }else{
      atual = atual->dir;
    }
  }

  return 0;
}

// função para percorrer a arvore binaria em ordem
void percorrer_em_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_em_ordem_arvore_binaria(&((*raiz)->esq));
    printf("%d\n", (*raiz)->valor);
    percorrer_em_ordem_arvore_binaria(&((*raiz)->dir));    
  }
}

// função para percorrer a arvore binaria em pré ordem
void percorrer_pre_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    printf("%d\n", (*raiz)->valor);
    percorrer_pre_ordem_arvore_binaria(&((*raiz)->esq));
    percorrer_pre_ordem_arvore_binaria(&((*raiz)->dir));    
  }
}

// função para percorrer a arvore binaria em pós ordem
void percorrer_pos_ordem_arvore_binaria(ArvoreBin *raiz)
{
  if(raiz == NULL)
    return;

  if(*raiz != NULL){
    percorrer_pos_ordem_arvore_binaria(&((*raiz)->esq));
    percorrer_pos_ordem_arvore_binaria(&((*raiz)->dir)); 
    printf("%d\n", (*raiz)->valor);   
  }
}
