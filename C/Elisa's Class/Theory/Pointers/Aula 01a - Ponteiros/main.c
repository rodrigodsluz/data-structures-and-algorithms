#include "stdio.h"

int subtracao(int n1, int n2){
  return n1 - n2;
}

void soma(int *ps, int n1, int n2){
  *ps = n1 + n2;
}

int main(void) {
  
  // declaração das variáveis (sub) e (s)
  int sub; // variável do tipo inteiro que armazena total da subtração
  int s; // variável do tipo inteiro que armazena total da soma
  
  
  /***********************************************************************************************/
  /** passagem de parâmetro por valor (função subtracao() retorna o resultado da subtração)     **/
  /***********************************************************************************************/
  
  sub = subtracao(10, 6); // chama função que calcula a subtração 10 - 6 = 4
  printf("Subtração = %d\n", sub);
  
  
  /***********************************************************************************************/
  /** passagem de parâmetro por referência (função soma() recebe o endereço da variável s)      **/
  /***********************************************************************************************/
  
  // usando o endereço da variável (&s)
  soma(&s, 3, 5);
  printf("Soma com s = %d\n", s);
  
  /***********************************************************************************************/
  /** passagem de parâmetro por referência (função soma() recebe um ponteiro para a variável s) **/
  /***********************************************************************************************/
  
  // declaração dos ponteiros (ps) e (ps2)
  int *ps = &s; // ponteiro para a posição de memória que armazena o total da soma
  int **ps2 = &ps; // ponteiro para o ponteiro anterior
  
  // usando o ponteiro (ps) que contém o endereço da variável (s)
  soma(ps, 3, 5);
  printf("Soma com ps = %d\n", *ps);
  
  // usando o valor do ponteiro para ponteiro (ps2) que contém o endereço do ponteiro (ps) 
  soma(*ps2, 3, 5);
  printf("Soma com *ps2 = %d\n", **ps2);
  
  return 0;
}
