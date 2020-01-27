#include <stdio.h>
#include <stdlib.h>

#include "adt.h"


int main(){

    int quantSenha, i, ok, ok2, senhaChamada = 1, limRetirada=0, senhaRetiradas =0, op, aleat, contChamadaPre = 0;
    int atendimentosCaixa = 0, atendimentoNegocial = 0, ok3;
    Cliente *clientes;
    FilaSenha *filaSenha;
    Fila *XP;
    Fila *XC;
    Fila *NP;
    Fila *NC;
    FilaMesa *Mesas;

    printf("\n\nDigite Numero de senha a ser distribuida: ");
    scanf("%d", &quantSenha);

    system("clear");

    filaSenha = criar_fila_senha(); //criar uma fila com o numero de senhas disponiveis
    XP = criar_fila();
    XC = criar_fila();
    NP = criar_fila();
    NC = criar_fila();
    Mesas = criar_fila_mesa();


    //se nao criar erro
    if(filaSenha == NULL){
        printf("\nErro fatal, contate o Administrador\n");
    }else{

        //preenche a fila de senhas
        for(i = 1; i <= quantSenha; i++){
            ok = insere_Fila_senha(filaSenha,i);
        }

        if(ok == -1){
            printf("\nErro fatal, contate o Administrador\n");
        }else{
            printf("\nLimite de [%d] senhas estabelecido\n", quantSenha);
        }
    }

    //enquanto a quantidade de senhas chamadas for menos q a quantidade de senhas disponiveis
    while (senhaChamada <= quantSenha){

        //do para escolha da opção a ser executada
        do{
            printf("\nEscolha uma Opcao:\n");

            //menu
            if(limRetirada < quantSenha){
                printf("[1] - Retirar Senha\n");
            }else{
                printf("[INDISPONIVEL] - Retirar Senha\n");
            }

            if(senhaRetiradas == 0){
                printf("[INDISPONIVEL] - Chamar Senha\n");
            }else{
                printf("[2] - Chamar Senha\n");
            }
            scanf("%d", &op);
            system("clear");
        }while (op != 1 && op != 2);


        //se escolher retirar senha
        if(op == 1){

            if(limRetirada < quantSenha){

                ok = criar_senha(&clientes, filaSenha);//criando as senhas

                //Opções de tipos de clientes
                if(ok == 1){
                    //inserindo no caixa preferencial
                    ok2 = insere_fila(XP, clientes);
                    insere_fila_mesa(Mesas, clientes, 1); //inserindo na mesa do caixa
                    printf("\n Senha retirada para o caixa \n");
                    senhaRetiradas++; //contador para saber quantas senhas foram tiradas
                }else if(ok == 2){
                    ok2 = insere_fila(XC, clientes); //inserindo caixa convencional
                    insere_fila_mesa(Mesas, clientes, 1); //inserindo mesa caixa
                    //cliente vai para a fila convencional
                    printf("\n Senha retirada para o caixa \n");
                    senhaRetiradas++; //contador para saber quantas senhas foram tiradas
                }else if(ok == 3){
                    ok2 = insere_fila(NP, clientes); //inserindo negocial preferencial
                    insere_fila_mesa(Mesas, clientes, 2); //insere na mesa negocial
                    printf("\n Senha retirada para o negocial \n");
                    senhaRetiradas++; //contador para saber quantas senhas foram tiradas
                }else if(ok == 4){
                    ok2 = insere_fila(NC, clientes); //inserindo negocial convencional
                    insere_fila_mesa(Mesas, clientes, 2); //insere mesa negocial
                    printf("\n Senha retirada para o negocial \n");
                    senhaRetiradas++; //contador para saber quantas senhas foram tiradas
                }else{
                    printf("\n Erro \n");
                }
                limRetirada++;  //limite para retirdada
            }else{
                printf("\nSem senha para retirar \n");
            }
        }//fim op retirar senha

        //se escolher retirar senha
        if(op == 2){
            aleat = rand() % 2; //gerando aleatorio

            if(aleat == 1){ //se aletorio igual a 1

                //verificando tamanho caixa preferenecial
                ok = verificaTamanhoFila(XP);

                //se caixa preferencial nao estiver vazio
                if(ok > 0){
                    //verifica se chamou 2 preferenciais
                    if(contChamadaPre != 2){
                        printf("\nCAIXA\n");
                        ok2 = remove_fila(XP); //removendo da fila
                        if(ok2 == 1){
                            contChamadaPre++; //cont chamada preferencial para saber quando atingir 2 e chama um convencional
                            senhaChamada++;  //quantidade senha chamada
                            atendimentosCaixa++; //numero atendimentos no caixa
                        }
                    }else{
                        printf("\nCAIXA\n");
                        ok = verificaTamanhoFila(XC);
                        if(ok > 0){
                            ok2 = remove_fila(XC);  //removendo da fila
                            if(ok2 == 1){
                                contChamadaPre++; //cont chamada preferencial para saber quando atingir 2 e chama um convencional
                                senhaChamada++; //quant senha chamada
                                contChamadaPre = 0; //zera  a chamada preferencial
                                atendimentosCaixa++;  //numero atendimento caixa
                            }
                        }
                    }

                }else{//se fila caixa preferencia estiver vazia
                    ok2 = verificaTamanhoFila(XC);
                    if(ok2 > 0){
                        printf("\nCAIXA\n");
                        ok = remove_fila(XC);   //remove fila

                        if(ok ==1){
                            contChamadaPre++; //cont chamada preferencial para saber quando atingir 2 e chama um convencional
                            senhaChamada++; //numero senha chamada
                            atendimentosCaixa++; //nuemro atendimento caixa
                            contChamadaPre = 0; //zera chamada
                        }
                    } //else{ printf("Caixa vazio\n")} aki pode ter esse else de caixa vazio
                }
            }else{

                /*as variaveis , contChamada, senhaChamada, atendimentoNegocial e contChamadaPre
                 * tem as mesmas funções citada acima
                 * */

                ok = verificaTamanhoFila(NP);
                ok2 = verificaTamanhoFila(NC);

                if(ok != 0){
                    if(contChamadaPre != 2){
                        printf("\nNEGOCIAL\n");
                        ok3 = remove_fila(NP);

                        if(ok3 == 1){
                            contChamadaPre++;
                            senhaChamada++;
                            atendimentoNegocial++;
                        }
                    }else{
                        printf("\nNEGOCIAL\n");
                        ok3 = remove_fila(NC);

                        if(ok3 == 1){
                            contChamadaPre++;
                            senhaChamada++;
                            atendimentoNegocial++;
                            contChamadaPre = 0;
                        }
                    }
                }else{
                    if(ok2 != 0){
                        printf("\nNEGOCIAL\n");
                        ok3 = remove_fila(NC);

                        if(ok3 == 1){
                            contChamadaPre++;
                            senhaChamada++;
                            atendimentoNegocial++;
                            contChamadaPre = 0;
                        }
                    } //else{printf("Negociavel vazio\n");} aki pode ter esse else
                }
            }
        }
    }//fim do while

    ok = verificaTamanhoFilaMesa(Mesas);


    printf("\nRelatorio de Atendimento\n");
    printf("Foram feitos %d atendimentos no caixa.\n", atendimentosCaixa);
    printf("Foram feitos %d atendimentos no negocial.\n\n", atendimentoNegocial);

    printf("Mesa 1.\n");
    imprimir_mesa(Mesas, 1); //imprime mesas com id 1

    printf("Mesa 2.\n");
    imprimir_mesa(Mesas, 2); //imprime mesas com id 2

    libera_fila_senhas(filaSenha);
    libera_fila(XP);
    libera_fila(XC);
    libera_fila(NP);
    libera_fila(NC);
    libera_fila_mesa(Mesas);

    return 0;
}