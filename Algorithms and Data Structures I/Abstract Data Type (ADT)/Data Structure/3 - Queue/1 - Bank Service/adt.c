#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt.h"



//elementos da fila da senha
struct elementoSenha{
    int senha;
    struct elementoSenha *prox;
};

//elementos mesa
struct mesa{
    int id_mesa;
    Cliente *clientes;
    struct mesa *prox;
};

//struct clientes
struct perfilCliente{
    int senha;
    char perfil;
    char tipo_atend;
    char senhaFinal[4];
};


// definição do struct elemento
struct elemento{
    Cliente *clientes;
    struct elemento *prox;
};

/************************************/
// definição de tipos abstratos
typedef struct elemento Elemento;
typedef struct elementoSenha Senha;
typedef struct mesa Mesa;
/************************************/


/************************************/
//nós
struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int qnt;
};

struct descritorSenha{
    struct elementoSenha *inicio;
    struct elementoSenha *fim;
    int qnt;
};

struct descritorMesa{
    struct mesa *inicio;
    struct mesa *fim;
    int quant;
};
/************************************/

/************************************/
//criando fila de senhas
FilaSenha* criar_fila_senha(){
    FilaSenha* fi = (FilaSenha*) malloc(sizeof(FilaSenha));

    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->qnt = 0;
    }
    return fi;
}

//criando fila
Fila* criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));

    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->qnt = 0;
    }
    return fi;
}

//criando fila
FilaMesa* criar_fila_mesa(){
    FilaMesa* fi = (FilaMesa*) malloc(sizeof(FilaMesa));

    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->quant = 0;
    }
    return fi;
}
/************************************/

/************************************/
//liberando filas

void libera_fila(Fila *fi){

    if(fi != NULL){
        Elemento *no;

        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }

        if(fi->inicio == NULL){
            fi->fim = NULL;
        }
        free(fi);
    }
}

void libera_fila_senhas(FilaSenha *fi){

    if(fi != NULL){
        Senha *no;

        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }

        if(fi->inicio == NULL){
            fi->fim = NULL;
        }
        free(fi);
    }
}

void libera_fila_mesa(FilaMesa *fi){
    if(fi != NULL){
        Mesa *no;

        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }

        if(fi->inicio == NULL){
            fi->fim = NULL;
        }
        free(fi);
    }
}

/************************************/

/************************************/
//criando elemento
Senha* cria_elemento_senha()
{
    // 'no' é um ponteiro do tipo Elemento
    Senha *no = (Senha*) malloc(sizeof(Senha));

    // verifica se a memória foi alocada corretamente
    if(no == NULL){
        return 0;
    }

    // retorna ponteiro alocado
    return no;
}

//criando elemento
Elemento* cria_elemento()
{
    // 'no' é um ponteiro do tipo Elemento
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    // verifica se a memória foi alocada corretamente
    if(no == NULL){
        return 0;
    }

    // retorna ponteiro alocado
    return no;
}

//criando elemento
Mesa* cria_elemento_mesa()
{
    // 'no' é um ponteiro do tipo Elemento
    Mesa *no = (Mesa*) malloc(sizeof(Mesa));

    // verifica se a memória foi alocada corretamente
    if(no == NULL){
        return 0;
    }

    // retorna ponteiro alocado
    return no;
}
/************************************/

int insere_Fila_senha(FilaSenha *fi, int num){
    if(fi == NULL){
        return -1;
    }

    //criando elemento que vai ser inserido
    Senha *no;
    no = cria_elemento_senha();

    //se a fila estiver vazia só insere
    if(fi->fim == NULL){

        no->senha = num;
        no->prox = NULL;

        //inicio aponta para no
        fi->inicio = no;
        fi->qnt = 1;
    }else{

        no->senha = num;
        no->prox = NULL;

        //o prox do fim aponta para o no
        fi->fim->prox = no;
        fi->qnt++;
    }

    //fi->fim aponta para no
    fi->fim = no;
    return 1;
}

int remove_fila_senha(FilaSenha *fi){
    if(fi == NULL){
        return -1;
    }
    Senha *atual = fi->inicio;
    fi->inicio = atual->prox;
    fi->qnt--;

    //verifico se a fila ficou vazia
    if(fi->qnt == 0){
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    free(atual);
    return 1;
}

int insere_fila(Fila *fi, Cliente *clientes){
    if(fi == NULL){
        return  -1;
    }

    Elemento *no;
    no = cria_elemento();

    if(fi->fim == NULL){
        no->clientes = clientes;
        no->prox = NULL;

        fi->inicio = no;
        fi->qnt = 1;
    }else{
        no->clientes = clientes;
        no->prox = NULL;

        fi->fim->prox = no;
        fi->qnt++;
    }
    fi->fim = no;

    return 1;
}

int remove_fila(Fila *fi){
    if(fi == NULL){
        return -1;
    }

    Elemento *atual = fi->inicio, *aSerExcluido;
    aSerExcluido = atual; //guardo elemento a ser excluido

    fi->inicio = atual->prox;
    fi->qnt--;

    //verifico se a fila ficou vazia
    if(fi->qnt == 0){
        fi->inicio = NULL;
        fi->fim = NULL;
    }

    //printamos o cliente que esta sendo excluido
    printCliente(aSerExcluido->clientes);

    free((atual));
    return 1;
}

int insere_fila_mesa(FilaMesa *fi, Cliente *clientes, int mesas){
    if(fi == NULL){
        return  -1;
    }

    Mesa *no;
    no = cria_elemento_mesa();

    if(fi->fim == NULL){
          no->id_mesa = mesas;
          no->clientes = clientes;
          no->prox = NULL;

        fi->inicio = no;
        fi->quant = 1;
    }else{
        no->id_mesa = mesas;
        no->clientes = clientes;
        no->prox = NULL;

        fi->fim->prox = no;
        fi->quant++;
    }
    fi->fim = no;

    return 1;
}

int remove_fila_mesa(FilaMesa *fi){
    if(fi == NULL){
        return -1;
    }

    Mesa *atual = fi->inicio;
    fi->inicio = atual->prox;
    fi->quant--;

    //verifico se a fila ficou vazia
    if(fi->inicio == NULL){
        fi->fim = NULL;
    }

    free(atual);

    return 1;
}

//criando a senha
int criar_senha(Cliente **clientes, FilaSenha *fi){
    int ok , op;

    *clientes = (Cliente*) malloc(sizeof(Cliente));

    do{
        printf("\nEscolha Tipo de atendimento \n");
        printf("[X] - Caixa\n");
        printf("[N] - Negocial\n");
        scanf(" %c", &(*clientes)->tipo_atend);

    }while ((*clientes)->tipo_atend != 'X' && (*clientes)->tipo_atend != 'N');

    system("clear");

    do{
        printf("\nEscolha Qual seu Perfil: \n");
        printf("[P] - Preferencial\n");
        printf("[C] - Convencional\n");
        scanf(" %c", &(*clientes)->perfil);

    }while ((*clientes)->perfil != 'P' && (*clientes)->perfil != 'C');

    system("clear");

    Senha *atual = fi->inicio;

    (*clientes)->senha = atual->senha;

    //concatenando os tipos de perfil
    (*clientes)->senhaFinal[strlen((*clientes)->senhaFinal)] = (*clientes)->tipo_atend;
    (*clientes)->senhaFinal[strlen((*clientes)->senhaFinal)] = (*clientes)->perfil;

    //removemos o numero disponive da senha
    remove_fila_senha(fi);

    //verificando o tipo de usuario que retirou a senha
    if((*clientes)->tipo_atend == 'X'){

        if((*clientes)->perfil == 'P'){ //escolhendo preferencial
            return 1;
        }
        if((*clientes)->perfil == 'C'){//escolhendo convencional
            return 2;
        }
    }else if( (*clientes)->tipo_atend == 'N' ){

        if((*clientes)->perfil == 'P'){ //escolhendo preferencial
            return 3;
        }
        if((*clientes)->perfil == 'C'){//escolhendo convencional
            return 4;
        }
    }else{
        return 0;
    }


}

int verificaTamanhoFila(Fila *fi){
    return fi->qnt;
}

int verificaTamanhoFilaMesa(FilaMesa *fi){
    return fi->quant;
}

//imprimindo mesa
void imprimir_mesa(FilaMesa *fi, int num){
    Mesa *atual = fi->inicio;

    while (atual != NULL){
        if(atual->id_mesa == num){
            //printf("Mesa %d\n", atual->id_mesa);
            printf("%s%d\n\n", atual->clientes->senhaFinal, atual->clientes->senha);
            remove_fila_mesa(fi); //depois de printar remove da fila mesa
        }
        atual = atual->prox;
    }
}

void printCliente(Cliente *clientes){
    printf("Senha %s%d\n", clientes->senhaFinal, clientes->senha);
}