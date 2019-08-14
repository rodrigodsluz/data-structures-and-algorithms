/*
Observação: 


A atribuição do trecho de código abaixo NÃO É VÁLIDA. 


  int M[10][5]; 
  int **pM; 
  pM = M;  


Esta atribuição não é correta para uma matriz (que possui mais de uma dimensão) pois a linguagem C permite que um ponteiro seja utilizado apenas com uma dimensão (ou seja, apenas um par de colchetes). 


Logo, para MATRIZ a seguinte atribução É VÁLIDA: 


  int M[10][5]; 
  int *pM; 
  pM = &M[0][0];  
 

Para VETOR a seguinte atribução É VÁLIDA: 


  int X[2];  
  int *p; 
  p = X;


=> Verifique a implementação ao lado!!! =)


Obs: (int **p) pode ser utilizado para armazenar matriz usando a alocação dinâmica. Veja próximo tópico!
*/

#include <stdio.h>
#include <stdlib.h>

/***************************************************************/
/** Função principal                                           */
/***************************************************************/
int main(void) 
{
  
  // ********* TRABALHANDO COM VETORES E PONTEIROS***************
  
  // declarando um VETOR de 10 elementos
  int X[10];
  
  // declarando um ponteiro
  int *p;
  
  // atribuindo vetor X para o ponteiro p 
  // ou seja, p recebe o endereço da primeira posição do vetor
  p = X;  // equivalente a (p = &X[0])
  
  printf("\nPreenchendo vetor X: \n");
  
  // preenchendo o vetor X
  for(int i=0; i<10; i++){
      X[i] = i*i;
      printf("X[%d] = %d \n", i, X[i]);
  }
  
  printf("\nImprimindo vetor X: \n");
  
  // imprimindo o vetor X 
  for(int i=0; i<10; i++){
      printf("%d ", X[i]);
  } 
  
  printf("\n\nImprimindo vetor X usando o ponteiro p: \n");
  
  // imprimindo o vetor X usando o ponteiro p
  for(int i=0; i<10; i++){
      printf("%d ", p[i]);
  } 
  
  // ********* TRABALHANDO COM MATRIZES E PONTEIROS ****************
  
  // declarando uma MATRIZ de 10 linhas e 5 colunas
  int M[10][5];
  
  // declarando um ponteiro
  int *pM;
  
  // atribuindo matriz M para o ponteiro p 
  // ou seja, p recebe o endereço da primeira posição da matriz
  pM = &M[0][0];  
  
  printf("\n\n\nPreenchendo matriz M: \n");
  
  // preenchendo o matriz M 
  for(int i=0; i<10; i++){
    for(int j=0; j<5; j++){
      M[i][j] = i*j;
      printf("X[%d][%d] = %d \n", i, j, M[i][j]);
    }
    printf("\n");
  }
  
  printf("\nImprimindo matriz M: \n");
  
  // imprimindo o matriz X 
  for(int i=0; i<10; i++){
    for(int j=0; j<5; j++){
      printf("%d ", M[i][j]);
    }
    printf("\n");  
  } 
  
  printf("\n\nImprimindo matriz M usando o ponteiro pM: \n");
  
  // imprimindo o matriz M usando o ponteiro pM
  for(int i=0; i<10; i++){
    for(int j=0; j<5; j++){
      printf("%d ", pM[i*5+j]);  // pM[i*5+j] é equivalente a M[i][j]
    }
    printf("\n");  
  } 
  
}
