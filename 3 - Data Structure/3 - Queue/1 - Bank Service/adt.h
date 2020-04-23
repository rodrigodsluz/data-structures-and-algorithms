//
// Created by denison on 04/11/18.
//

#ifndef ATIVIDADE_PRATICA_2_FILA_H
#define ATIVIDADE_PRATICA_2_FILA_H


typedef struct perfilCliente Cliente;

typedef struct descritor Fila;
typedef struct descritorSenha FilaSenha;
typedef struct descritorMesa FilaMesa;


Fila* criar_fila();
FilaSenha* criar_fila_senha();
FilaMesa* criar_fila_mesa();

void libera_fila(Fila *fi);
void libera_fila_senhas(FilaSenha *fi);
void libera_fila_mesa(FilaMesa *fi);

int insere_fila(Fila *fi, Cliente *clientes);
int insere_Fila_senha(FilaSenha *fi, int num);
int insere_fila_mesa(FilaMesa *fi, Cliente *clientes, int mesa);

int remove_fila_senha(FilaSenha *fi);
int remove_fila(Fila *fi);
int remove_fila_mesa(FilaMesa *fi);

int verificaTamanhoFila(Fila *fi);
int verificaTamanhoFilaMesa(FilaMesa *fi);

void printCliente(Cliente *clientes);

void imprimir_mesa(FilaMesa *fi, int num);

// função para criar senha
int criar_senha(Cliente **clientes, FilaSenha *fi);

#endif //ATIVIDADE_PRÁTICA_2_FILA_H