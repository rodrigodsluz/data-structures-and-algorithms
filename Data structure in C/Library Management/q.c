#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define tam 3
struct Biblioteca{
    char nome_livro[50];
    int id;
    int qtdade;
};
struct Biblioteca livros[tam];
struct Usuarios{
    char nome_cliente[50];
    int cpf;
};
struct Usuarios contas[tam];
void registarUsuario(int num, int cc);
void registarLivros(int ID, int cc, int max[]);
void mostraLivros();
int procuraLivro();
void emprestarLivros(int ret);
void devolverLivros(int dev, int max[]);
int verificacliente();
int i, cont=0;
int main(){
	
    int menu, contcliente=0, maxlivros[tam];
    do{
        printf("\n\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t*    Gerenciamento de biblioteca      *\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t*           Menu de Opções            *\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t* [1] Cadastrar usuário               *\n");
        printf("\t\t* [2] Cadastrar livros                *\n");
        printf("\t\t* [3] Verificar livros existentes     *\n");
        printf("\t\t* [4] Emprestar livros                *\n");
        printf("\t\t* [5] Devolver livros                 *\n");
        printf("\t\t* [6] Sair                            *\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\tOpção: ");
        scanf("%d", &menu);
        //printf("\e[H\e[2J");
		system("cls");
        switch(menu)
        {
            int ver_conta;
            case 1: 
                printf("\n\n");
                printf("\t\tDigite sua matrícula: ");
                scanf("%d", &ver_conta);
                registarUsuario(ver_conta, contcliente);
                break;
            case 2:
            {
                int ide;
                printf("\n\n");
                printf("\t\tDigite um ID para seu livro: ");
                scanf("%d", &ide);
                registarLivros(ide, contcliente, maxlivros);
                break;
            }
            case 3:
            {   
                int h;
                printf("\t\t1 - Ver todos os livros:\n");
                printf("\t\t2 - Pesquisar livro específico:\n");
                printf("\t\tOpção: ");
                scanf("%d", &h);
                if (h==1){
                    mostraLivros();
                }else{
                    if (procuraLivro()==1){
                        printf("\t\tID: %d\t\tNome: %s \t\tQuantidade: %d\n", livros[i].id,livros[i].nome_livro, livros[i].qtdade);
                    }else{
                        printf("\t\tNão existe esse livro!");
                    }
                }
            }
                break;
            case 4:
            {
                int retirar;
                if (verificacliente() == 1){
                    printf("\t\tDigite o ID do livro que deseja emprestar:");
                    scanf("%d", &retirar);
                    emprestarLivros(retirar);
                }else{
                    printf("\t\tVocê não está cadastrado!");
                }
                
            }
                break;
            case 5:
            {
                int devolver;
                if(verificacliente() == 1){
                    printf("\t\tDigite o ID do livro que deseja devolver:");
                    scanf("%d", &devolver);
                    devolverLivros(devolver, maxlivros);
                }else{
                    printf("\t\tVocê não está cadastrado!");
                }
            }
                break;
            default:
            
                break;
        }
    }while(menu != 6);
  system("pause");
  return 0;
}
void registarUsuario(int num, int cc){ 
    for (i=0;i<tam;i++){
        if (num!=contas[i].cpf){
           cc++;             
        }
    }
    if (cc==tam){
        contas[cont].cpf=num;
        printf("\t\tDigite seu nome: ");
        scanf(" %[^\n]",&contas[cont].nome_cliente);
        //printf("\e[H\e[2J");
		system("cls");
        printf("\n\t\t   Cadastro efetuado com sucesso!");
        //sleep(1.5);
        printf("\n");
        cc=0;
    }else{
        cont -= 1;
        //sleep(1.5);
        //printf("\e[H\e[2J");
		system("cls");
        printf("\n\t\tEssa matrícula já está cadastrada! Coloque outra!");
        cc=0;
    }
    cont++; 
}
void registarLivros(int ID, int cc, int max[]){
    for (i=0;i<tam;i++){
        if (ID!=livros[i].id){
           cc++;             
        }
    }
    if (cc==tam){
        livros[cont].id=ID;
        printf("\t\tDigite o nome do livro: ");
        scanf(" %[^\n]",&livros[cont].nome_livro);
        printf("\t\tDigite a quantidade: ");
        scanf("%d", &livros[cont].qtdade);
        max[cont] = livros[cont].qtdade;
        //printf("\e[H\e[2J");
		system("cls");
        printf("\n\t\tLivro cadastrado com sucesso!");
        cc=0;
    }else{
        cont -= 1;
        //printf("\e[H\e[2J");
		system("cls");
        printf("\n\t\tEsse livro já existe!");
        cc=0;
    }
    cont++;
}
void mostraLivros(){
    for(i=0; i<tam; i++){
        if(livros[i].qtdade>=0){
            printf("\t\tID: %d\t\tNome: %s\t\tQuantidade: %d\n\n", livros[i].id, livros[i].nome_livro, livros[i].qtdade);
        }
    }
}
int procuraLivro(){
    char nlivro[50];
    int numero;
    printf("\n\t\tDigite o nome do livro: ");
    scanf(" %[^\n]", &nlivro);
    for (i=0;i<tam;i++){
        numero=strncmp(nlivro, livros[i].nome_livro, 20);
        if (numero==0){
            return 1;
        }    
    }
}
void emprestarLivros(int ret){
    cont=0;
    for (i=0;i<tam;i++){
        if(ret == livros[i].id){
            cont++;
            if(livros[i].qtdade == 0){
                printf("\t\tTodos esses livros foram esprestados!\n"); 
            }else{
                livros[i].qtdade--;
                printf("\t\tRetirada efetuada com sucesso!");
            }
        }
    }
    if(cont==0){
        printf("\t\tEste livro não está registrado!");
    }
}
void devolverLivros(int dev, int max[]){
    cont=0;
    for (i=0;i<tam;i++){
        if(dev == livros[i].id){
            if(livros[i].qtdade < max[i]){
                printf("\t\tDevolução efetuada com sucesso!");
                livros[i].qtdade++;
            }else{
                printf("\t\tOps! Todos as edições desse livro já foram devolvidas. Tente novamente... \n");
            }
            cont++;
        }
    }
    if(cont==0){
        printf("\t\tEste livro não está registrado!");
    }
}
int verificacliente(){
    char nom[50];
    int numero;
    printf("\t\tDigite seu nome:");
    scanf(" %[^\n]", &nom);
    for (i=0;i<tam;i++){
        numero=(strcmp(nom, contas[i].nome_cliente));
        if (numero==0){
            return 1;
        }
    }
}