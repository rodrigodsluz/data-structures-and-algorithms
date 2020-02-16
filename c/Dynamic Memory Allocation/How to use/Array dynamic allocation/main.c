#include <stdio.h>
#include <stdlib.h>

/***********************************************************************/
/** Protótipos de funções                                              */
/***********************************************************************/
int *alocarVetorInt(int n);
void preencherVetor(int n, int *v);
void imprimirVetor(int n, int *v);


/***********************************************************************/
/** Função principal                                                   */
/***********************************************************************/
int main(void) 
{
  int n;
  int *vetor;
  
  printf("\nDigite número de alunos a ser cadastrado:");
  scanf("%d", &n);
  
  // aloca memória para o vetor com tamanho n
  vetor = alocarVetorInt(n);
  
  printf("\nCadastre o número de matrícula de %d alunos: \n", n);
  
  // chamada de função para preencher vetor
  preencherVetor(n, vetor);
  
  printf("\nAlunos matriculados: \n");
  
  // chamada de função para imprimir vetor
  imprimirVetor(n, vetor);
  
  // desaloca memória 
  free(vetor);
  
  return 0;
}


/********************************************************************/
/** Função para alocar memória para vetor com n elementos           */
/********************************************************************/
int *alocarVetorInt(int n)
{
  // declara um ponteiro de ponteiro
  int *v;
  
  // aloca memória para um vetor de ponteiro com n posições do tipo (int)
  v = (int*) malloc(n * sizeof(int));
  
  if(v == NULL){ 
    printf("Memória insuficiente!");
  }
  
  return v;
}

/********************************************************************/
/** Função para preencher vetor com valores digitados pelo usuário */
/********************************************************************/
void preencherVetor(int n, int *v)
{
  for(int i=0; i<n; i++){
      
      // atribui a posição i da matriz o valor digitado pelo usuário
      scanf("%d", &v[i]); 
      
    }
}

/******************************************************************/
/** Função para imprimir vetor                                   */
/******************************************************************/
void imprimirVetor(int n, int *v)
{
  for(int i=0; i<n; i++){
      
      // imprime na tela o valor da posição n do vetor
      printf("%d ", v[i]); 
      
    }
}
