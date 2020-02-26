/*
Alocação Dinâmica


Funções: 


malloc(), de Memory Allocation, é uma função da biblioteca stdlib.h que  recebe como argumento números inteiros positivos (size_t), que irão  representar o número de bytes que iremos alocar.
 Essa função retorna um ponteiro contendo o endereço do bloco alocado.


void *malloc(size_t numero_de_bytes);


A função malloc() serve para declarar qualquer tipo de dado, por isso em sua sintaxe é mostrado um void. Ela retorna o endereço do bloco de memória que foi alocado. Logo, devemos fazer um cast, ou seja, fazer com que um  ponteiro (do tipo alocado) receba esse endereço. Por exemplo, e quisermos alocar um bloco de 10 endereços para inteiros, convertemos void* para int*, adicionando (int*) na frente do malloc: 
int *p; 
p = (int *) malloc( 10 * sizeof( int ) );


Obs: O cast converte um tipo de dado em outro para ser atribuído a uma variável. Por exemplo, o trecho abaixo converte uma variável double para inteiro:


double y = 4.0;
int x;
x = (int) y;


Referência:
https://www.cprogressivo.net/2013/04/Como-usar-a-funcao-malloc-para-alocar-memoria-em-linguagem-C.html
*/

#include <stdio.h>
#include <stdlib.h>

/***********************************************************************/
/** Protótipos de funções                                              */
/***********************************************************************/
int **alocarMatrizInt(int l, int c);
void preencherMatriz(int l, int c, int **m);
void imprimirMatriz(int l, int c, int **m);


/***********************************************************************/
/** Função principal                                                   */
/***********************************************************************/
int main(void) 
{
  int l, c;
  int **pMatriz;
  
  printf("\n\nDigite número de linhas e colunas:");
  scanf("%d %d", &l, &c);
  
  // aloca memória para a matriz 
  pMatriz = alocarMatrizInt(l, c);
  
  printf("Preencha a matriz [%d x %d]: \n", l, c);
  
  // chamada de função para preencher matriz
  preencherMatriz(l, c, pMatriz);
  
  printf("Matriz [%d x %d] = \n", l, c);
  
  // chamada de função para imprimir matriz
  imprimirMatriz(l, c, pMatriz);
  
  // desaloca memória
  free(*pMatriz);
  
  return 0;
}


/********************************************************************/
/** Função para alocar memória para matriz com l linhas e c colunas */
/********************************************************************/
int **alocarMatrizInt(int l, int c)
{
  // declara um ponteiro de ponteiro
  int **m;
  
  // aloca memória para um vetor de ponteiro com l posições do tipo (int*)
  m = (int**) malloc(l * sizeof(int*));
  
  if(m == NULL){ 
    printf("Memória insuficiente!");
    return NULL;
  }
  
  // para cada linha da matriz m[i] aloca um vetor de inteiros com c posições
  for(int i=0;i<l;i++){
    
    // aloca memória para um vetor de inteiros com c posições do tipo (int)
    m[i] = (int*) malloc(c * sizeof(int));
    
    if(m[i] == NULL){ 
      printf("Memória insuficiente!");
    }
  }
  
  return m;
}

/********************************************************************/
/** Função para preencher matriz com valores digitados pelo usuário */
/********************************************************************/
void preencherMatriz(int l, int c, int **m)
{
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      
      // atribui a posição i,j da matriz o valor digitado pelo usuário
      scanf("%d", &m[i][j]); 
      
    }
    printf("\n");
  }
}

/******************************************************************/
/** Função para imprimir matriz                                   */
/******************************************************************/
void imprimirMatriz(int l, int c, int **m)
{
  for(int i=0; i<l; i++){
    for(int j=0; j<c; j++){
      
      // imprime na tela o valor da posição i,j da matriz
      printf("%d ", m[i][j]); 
      
    }
    printf("\n");
  }
}
