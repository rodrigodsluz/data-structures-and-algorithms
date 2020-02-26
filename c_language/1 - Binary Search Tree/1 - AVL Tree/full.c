#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no * pno;

typedef struct no{
  int chave;
  char nome[20];
  pno esq;
  pno dir;
  int alt;
}no;

/****************************************************************************/
pno criar_no(int c, char nome[])
{
  pno aux = (pno) malloc(sizeof(no));
  aux->chave = c;
  strcpy(aux->nome,nome);
  aux->esq = NULL;
  aux->dir = NULL;
  aux->alt = 0;
  return aux;
}

/****************************************************************************/
int altura(pno n)
{
  if(n == NULL) return -1;
  else return n->alt;
}

/****************************************************************************/
int max(int a, int b)
{
  if(a>b)return a;
  return b;
}

/****************************************************************************/
pno rotaciona_direita(pno n)
{
  pno aux;
  aux = n->esq;
  n->esq = aux->dir;
  aux->dir = n;

  n->alt   = max(altura(n->esq), altura(n->dir)) + 1;
  aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

  return(aux);
}

/****************************************************************************/
pno rotaciona_esquerda(pno n)
{
  pno aux;
  aux = n->dir;
  n->dir = aux->esq;
  aux->esq = n;

  n->alt   = max(altura(n->esq), altura(n->dir)) + 1;
  aux->alt = max(altura(aux->esq), altura(aux->dir)) + 1;

  return(aux);
}

/****************************************************************************/
pno rotaciona_esquerda_direita(pno n)
{
  n->esq = rotaciona_esquerda(n->esq);
  pno aux = rotaciona_direita(n);
  return aux;
}

/****************************************************************************/
pno rotaciona_direita_esquerda(pno n)
{
  n->dir = rotaciona_direita(n->dir);
  pno aux = rotaciona_esquerda(n);
  return aux;
}

/****************************************************************************/
void print_arvore(pno arv)
{
  if(arv == NULL) return;
  print_arvore(arv->esq);
  printf(" %d %s \n", arv->chave, arv->nome);
  print_arvore(arv->dir);
  return;
}

/****************************************************************************/
int consulta(pno arv, int chave, char nome[20])
{
  int achou = -1;
  if (arv->chave == chave){
    strcpy(nome, arv->nome);
    return 1;
  }
  if(arv->chave > chave){
    if(arv->esq == NULL)
      return -1;
    achou = consulta(arv->esq, chave, nome);
  }
  if(arv->chave < chave){
    if(arv->dir == NULL)
      return -1;
    achou = consulta(arv->dir, chave, nome);
  }

  return achou;
}

/****************************************************************************/
int fator_balanceamento(pno n)
{
  if(n == NULL) return 0;
  return(altura(n->dir) - altura(n->esq));
}

/****************************************************************************/
pno busca_menor(pno atual)
{
    pno no1 = atual;
    pno no2 = atual->esq;
    while (no2 != NULL){
        no1 =  no2;
        no2 = no2->esq;
    }
    return no1;
}

/****************************************************************************/
int remover(pno *arvore, int chave)
{
    if (arvore == NULL){
        printf("NÃO EXISTE!"); return 0;
    }

    int aux;
    if (chave < (*arvore)->chave){
        if ((aux =remover(&(*arvore)->esq, chave))==1)
            if (fator_balanceamento(*arvore) >= 2){
                if (altura((*arvore)->dir->esq) <= altura((*arvore)->dir->dir))
                    rotaciona_direita(*arvore);
                else
                    rotaciona_direita_esquerda(*arvore);
            }
    }

    if (chave > (*arvore)->chave){
        if ((aux=remover(&(*arvore)->dir, chave))==1)
            if (fator_balanceamento(*arvore) >= 2){
                if (altura((*arvore)->esq->dir) <= altura((*arvore)->esq->esq))
                    rotaciona_esquerda(*arvore);
                else
                    rotaciona_esquerda_direita(*arvore);
            }
    }

    if ((*arvore)->chave == chave){
        //Nó com folhas ou sem folhas
        if (((*arvore)->esq==NULL || (*arvore)->dir == NULL)){
            pno aux = (*arvore);
            if ((*arvore)->esq != NULL)
                (*arvore) = (*arvore)->esq;
            else
                (*arvore) = (*arvore)->dir;
            free(aux);
        }
        else{
            pno temp = busca_menor((*arvore)->dir);
            (*arvore)->chave = temp->chave;
            remover(&(*arvore)->dir, (*arvore)->chave);
            if (fator_balanceamento((*arvore)) >= 2){
                if (altura((*arvore)->esq->dir) <= altura((*arvore)->esq->esq))
                    rotaciona_esquerda((*arvore));
                else
                    rotaciona_esquerda_direita((*arvore));
            }
        }
        return 1;
    }
    return aux;
}

/****************************************************************************/
pno insere(pno arvore, int c, char nome[])
{
  if(arvore == NULL) return(criar_no(c, nome));
  if(arvore->chave == c){
    printf("Chave existente\n");
    return arvore;
  }
  if(arvore->chave > c){
    //insere na esquerda
    arvore->esq = insere(arvore->esq, c, nome);
    //como eu inseri na esquerda o unico problema que eu posso ter ? se a esquerda agora tem 2 vezes mais altura
    if(fator_balanceamento(arvore) == -2){
      if(c < arvore->esq->chave) arvore = rotaciona_direita(arvore);
      else arvore = rotaciona_esquerda_direita(arvore);
    }
  }
  if(arvore->chave < c){
    //insere na direita
    arvore->dir = insere(arvore->dir, c, nome);
    //como eu inseri na esquerda o unico problema que eu posso ter ? se a esquerda agora tem 2 vezes mais altura
    if(fator_balanceamento(arvore) == 2){
      if(c > arvore->dir->chave) arvore = rotaciona_esquerda(arvore);
      else arvore = rotaciona_direita_esquerda(arvore);
    }
  }
  arvore->alt   = max(altura(arvore->esq), altura(arvore->dir)) + 1;
  return(arvore);
}

/****************************************************************************/
int main(int argc, char *argv[])
{
  pno arvore = NULL;

  int chave;
  char nome[20], op;

  do{
    printf("\n\n***MENU DE OPCOES***");
    printf("\nESCOLHA O CARACTER CONFORME OPCAO DESEJADA");
    printf("\n[i] - Inserir registro");
    printf("\n[c] - Consultar");
    printf("\n[p] - Imprimir");
    printf("\n[r] - Remover");
    printf("\n[v] - Verificar se arvore esta balanceada");
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
            if(consulta(arvore, chave, nome) == 1){
              printf("\n %d %s",chave, nome);
            }
            break;

        case 'p':
            print_arvore(arvore);
            break;

        case 'r':
            printf("\nInforme CHAVE: "); scanf("%d",&chave);
            remover(&arvore, chave);
            break;

        case 'v':
            if(fator_balanceamento(arvore) >= -1 && fator_balanceamento(arvore) <= 1)
                printf(" SIM ");
            else
                printf(" NAO ");
            break;

        case 'x':
            //liberar_arvore(arvore); implementar
            printf("Finalizando...");
            break;

        default:
            printf("Opção invalida!");
            break;
    }

    printf("\n\n");
    // system("pause");
    // system("clear");

  } while(op != 'x');

  return 0;
}