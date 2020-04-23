//
// Created by R
//

#ifndef TUBOS_FILA_H
#define TUBOS_FILA_H

/****typedef no descritor Pilha ****************/
typedef struct descritor Pilha;               //
/*********************************************/

/***********criando pilha**********************/
Pilha* criar_pilha();                        //
/********************************************/


/************liberando pilha*******************/
void libera_pilha(Pilha *pi);                //
/********************************************/

/*******empilhando e desimpilhando************/
int empilhar(Pilha *pi, char vogal);        //
char desempilhar(Pilha *pi);               //
/******************************************/

/*****************consultando Pilha*************************/
void consulta_pilha(Pilha *pi, Pilha *pi2, Pilha *pi3);   //
/*********************************************************/

/*****************informações da pilha*********************/
int tamanhoPilha(Pilha *pi);                             //
/********************************************************/

/*************************************************************************/
//pega o valor do primeiro elemento da pilha para comparar com o outro  //
char pegaVogal(Pilha *pi);                                             //
/**********************************************************************/

//Verifica se o tubo 3 esta certo
/********************************************************/
int verificaCerto(Pilha *pi);                          //
/******************************************************/
#endif //TUBOS_FILA_H