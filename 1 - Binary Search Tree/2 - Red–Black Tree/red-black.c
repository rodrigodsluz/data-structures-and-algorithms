/*
	Trabalho 05 - Árvores rubro-negro esquerdista
    
    Rodrigo Duarte Silva Luz - 2019003520
	Yasmin Karolyne Aniceto- 2018010440
	Matheus de Souza - 2019005909
*/

#include <stdlib.h>
#include <stdio.h>

enum Cor
{
    RED,
    BLACK
};

typedef struct Node
{
    int key;
    struct Node *esq;
    struct Node *dir;
    enum Cor cor;
} Node;

Node *cria_no(int key, enum Cor cor)
{
    Node *no = malloc(sizeof(Node));
    no->key = key;
    no->cor = cor;
    return no;
}

int isRed(Node *x)
{
    if (x == NULL)
        return 0;
    return x->cor == RED;
}

Node *rotateLeft(Node *h)
{
    Node *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = RED;
    return x;
}

Node *rotateRight(Node *h)
{
    // IMPLEMENTAÇÃO
    Node *x = h->esq;
    h->esq = x->dir;
    x->dir = h;

    x->cor = h->cor;
    h->cor = RED;
    return x;
}

void flipColors(Node *h)
{
    h->cor = RED;
    h->esq->cor = BLACK;
    h->dir->cor = BLACK;
}

Node *put(Node *h, int key)
{
    if (h == NULL)
        return cria_no(key, RED);

    if (key < h->key)
        h->esq = put(h->esq, key);
    else
        h->dir = put(h->dir, key);

    if (isRed(h->dir) && !isRed(h->esq))
        h = rotateLeft(h);
    if (isRed(h->esq) && isRed(h->esq->esq))
        h = rotateRight(h);
    if (isRed(h->esq) && isRed(h->dir))
        flipColors(h);
    return h;
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

Node *find(Node *h, int key)
{
    // IMPLEMENTAÇÃO
    if (h == NULL)
        return 0;

    Node *current = h;

    // Busca a key desejada percorrendo a árvore binária
    while (current != NULL)
    {
        // retorna current quando encontra já key
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
                printf("%d\n", no->key);
            break;
        case 'p':
            print_tree(arvore);
            printf("\n");
            break;
        case 'x':
            //saindo, nada a fazer
            break;
        default:
            printf("comando nao encontrado: %c", c);
        }
        getchar(); //le e descarta o enter
    } while (c != 'x');

    return 0;
}
