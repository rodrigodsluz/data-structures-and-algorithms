//
// Created by denison on 22/10/18.
//

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

#include "adt.h"

/****estrutura do elemento******/
struct elemento{
    int **mt;
    struct elemento *prox;
};
/*****************************/

/********typedef elemento***********/
typedef struct elemento Elemento;
/**********************************/

/******criando nó descritor**********/
struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int quant;
};
/**********************************/


/***********Criando a pilha************************/
Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->inicio = NULL;
        pi->fim = NULL;
        pi->quant = 0;
    }
    return pi;
}
/***********************************************/


/*********************Criando Elemento*********************/
Elemento* cria_elemento(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL){
        return 0;
    }
    return no;
}
/*********************************************************/

/***************************Multiplicar********************************/

/*função para multiplicar 2 matrizes e atribuir ser resultado, lembrando q como as matrizes são pomteiros
 *as mudança feitas dentro da função são válidas para o resto do programa
*/

//função recebe 3 matrizes como parametro
int  **multiplica(int **M, int **M2,int **m3){
  int i,j;
  int result, k=0, l=0, soma = 0, ii = 0, jj = 0, cont=0;

  for(i = 0; i < 3;i++){//para cada linha 
      //a mesma linha [i] da matriz 1 sera usada 3 vezes para multiplicar cada coluna da matriz 2
      while(cont < 3){
          for(j = 0; j < 3; j++){
              result = M[i][j] * M2[k][l];//multiplica linha atual pela coluna atual
              k++;//aumento k, que é minha linha, a coluna se mantem a mesma
              soma = soma + result;  
          }
          m3[ii][jj] = soma;  //matriz com a resposta recebe na posição[ii][jj] o resultado da devida posição da matriz
          k=0; //linha recebe 0, sempre na linha 0 da matriz 2
          l++;//incremento 1 a minha coluna da matriz 2
          jj++;//posição da minha coluna da matriz 3 que é o resultado é incrementada
          cont++;//contador incrementado
          soma=0;//a cada passo a soma é zerada
      }
      jj=0; //incremento a coluna que sempre irá começar da coluna 0
      ii++;//incremento minha linha para ter o resultado da proxima linha
      l=0;//zero minha coluna
      cont=0;//zero contador
  }

  return m3;
}
/*************************************************************/


/******************Empilhar a matriz*************************/
int empilhar(Pilha *pi, /*int M[3][3]*/ int **M){

    if(pi == NULL){
        return -1;
    }

    int **mat; //declaramos um ponteiro de ponteiro
    int l = 3, c = 3;

    //alocamos memoria para meu ponteiro de ponteiro, para que nao sobreescreva a matriz sempre que a recebermos
    mat = (int**) malloc(l * sizeof(int*));
    for (int i = 0;  i < l; i++){
        mat[i] = (int*) malloc (c * sizeof(int));
    }

    //passamos o valor da matriz M que estamos recendo a mat que estamos criando
    for(int i = 0; i < l; i++){
        for (int j = 0; j < c; ++j) {
            mat[i][j] = M[i][j];
        }
    }

    Elemento *no;
    no = cria_elemento();//criando elemento

    no->mt = mat;//no que guarda a matriz recebe matriz

    // se a pilha estiver vazia só inserimos
    if(pi->fim == NULL){
        no->prox = NULL;

        pi->inicio = no;
        pi->fim = no;

        pi->quant++;
        return 1;
    }else{//senao fazemos o apontamento onde o no->inicio apontara para o no e no para o antigo topo
        Elemento *atual;
        atual = pi->inicio;

        no->prox = atual;

        pi->inicio = no;
        pi->quant++;
        return 1;
    }
}
/*************************************************************/

/***************Desempilhando uma matriz*********************/
//função retorna a matriz
int **desempilharUm(Pilha *pi, int **m){
    if(pi->fim == NULL){
        pi->inicio = NULL;
        pi->quant = 0;
        return 0;
    }else{

      Elemento *atual = pi->inicio;

      //atribuimos a matriz que vem como parametro da função os valores da matriz que esta sendo desempilhada
      for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
              m[i][j] = atual->mt[i][j];

          }
      }
      
      pi->inicio = atual->prox; //pi inicio aponta para onde o atual esta apontando
      pi->quant--; //dinuimos a quantidade

      free(atual); //free na matriz do topo
      return m;
    }
}
/*************************************************************/


/****************Desempilhar*********************************/
/*
* desempilharesmo um par de matriz, esse par sera multiplicado gerando uma terceira matriz com o resultado
*/
int desempilhar(Pilha *pi){
  if(pi == NULL){
      return -1;
  }

  int **mat, **mat2, **mat3;//declaramos 3 matrizes
  int l = 3, c = 3; //liha e coluna

  //alocamos as 3 matrizes necessária para a multiplicação
  mat = (int**) malloc(l * sizeof(int*));
  mat2 = (int**) malloc(l * sizeof(int*));
  mat3 = (int**) malloc(l * sizeof(int*));
  for (int i = 0;  i < l; i++){
      mat[i] = (int*) malloc (c * sizeof(int));
      mat2[i] = (int*) malloc (c * sizeof(int));
      mat3[i] = (int*) malloc (c * sizeof(int));
  }

  //desempilha um par de matrizes, multiplica ela e empilha o resultado enquanto quantidade de matrizes > 1
  while(pi->quant > 1){
    //desempilhando a matriz 2 vezes, multiplicando e empilhando 
    empilhar(pi, multiplica(desempilharUm(pi, mat),desempilharUm(pi, mat2), mat3));
  }

  //dando free nos ponteiros alocados
  for (int i = 0;  i < l; i++){
      free(mat[i]);
      free(mat2[i]);
      free(mat3[i]);
  }
  free(mat);
  free(mat2);
  free(mat3);
}
/*************************************************************/

/******************CONSULTANDO A PILHA***********************/
void consulta(Pilha *pi){
    if(pi == NULL){
        printf("Pilha nao existe\n");
    }

    if(pi->quant == 0){
        printf("Pilha vazia\n");
    }else{

        Elemento *atual = pi->inicio;

        printf("\n\n");
        while (atual != NULL){
            for(int i= 0; i < 3; i++){
                for(int j=0; j < 3; j++){
                    printf("%d  ", atual->mt[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            atual = atual->prox;
        }
    }
}
/*************************************************************/