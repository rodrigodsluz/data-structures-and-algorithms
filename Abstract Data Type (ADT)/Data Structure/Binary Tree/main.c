  
// bibliotecas do sistema
#include <stdio.h>

// bibliotecas do projeto
#include "adt.h"

// funcao principal
int main(void) {

  ArvoreBin *raiz;
  int opcao, valor, ok, pos;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n1 - Criar árvore binária");
    printf("\n2 - Liberar árvore binária");
    printf("\n3 - Inserir nó na árvore binária");
    printf("\n4 - Remover nó da árvore binária");
    printf("\n5 - Consultar nó na árvore binária");
    printf("\n6 - Percurso pré-ordem");
    printf("\n7 - Percurso em-ordem");
    printf("\n8 - Percurso pós-ordem");
    printf("\n9 - Altura da árvore binária");
    printf("\n10 - Total de nós");
    printf("\n11 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1: 

        // criar arvore binaria
        raiz = criar_arvore_binaria();

        if(raiz != NULL){
          printf("\n Árvore criada com sucesso!");
        }else{
          printf("\n Árvore não criada!");
        }
        break;


      case 2: 
        
        // liberar arvore binaria
        ok = liberar_arvore_binaria(raiz);

        if(ok){
          printf("\n Árvore liberada com sucesso!");
        }else{
          printf("\n Árvore não liberada!");
        }
        break;

      case 3:

        // inserir nó na árvore binária  
        printf("\n Valor a ser inserido: ");
        scanf("%d", &valor);      

        ok = inserir_arvore_binaria(raiz, valor);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // remover nó com determinado valor
        printf("\n Valor a ser removido: ");
        scanf("%d", &valor); 

        ok = remover_arvore_binaria(raiz, valor);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }

        break;

      case 5:

        // busca elemento pelo valor
        printf("\n Valor a ser buscado: ");
        scanf("%d", &valor); 

        ok = consultar_arvore_binaria(raiz, valor);

        if(ok == 1){
          printf("\n Busca realizada com sucesso!");
        }else{
          printf("\n Valor não encontrado na árvore!");
        }


        break;

      case 6:    
        // imprime percurso pré-ordem
        percorrer_pre_ordem_arvore_binaria(raiz);
        break;

      case 7:   
        // imprime percurso em-ordem 
        percorrer_em_ordem_arvore_binaria(raiz);
        break;

      case 8:    
        // imprime percurso pós-ordem
        percorrer_pos_ordem_arvore_binaria(raiz);    
        break;


      case 9:
        // imprime a altura da árvore binária
        printf("%d\n", altura_arvore_binaria(raiz));
        break;
      
        break;

      case 10:
        // imprime o número total de nós na árvore binária
        printf("%d\n", quantidade_nos_arvore_binaria(raiz));
        break;
              
      case 11:

        // libera memória e finaliza programa
        liberar_arvore_binaria(raiz);
        printf("\nFinalizando...");
        break;

      default: 
        printf("\nOpção inválida!");
        break;
    }

  }while(opcao != 11);

  return 0;
}