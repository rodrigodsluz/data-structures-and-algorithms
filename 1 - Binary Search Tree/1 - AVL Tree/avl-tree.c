/*
	Trabalho 06 - Árvore AVL
    
    Rodrigo Duarte Silva Luz - 2019003520
	Yasmin Karolyne Aniceto- 2018010440
	Matheus de Souza - 2019005909
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *pno;

typedef struct Node
{
    int key;
    pno esq;
    pno dir;
    int alt;
} Node;

pno criar_no(int c)
{
    pno aux = (pno)malloc(sizeof(Node));
    aux->key = c;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->alt = 0;
    return aux;
}

int altura(pno n)
{
    if (n == NULL)
        return -1;
    else
        return n->alt;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

pno rotaciona_direita(pno n)
{
    pno aux;
    aux = n->esq;
    n->esq = aux->dir;
    aux->dir = n;

    n->alt = max(altura(n->esq), altura(n->dir)) + 1;
    aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

    return (aux);
}

pno rotaciona_esquerda(pno n)
{
    pno aux;
    aux = n->dir;
    n->dir = aux->esq;
    aux->esq = n;

    n->alt = max(altura(n->esq), altura(n->dir)) + 1;
    aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

    return (aux);
}

pno rotaciona_esquerda_direita(pno n)
{
    n->esq = rotaciona_esquerda(n->esq);
    pno aux = rotaciona_direita(n);
    return aux;
}

pno rotaciona_direita_esquerda(pno n)
{
    n->dir = rotaciona_direita(n->dir);
    pno aux = rotaciona_esquerda(n);
    return aux;
}

void print_arvore(pno arv)
{
    if (arv == NULL)
        return;
    printf("(%d, ", arv->key);
    print_arvore(arv->esq);
    printf(", ");
    print_arvore(arv->dir);
    printf(")");
    return;
}

int fator_balanceamento(pno n)
{
    if (n == NULL)
        return 0;
    return (altura(n->dir) - altura(n->esq));
}

pno put(pno arvore, int c)
{
    //IMPLEMENTAÇÃO
    if (arvore == NULL)
        return (criar_no(c));
    if (arvore->key == c)
    {
        printf("Essa key já existe\n");
        return arvore;
    }
    if (arvore->key > c)
    {
        //add no lado esquerdo
        arvore->esq = put(arvore->esq, c);
        //se a esquerda tiver 2 vezes mais altura
        if (fator_balanceamento(arvore) == -2)
        {
            if (c < arvore->esq->key)
                arvore = rotaciona_direita(arvore);
            else
                arvore = rotaciona_esquerda_direita(arvore);
        }
    }
    if (arvore->key < c)
    {
        //add no lado direito
        arvore->dir = put(arvore->dir, c);
        //se tiver 2 vezes mais altura
        if (fator_balanceamento(arvore) == 2)
        {
            if (c > arvore->dir->key)
                arvore = rotaciona_esquerda(arvore);
            else
                arvore = rotaciona_direita_esquerda(arvore);
        }
    }
    arvore->alt = max(altura(arvore->esq), altura(arvore->dir)) + 1;
    return (arvore);
}

Node *find(Node *h, int key)
{
    // IMPLEMENTAÇÃO
    if (h == NULL)
        return 0;

    Node *current = h;

    // Busca a key desejada percorrendo a árvore binária
    while (current != NULL)
    {
        // retorna current quando encontra já a key
        if (key == current->key)
        {
            return current;
        }

        // Essas são as subárvores pela qual irá percorrer
        if (key < current->key)
        {
            current = current->esq;
        }
        else
        {
            current = current->dir;
        }
    }

    return 0;
}

void print_tree(Node *h)
{
    // IMPLEMENTAÇÃO
    if (h == NULL)
        return;

    printf("(");
    print_tree(h->esq);
    printf(";%d;", h->key);
    print_tree(h->dir);
    printf(")");
    return;
}

Node *libera_arvore(Node *h)
{
    //IMPLEMENTAÇÃO
    if (h != NULL)
    {
        libera_arvore(h->esq); //libera filhos a esqurda
        libera_arvore(h->dir); // libera filhos a direita
        free(h);               //Libera a raíz
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    Node *arvore = NULL;

    char c;
    int key;
    do
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &key);
            arvore = put(arvore, key);
            break;
        case 'b':
            scanf("%d", &key);
            Node *no = find(arvore, key);
            if (no != NULL)
                printf("%d\n", key);
            break;
        case 'p':
            print_tree(arvore);
            printf("\n");
            break;
        case 'x':
            //saindo nada a fazer
            break;
        default:
            printf("comando nao encontrado: %c", c);
        }
        getchar(); //le o enter
    } while (c != 'x');

    arvore = libera_arvore(arvore);

    return 0;
}
