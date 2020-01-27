#include "stdio.h"
#include "stdlib.h"
#include "adt.h"

int main(void) {

  Ponto *p, *q; // necessário declarar ponteiros para acessar a TAD

  // cria dois pontos: p e q
  p = pontoCriar(10, 21);
  q = pontoCriar(7, 25);

  // imprimir pontos
  printf("\nPonto p = ");
  pontoImprimir(p);

  printf("\nPonto q = ");
  pontoImprimir(q);

  // libera memória alocada para os pontos p e q
  pontoLiberar(q);
  pontoLiberar(p);
  
  printf("\n");
  return 0;
}