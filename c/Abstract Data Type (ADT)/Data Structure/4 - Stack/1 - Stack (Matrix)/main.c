//
// Created by denison on 22/10/18.
//

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

#include "adt.h"

//função que entra com entrarNumero
int entrarNumero();

//função que chama o menu
int menu();

//função que aloca uma matriz
int **alocarMatriz();



int main(void) {
   
  
  int **M;// declaranto ponteiro de ponteiro
  Pilha *mat; //declarando um ponteiro do tipo pilha
  int i,j, ok, num, op; 
  
  M = alocarMatriz(); //alocando matriz
  mat = criar_pilha(); //criando uma pilha

  do{
      op = menu(); //chamo menu
      
      if(op == 1){//se escolher empilhar
          //laço para preencher uma matriz 3X3
          for(i = 0; i < 3; i++){
              for(j = 0; j < 3; j++){
                  printf("M[%d][%d] = ", i,j);
                  scanf("%d", &M[i][j]);
              }
              system("clear"); //limpa tela linux (se usa windows substitua por system("cls") )
          }
          empilhar(mat, M);//empilha a matriz preenchida
      }

      //se escolher desempilhar
      if(op ==2 ){
          desempilhar(mat);  //desempilhamos a pilha
      }

      if(op != 3){
        //printa a pilha atual na teal
        consulta(mat);
      }
  }while(op != 3);
  
  //liberando memoria para a matriz M que foi alocada

  for (int i = 0;  i < 3; i++){
      free(M[i]);
  }
  free(M);

  //free(*M);


  printf("\n\nFim do Programa\n\n");
  
return 0;
}

//função para entrar com um numero
int entrarNumero(){
    int num;
    
    printf("Entre com um numero\n");
    scanf("%d", &num);
    
    return num;
}

//função para o menu
int menu(){
    int op;
    do{
        printf("Escolha uma Opcao\n\n");
        printf("1 - Empilhar\n");
        printf("2 - Dempilhar\n");
        printf("3 - Sair\n");
        scanf("%d", &op);
        
        system("clear");
    }while(op != 1 && op != 2 && op != 3);
   return op;
}

//função que aloca a matriz
int **alocarMatriz(){
    int **M;

    M = (int**) malloc(3 * sizeof(int*));
    for (int i = 0;  i < 3; i++){
        M[i] = (int*) malloc (3 * sizeof(int));
    }

    return M;
}