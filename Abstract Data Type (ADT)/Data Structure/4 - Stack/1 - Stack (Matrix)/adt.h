//
// Created by denison on 22/10/18.
//

#ifndef EMP_MAT_H
#define EMP_MAT_H


/***********typedef nó descritor***********/
 typedef struct descritor Pilha;         //
/****************************************/

/**************Criar Pilha****************/
 Pilha* criar_pilha();                   //
/***************************************/

/********Empilhar e Desempilhar***********/
 int empilhar(Pilha *pi, int **M);       //
 int desempilhar(Pilha *pi);            //
/**************************************/

/********consulta*********************/
 void consulta(Pilha *pi);           //
/************************************/


#endif //TUBOS_FILA_H
