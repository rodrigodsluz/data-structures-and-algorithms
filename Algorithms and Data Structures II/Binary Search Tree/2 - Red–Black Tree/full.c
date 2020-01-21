#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* IMPLEMENTAÇÃO ARVORE RUBRO NEGRA ESQUERDISTA - FALTA A REMOÇÃO */

enum Cor{VERMELHO, PRETO};

typedef struct No{
    int chave;
    char nome[50];
    enum Cor cor;
    struct No *esq, *dir;
}No;

typedef No *pno;

/****************************************************************************/
int ehVermelho(pno x)
{
    if (x==NULL) return 0;
    return x->cor == VERMELHO;
}

/****************************************************************************/
int ehPreto(pno x)
{
    if(x==NULL) return 1;
    return x->cor == PRETO;
}

/****************************************************************************/
pno rotaciona_esquerda(pno raiz)
{
    pno x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;

    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

/****************************************************************************/
pno rotaciona_direita(pno raiz)
{
    pno x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;

    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

/****************************************************************************/
void sobe_vermelho(pno raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

/****************************************************************************/
pno inserir_recursivo(pno raiz, int chave, char nome[])
{
    pno novo;
    if (raiz == NULL){
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        strcpy(novo->nome, nome);
        novo->cor = VERMELHO;
        return novo;
    }

    if (chave < raiz->chave)
        raiz->esq = inserir_recursivo(raiz->esq, chave, nome);
    else
        raiz->dir = inserir_recursivo(raiz->dir, chave, nome);

    //CORRRIGI ARVORE
    if(ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        raiz = rotaciona_esquerda(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotaciona_direita(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        sobe_vermelho(raiz);

    return raiz;
}

pno insere(pno raiz, int chave, char nome[])
{
    raiz = inserir_recursivo(raiz, chave, nome);
    raiz->cor = PRETO;
    return raiz;
}

/****************************************************************************/
int consulta(pno raiz, int chave, char nome[])
{
  int achou = -1;
  if (raiz->chave == chave){
    strcpy(nome, raiz->nome);
    return 1;
  }
  if(raiz->chave > chave){
    if(raiz->esq == NULL)
      return -1;
    achou = consulta(raiz->esq, chave, nome);
  }
  if(raiz->chave < chave){
    if(raiz->dir == NULL)
      return -1;
    achou = consulta(raiz->dir, chave, nome);
  }

  return achou;
}

/****************************************************************************/
void imprime_em_ordem(pno raiz)
{
  if(raiz == NULL) return;
  imprime_em_ordem(raiz->esq);
  printf(" %d %s \n", raiz->chave, raiz->nome);
  imprime_em_ordem(raiz->dir);
  return;
}

void imprime_pre_ordem(pno raiz)
{
  if(raiz == NULL) return;
  printf(" %d %s \n", raiz->chave, raiz->nome);
  imprime_pre_ordem(raiz->esq);
  imprime_pre_ordem(raiz->dir);
  return;
}

void imprime_pos_ordem(pno raiz)
{
  if(raiz == NULL) return;
  imprime_pos_ordem(raiz->esq);
  imprime_pos_ordem(raiz->dir);
  printf(" %d %s \n", raiz->chave, raiz->nome);
  return;
}

void print_arvore(pno raiz){
  if(raiz == NULL) return;
  printf(" (%d %s", raiz->chave, raiz->nome);
  print_arvore(raiz->esq);
  print_arvore(raiz->dir);
  printf(")");
  return;
}

/****************************************************************************/
int main(int argc, char *argv[])
{
  pno arvore = NULL;
  int chave;
  char nome[50], op;

  do{
    printf("\n\n***MENU DE OPCOES***");
    printf("\nESCOLHA O CARACTER CONFORME OPCAO DESEJADA");
    printf("\n[i] - Inserir registro");
    printf("\n[c] - Cosulta registro");
    printf("\n[p] - Imprimir em ordem");
    printf("\n[q] - Imprimir em pos ordem");
    printf("\n[s] - Imprimir em pre ordem");
    printf("\n[t] - Imprimir em formato arvore");
    printf("\n[x] - Encerrar");
    printf("\nOpcao: "); scanf(" %c",&op);
    printf("\n\n");

    switch (op){
        case 'i':
            printf("Informe CHAVE: "); scanf("%d",&chave);
            printf("Informe NOME: "); scanf(" %[^\n]",nome);
            arvore = insere(arvore, chave, nome);
            break;

        case 'c':
            printf("\nInforme CHAVE: "); scanf("%d",&chave);
            if(consulta(arvore, chave, nome) == 1)
              printf("\n %d %s",chave, nome);
            else
              printf("Nao encontrado!");
            break;

        case 'p':
            imprime_em_ordem(arvore);
            break;

        case 'q':
            imprime_pos_ordem(arvore);
            break;

        case 's':
            imprime_pre_ordem(arvore);
            break;

        case 't':
            print_arvore(arvore);
            break;

        case 'x':
            //liberar_arvore(arvore); implementar
            printf("Finalizando...");
            break;

        default:
            printf("Opcao invalida!");
            break;
    }

    printf("\n\n");
    // system("pause");
    // system("clear");

  } while(op != 'x');

  return 0;
}