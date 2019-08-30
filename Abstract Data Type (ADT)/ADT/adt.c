
#include "stdio.h"
#include "stdlib.h"
#include "adt.h"


// --------------------------
// definição de structs 
// --------------------------
struct ponto{
  float x;
  float y;
};

// --------------------------
// implementação das funções 
// --------------------------

// função para criar um novo ponto
Ponto* pontoCriar(float x, float y)
{
  Ponto* p = (Ponto*) malloc(sizeof(Ponto));

  if(p != NULL){
    p->x = x;
    p->y = y;
  }
  
  return p;
}

// função para acessar os valores das coordenadas x e y do ponto
int pontoAtribuir(Ponto* p, float x, float y)
{
  // se a memória do ponteiro p não foi alocada retorna como erro
  if(p == NULL)
    return 0;
  
  p->x = x;
  p->y = y;

  return 1;
}

// função para atribuir valores para as coordenadas x e y do ponto
int pontoAcessar(Ponto* p, float *x, float *y)
{
  // se a memória do ponteiro p não foi alocada retorna como erro
  if(p == NULL)
    return 0;
  
  // parâmetros x e y foram passados por referência pois se alteram aqui 
  *x = p->x;
  *y = p->y;

  return 1;
}

// função para imprimir um ponto
void pontoImprimir(Ponto* p)
{
  printf("(%.2f, %.2f)", p->x, p->y);
}

// função para liberar a memória de um ponto
void pontoLiberar(Ponto* p)
{
  free(p);
}