  //
// Created by R
//

#include <stdio.h>
#include <stdlib.h>

#include "adt.h"


//criando elemento
struct elemento{
    char vogal;
    struct elemento *prox;
};


//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int quant;
};

/*Criando e libreando a pilha*/
Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->inicio = NULL;
        pi->fim = NULL;
        pi->quant = 0;
    }
    return pi;
}

void libera_pilha(Pilha *pi){
  if(pi != NULL){
    Elemento *atual;


    if(pi->inicio == NULL){
        pi->fim = NULL;
    }else{
      while (pi->fim != NULL){
        atual = pi->inicio;
        pi->inicio = atual->prox;
        free(atual);

        if(pi->inicio == NULL){
          pi->fim = NULL;
        }
      }
    }
    free(pi);
  }
}
/*******************************/

/*Criando Elemento*/
Elemento* cria_elemento(){
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    return no;
}
/*********************************/

/*Empilhando*/
int empilhar(Pilha *pi, char vogal){

    if(pi == NULL){
        return -1;
    }

    Elemento *no;
    no = cria_elemento();//criando o no

    //se pi->fim apontar para null segnifica q a pilha esta vazia entao só insere
    if(pi->fim == NULL){
        no->vogal = vogal; //elemento q sera inserido recebe a vogal
        no->prox = NULL;//elemento proz aponta para null pq ele sera o ultimo elemento

        //no descrito pi->inicio aponta para no
        pi->inicio = no;

        //pi->fim tmbb aponta pro no, pois ele é  unico elemento da pilha até o momento
        pi->fim = no;

        //aumento a quantidade de elementos
        pi->quant++;
    }else{
        Elemento *atual;

        //atual será o primeiro elemento atual da pilha (topo)
        atual = pi->inicio;

        //no q sera adicionado recebe seus valores
        no->vogal = vogal;
        no->prox = atual; //no->prox aponta para atual, que é meu elemento atual do topo da pilha

        //pi->inicio aponta para o no, novo topo da pilha
        pi->inicio = no;

        //aumento a quantidade de elementos existentes na pilha
        pi->quant++;
    }
    return 1;
}
/*************************************/

/*Desimpilhando Pote 1*/
/*No caso de desse programa, o desempilhar vai sempre retornar a vogal desempilhada*/
char desempilhar(Pilha *pi){

    char v = ' '; //declaro vogal recebendo espaço em branco

    if(pi == NULL){
        return -1;
    }

    if(pi->fim == NULL){ //se a pilha estiver vazia pi->inicio aponta para null, zero a quantidade e retorno V
        pi->inicio = NULL;
        pi->quant = 0;

        return v;
    }else{

        //atual é elemento que sera desempilhado
        Elemento *atual = pi->inicio;

        //variavel vogal recebe a vogal a ser retirada
        v = atual->vogal;

        //pi->inicio aponta para quem atual aponta, novo topo da pilha
        pi->inicio = atual->prox;
        pi->quant--;// diminuo um valor do total da pilha

        //libero o topo atual
        free(atual);

        //retorno a variavel q foi desempilhada
        return v;
    }
}
/*************************************/

/*Consultando sempre as 3 pilhas para printa-las na tel*/
void consulta_pilha(Pilha *pi, Pilha *pi2, Pilha *pi3){
    //criando meus elementos
    Elemento *atual = pi->inicio;
    Elemento *atual2 = pi2->inicio;
    Elemento *atual3 = pi3->inicio;

    printf("|P1| |P2| |P3|\n\n");

    //para i < que 5 printarei na tela a pilha
    for(int i = 0; i < 5; i++){

        /*1 if pra cada tubo*/

        //se i < que a quqantidade printo a vogal
        if(i < pi->quant){
            printf("|%c |", atual->vogal);//printamos vogal tubo 1
            atual = atual->prox;//ando para meu proximo elemento do tubo 1
        }else{//quando nao tiver mais elemento na pilha, printo um espaço em branco
            printf("|  |");
        }

        //restante dos if tem a mesma função, porém será executado no tubo 2 e 3
        if(i < pi2->quant){
            printf(" |%c |", atual2->vogal);
            atual2 = atual2->prox;
        }else{
            printf(" |  |");
        }
        if(i < pi3->quant){
            printf(" |%c |", atual3->vogal);
            atual3 = atual3->prox;
        }else{
            printf(" |  |");
        }
        printf("\n");
    }
}
/*************************************/

/*Tamanho da Pilha*/
int tamanhoPilha(Pilha *pi){
    if(pi == NULL){
        return -1;
    }
    return pi->quant;
}
/*************************************/


/*Retorna pra gente o topo de um tubo quando necessário*/
char pegaVogal(Pilha *pi){
    /*pi->quant == 0 significa q a pilha esta vazia, logo retornamos z para indicar que esta vazia
        Por que z ? por que a função retorna um char sendo ele consoante.
    */
    if(pi->quant == 0){
        return 'z';
    }else{
        return pi->inicio->vogal;
    }
}
/*************************************/


/*Verificando se tubo 3 esta na ordem certa*/
int verificaCerto(Pilha *pi){

    int vet[5] = {'a','e','i','o','u'};
    int cont = 0;

    Elemento *atual = pi->inicio;

    //só entrara na condição quando o tubo 3 tiver 5 elementos
    if(pi->quant == 5){

        /*criamos um loop para percorrer e apilha e comparar com o vetor pra vermos se esta igual*/
        for(int i = 0; i < pi->quant; i++){
            if(atual->vogal == vet[i]){
                cont++;
            }
            atual = atual->prox;
        }

        //se as 5 posições estiverem na mesma ordem retorno 1
        if(cont == 5){
            return 1;
        }else{
            //senao retornamos 0
            return 0;
        }
    }else{
        return 0;
    }
}
/*************************************/