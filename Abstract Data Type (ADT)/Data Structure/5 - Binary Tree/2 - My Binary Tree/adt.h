// ADT for linked binary tree
#ifndef _BINARY_TREE_
#define _BINARY_TREE_

// Definition of abstracts type
typedef struct node Node;
typedef Node* BinaryTree;

// Functions to allocate e deallocate memory
BinaryTree  *createBinaryTree();
int freeBinaryTree(BinaryTree *root);

// Function to insert elements in Binary Tree
int insertNode(BinaryTree *root, int value);

// funções para obter informações da arvore binaria
int quantidade_nos_arvore_binaria(ArvoreBin *raiz);
int altura_arvore_binaria(ArvoreBin *raiz);
int esta_vazia_arvore_binaria(ArvoreBin *raiz);



// função para remoção de elementos da arvore binaria
int remover_arvore_binaria(ArvoreBin *raiz, int valor);

// função para buscar elementos na arvore binaria
int consultar_arvore_binaria(ArvoreBin *raiz, int valor);

// funções para percorrer a arvore binaria
void percorrer_em_ordem_arvore_binaria(ArvoreBin *raiz);
void percorrer_pre_ordem_arvore_binaria(ArvoreBin *raiz);
void percorrer_pos_ordem_arvore_binaria(ArvoreBin *raiz);

#endif