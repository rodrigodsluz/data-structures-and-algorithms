//
// Created by R
//

#include  <stdio.h>
#include <stdlib.h>

#include "adt.h"

int menu();

int main(void)
{
    Pilha *tubo1;  //declarando pilha para tubo 1
    Pilha *tubo2;  //declarando pilha para tubo 2
    Pilha *tubo3;  //declarando pilha para tubo 3
    int ok, tam, i, op, op2;
    char vet[5] = {'u', 'o', 'i', 'e', 'a'}; //criando vetor para preecher o pote 1
    char aux, compT1, compT2, compT3;  //variaveis char auxiliares

    /*Criando as pilhas*/
    tubo1 = criar_pilha();
    tubo2 = criar_pilha();
    tubo3 = criar_pilha();

    printf("|------------- Bem Vindo ao Jogo ----------------------| \n");
    printf("|                                                      |\n");
    printf("|Objetivo é passar todas as vogais do pote 1 ao pote 3,| \n");
    printf("|mantendo a mesma ordem seguindo as regras             | \n");
    printf("|                                                      |\n");
    printf("|   1 - A entrada nos tubos é por cima, a ultima vogal |\n");
    printf("|     a entrar será a primeira a sair                  |\n");
    printf("|   2 - Nunca em hipótese alguma, a vogal de cima      |\n");
    printf("|     será maior que a de baixo                        |\n");
    printf("|                                                      |\n");
    printf("|Boa Sorte                                             |\n");
    printf("|------------------------------------------------------|\n\n");

    /*Loop para preecher o primeiro tubo, onde a vogal (a) será a última a entrar na pilha*/
    for(i = 0; i < 5; i++){
        ok = empilhar(tubo1, vet[i]);
    }
    /**************************************************************************************/

    /*Tratando a primeira vogal a ser retirada do tubo 1*/

    do{//menu que pergunta aonde irá colocar a primeira vogal
        //printa as 3 pilhas na tela
        consulta_pilha(tubo1, tubo2, tubo3);
        printf("\nOnde deseja colocar a primeira vogal\n\n");
        printf("1 - P2\n");
        printf("2 - P3\n");
        printf(">");
        scanf("%d", &op);
        system("clear");
    }while(op != 1 && op != 2);

    //if para opção de inserir no pote 1
    if(op == 1){
      //variavel aux recebe a vogal que foi desempilhada do tubo 1
      aux = desempilhar(tubo1);

      //empilhando essa variavel que saiu do tubo 1  no tubo 2
      empilhar(tubo2, aux);

      //limpando a tela no linux
      system("clear");

    }

    //if para o inserir no pote 2
    if(op == 2){
      //variavel aux recebe a vogal que foi desempilhada do tubo 1
      aux = desempilhar(tubo1);

      //empilhando essa variavel que saiu do tubo 1  no tubo 2
      empilhar(tubo3, aux);

      //limpando a tela no linux
      system("clear");

    }
    /*Fim do tratamento da retirada da primeira vogal*/


    /*mexendo com restante das vogais, condição de parada vai ser quando a função checa tubo3 retornar 1
    * o que significara que a ordem estara igual ao começo só que no tubo 3 */

    do{ //inicio do

        //do da opção de retirar vogal
        do{
            //printando as 3 pilhas na tela
            consulta_pilha(tubo1, tubo2, tubo3);

            //chamando o menu
            op = menu();

            system("clear");
        }while (op != 1 && op != 2 && op != 3);

        
        //se escolher retirar a vogal do pote1
        if(op == 1){

            //verifica qual vogal vai ser retirada do pote 1
            compT1 = pegaVogal(tubo1);

            //se o retorno for igual a z, a pilha esta vazia logo nao podemos retirar nada dela
            if(compT1 == 'z'){
                printf("\nOperação nao permitida, pois pote esta vazio\n\n");

                //printa os 3 tubos na tela, e volta para chamada do menu
                consulta_pilha(tubo1, tubo2, tubo3);
            }else{

                //pergunta onde vai colocar a vogal no pote 2 ou 3
                do{
                  consulta_pilha(tubo1, tubo2, tubo3);
                  printf("\nOnde colocar a vogal retirada\n\n");
                  printf("1 - P2\n");
                  printf("2 - P3\n");
                  printf(">");
                  scanf("%d", &op2);
                  system("clear");
                }while(op2 != 1 && op2 != 2);
                
                //se escolher colocar no pote 2
                if(op2 == 1){
                    //ve qual vogal esta no topo do tubo2
                    compT2 = pegaVogal(tubo2);

                    //se a pilha 2 retornar z,ela esta vazia, logo só insere a vogal
                    if(compT2 == 'z'){
                        //aux recebe a vogal que esta sendo desempilhada no tubo 1
                        aux = desempilhar(tubo1);

                        //empilha a vogal que saiu do tubo 1 no tubo 2
                        empilhar(tubo2, aux);

                        //limpa tela no linux
                        system("clear");

                        //printa as 3 pilhas na tela
                        //consulta_pilha(tubo1, tubo2, tubo3);
                    }else{// se nao estiver vazia a pilha 2 

                      //comparamos se a vogal que sai do tubo 1 é menor que a vogal que esta no topo do tubo 2
                      if(compT1 < compT2){//se sim 
                        //aux recebe a vogal que esta sendo desempilhada do tubo 1
                        aux = desempilhar(tubo1);

                        //empilha no tubo 2 ---- continuar daki testar empilhar(tubo2, desempilhar(tubo1))
                        empilhar(tubo2, aux);
                        system("clear");
                        //consulta_pilha(tubo1, tubo2, tubo3);
                      }else{
                          printf("\nOperação nao permitida pois %c > %c\n\n",compT1, compT2);
                          //consulta_pilha(tubo1, tubo2, tubo3);
                      }
                    }//fim else compt2
                }//fim op2 onde coloca vogal

                //se escolher colocar no pote 3
                if(op2 == 2){
                    //ve qual vogal esta tubo3
                    compT3 = pegaVogal(tubo3);

                    //esta vazio ja insere
                    if(compT3 == 'z'){
                        aux = desempilhar(tubo1);
                        empilhar(tubo3, aux);
                        system("clear");
                        //consulta_pilha(tubo1, tubo2, tubo3);
                    }else{
                        if(compT1 < compT3){
                            aux = desempilhar(tubo1);
                            empilhar(tubo3, aux);
                            system("clear");
                            //consulta_pilha(tubo1, tubo2, tubo3);
                        }else{
                            printf("\nOperação nao permitida pois %c > %c\n\n",compT1, compT3);
                            //consulta_pilha(tubo1, tubo2, tubo3);
                        }
                    }
                }
            }//fim else compt1 vazio
        }//se escolher retirar de 1

        //se escolher retirar do pote 2
        if(op == 2){
            //ve qual vogal vai ser retirada
            compT2 = pegaVogal(tubo2);

            //se compT2 retornar z, a pilha esta vazia logo nao tem nada a tirar
            if(compT2 == 'z'){
                printf("\nOperação nao permitida, pois pote esta vazio\n\n");
                //consulta_pilha(tubo1, tubo2, tubo3);
            }else{
                //pergunta onde vai colocar a vogal
                do{
                    consulta_pilha(tubo1, tubo2, tubo3);
                    printf("\nOnde colocar a vogal retirada\n\n");
                    printf("1 - P1\n");
                    printf("2 - P3\n");
                    printf(">");
                    scanf("%d", &op2);
                    system("clear");
                }while(op2 != 1 && op2 != 2);

                //se kiser inserir em 1
                if(op2 == 1){
                    //ve qual vogal esta em tubo1
                    compT1 = pegaVogal(tubo1);

                    //se tubo 1 estiver vazio, só insere
                    if(compT1 == 'z'){
                        aux = desempilhar(tubo2);
                        empilhar(tubo1, aux);
                        system("clear");
                        //consulta_pilha(tubo1, tubo2, tubo3);
                    }else{//senao
                        //compara se o que esta saindo do tubo 2 é menor que o topo do tubo 1
                        if(compT2 < compT1){//se sim insere
                            aux = desempilhar(tubo2);
                            empilhar(tubo1, aux);
                            system("clear");
                            //consulta_pilha(tubo1, tubo2, tubo3);
                        }else{//se nao
                            printf("Operação nao permitida pois %c > %c\n\n",compT2, compT1);
                        }
                    }//fim else compt1 vazio
                }else if(op == 2){ //se kiser inserir no pote 3
                    //pega o topo do tubo 3
                    compT3 = pegaVogal(tubo3);

                    //se estiver vazio só insere
                    if(compT3 == 'z'){
                        aux = desempilhar(tubo2);
                        empilhar(tubo3, aux);
                        system("clear");
                        //consulta_pilha(tubo1, tubo2, tubo3);
                    }else{
                        //compara se o que sai do tubo 2 é menor que o topo de 3
                        if(compT2 < compT3){//se sim insere
                            aux = desempilhar(tubo2);
                            empilhar(tubo3, aux);
                            system("clear");
                            //consulta_pilha(tubo1, tubo2, tubo3);
                        }else{
                            printf("Operação nao permitida pois %c > %c\n\n",compT2, compT3);
                        }
                    }
                }
            }//fim compt2 vazio
        }//fim if retirar pote 2

        //se escolher retirar do pote 3
        if(op == 3){

            //ve qual vogal vai ser retirada
            compT3 = pegaVogal(tubo3);

            if(compT3 == 'z'){
                printf("Operação nao permitida, pois pote esta vazio\n");
            }else{

                //pergunta onde vai colocar a vogal
                do{
                    consulta_pilha(tubo1, tubo2, tubo3);
                    printf("Onde colocar a vogal retirada\n");
                    printf("1 - P1\n");
                    printf("2 - P2\n");
                    printf(">");
                    scanf("%d", &op2);
                    system("clear");
                }while(op2 != 1 && op2 != 2);

                //se kiser colocar no pote 1
                if(op2 == 1){

                    //pegando valor do topo do tubo 1
                    compT1 = pegaVogal(tubo1);

                    //se estiver vazio o topo 1 só insere
                    if(compT1 == 'z'){
                        //aux recebe o que esta sendo desempilhado do tubo 3
                        aux = desempilhar(tubo3);

                        //empilha no tubo 1
                        empilhar(tubo1, aux);

                        system("clear");
                        //consulta_pilha(tubo1, tubo2, tubo3);
                    }else{
                        if(compT3 < compT1){
                            aux = desempilhar(tubo3);
                            empilhar(tubo1, aux);
                            system("clear");
                            //consulta_pilha(tubo1, tubo2, tubo3);
                        }else{
                            printf("Operação nao permitida pois %c > %c\n\n",compT3, compT1);
                        }
                    }
                }else if(op2 == 2){ //se kiser inserir no pote 2
                    //pega o topo do pote 2
                    compT2 = pegaVogal(tubo2);

                    //se topo 2 estiver vazio só insere
                    if(compT2 == 'z'){
                        //aux recebe vogal desempilhada do tubo 3
                        aux = desempilhar(tubo3);

                        //empilha no tubo 2
                        empilhar(tubo2, aux);

                        system("clear");
                        //consulta_pilha(tubo1, tubo2, tubo3);
                    }else{
                        //comparando o que sai do tubo 3 com o topo de 2
                        if(compT3 < compT2){//se o q sai de 3 menor q topo 2 insere
                            //aux recebe vogal desempilhada do tubo 3
                            aux = desempilhar(tubo3);

                            //empilha no tubo 2
                            empilhar(tubo2, aux);

                            system("clear");
                            //consulta_pilha(tubo1, tubo2, tubo3);
                        }else{
                            printf("Operação nao permitida pois %c > %c\n\n",compT3, compT2);
                        }
                    }
                }
            }//fim else compt3 vazio
        }//fim op 3 pra retirar

        ok = verificaCerto(tubo3);
    }while(ok != 1);

    libera_pilha(tubo1);
    libera_pilha(tubo2);
    libera_pilha(tubo3);
    
    printf("\n\nPARABENS!!!!!!!!!!!!!!!!!!\n");

    printf("\n\nfim do programa\n\n");

    return 0;
}

int menu(){
  int op;

  printf("\nOnde deseja retirar a vogal\n\n");
  printf("1 - P1\n");
  printf("2 - P2\n");
  printf("3 - P3\n");
  printf(">");
  scanf("%d", &op); 
  return op;
}