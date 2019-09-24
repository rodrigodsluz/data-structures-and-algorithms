#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// definição do struct elemento
typedef struct elemento{
  int dado;
  struct elemento *prox;
}Elemento;


// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a lista foi criada corretamente, indica que ela está vazia
  if(li != NULL){
    *li = NULL;
  } 

  return li;
}


// função para liberar memória
int liberar_lista(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // libera todos os nós da lista que foram alocados
  Elemento *no;
  while( (*li) != NULL ){
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(li);

  return 1;  
}

// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // a lista não foi criada corretamente
  if(li == NULL){
    return 0;
  }

  int cont = 0;
  Elemento *no = *li;

  // acrescenta cont até acabar a lista
  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}

// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, li não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


// função para verificar se a lista está cheia (não se aplica)
int lista_cheia(Lista *li)
{
  return 0;
}


// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  return no;
}


// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = (*li);

  // insere elemento no início da lista
  *li = no;

  return 1;
}


// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    *li = no;

  }else{

    // senão percorre a lista até o fim e insere no final
    Elemento *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}


// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->dado = dado;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    no->prox = NULL;
    *li = no;

  }else{

    // senão percorre a lista até achar o local correto e insere
    Elemento *anterior, *atual;
    atual = *li;

    while(atual != NULL && atual->dado < dado){
      anterior = atual;
      atual = atual->prox;
    }
    
    // insere na primeira posição
    if( atual == (*li) ){
      no->prox = (*li);
      *li = no;

    }else{
      no->prox = atual;
      anterior->prox = no;
    }
  }

  return 1;
}


// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // muda inicio para o proximo elemento
  Elemento *no;
  no = *li;
  *li = no->prox;

  // libera Elemento no
  free(no);

  return 1;
}


// função para remover elemento do final da lista
int remover_lista_final(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre lista até o final
  Elemento *anterior, *no;
  no = *li;
  
  while(no->prox != NULL){
    anterior = no;
    no = no->prox;
  }

  // remove o primeiro elemento, se este for o único da lista
  if(no == (*li)){ 
    *li = no->prox;  

  }else{
    anterior->prox = no->prox;
  }

  //libera Elemento no
  free(no);

  return 1;

}


// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int dado)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre a lista até achar o elemento e remove
  Elemento *anterior, *no;
  no = *li;

  while(no != NULL && no->dado != dado){
    anterior = no;
    no = no->prox;
  }

  // elemento não foi encontrado
  if(no == NULL){
    return 0;
  }

  // remove o primeiro elemento
  if(no == (*li)){
    *li = no->prox;

  }else{
    anterior->prox = no->prox;
  }

  free(no);
  return 1;

}

int buscar_lista_posicao(Lista *li, int pos, int *dado)
{
  // verifica se a lista foi criada corretamente, se não está vazia e se a posição é válida (note que é a posição na lista e não o índice do vetor)
  if(li == NULL || (*li) == NULL || pos <= 0){
    return 0;
  }

  Elemento *no = *li;
  int i = 1;

  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }

  // posição não existe na lista
  if(no == NULL){
    return 0;
  }

  // copia o dado da posição desejada (parâmetro passado por referência)
  *dado = no->dado;

  return 1;
}


int buscar_lista_dado(Lista *li, int dado, int *pos)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL || (*li) == NULL){
    return 0;
  }

  // procura a posição no vetor onde o dado desejado se encontra
  Elemento *no = *li;
  int i = 1;

  while(no != NULL && no->dado != dado){
    no = no->prox;
    i++;
  }
  
  // verifica se elemento não foi encontrado 
  if(no == NULL){ 
    return 0;
  }

  // copia a posição da lista onde o dado foi encontrado (parâmetro passado por referência)
  *pos = i; 

  return 1;
}



//**************************************************************************
// função para imprimir a lista dinâmica
int imprimir_lista(Lista *li)
{
    if(li == NULL || (*li) == NULL){
      return 0;
    }

    Elemento *aux = (*li);

    while(aux->prox != NULL){
      printf(" %d ", aux->dado);
      aux = aux->prox;
    }

    printf(" %d ", aux->dado);

    return 1;
}
