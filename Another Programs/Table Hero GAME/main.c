/*  (a) O jogo deve ter apenas um jogador (Ex: Resta 1, Jogo do 15, etc.).
    (b) O jogo deve ter algum esquema de pontuação que considera o nome do jogador e
    sua pontuação (utilizar registro - struct).
    (c) Mostrar um ranking de pontuação toda vez que um jogador terminar um jogo.
    (d) O programa deve conter um menu inicial que contenha pelo menos as opções:
    1. Jogar.
    2. Sair.
    (e) O programa só deve finalizar quando a opção Sair for escolhida. Caso contrário, o
    jogador pode escolher jogar novamente.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define tamMatriz 7


/*
    Struct
*/
typedef struct personagens{
    char rei;
    char goblin;
    char ogro;
    char cura;
    char escudo;
}Personagens;

typedef struct jogador{
    char nome[40];
    int HP;
    int record;
}Jogador;



/*
    PROTOTIPOS
*/
void executarJogo(char m[][tamMatriz]);
Jogador infoJogador();
void encontrarAlvo(char matriz[][tamMatriz], Personagens personagens, Jogador jogador);
char verificarArquivo(int linha, int coluna);
void record(int hp, char nome[40]);
void  mostrarRecord();


int main()
{
    char voltar;
    int menu;
    do{
    printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t*            NOME DO JOGO             *\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t*           Menu de Opcões            *\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t*             [1] Jogar               *\n");
    printf("\t\t*             [2] Instruções          *\n");
    printf("\t\t*             [3] História            *\n");
    printf("\t\t*             [4] Record              *\n");
    printf("\t\t*             [5] Sair                *\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\tOpção: ");
    scanf("%d", &menu);
    //printf("\e[H\e[2J");
	system("cls");
    switch(menu){
        case 1:
        {
            char matriz[tamMatriz][tamMatriz];
            executarJogo(matriz);
            break;
        }
        case 2:
        {
           
            do{
                printf("\t\tInstruções:\n\t\t1-Digite seu nome\n\t\t2-Digite as coordenadas da linha e da coluna para executar a movimentação\n\t\tobs: A linha e a coluna começam ambos em 0 (zero).");
                printf("\n\n");
                printf("\t\t[0] Voltar\n");
                printf("\t\t->");
                scanf("%c", &voltar);
                //printf("\e[H\e[2J");
				system("cls");
            }while(voltar!= '0');   
            //printf("\e[H\e[2J");
			system("cls");
            break;
        }
        case 3:
        {
            
            do{
                
                printf("Em um povoado distante, havia um reino pacífico, onde todas as criaturas viviam em paz.\n");
                printf("No castelo do rei morava uma princesa belíssima, que encantava a todos com sua beleza. Certa época,\n");
                printf("o reino foi invadido por criaturas horríveis, fortes e poderosas: os goblins e os orcs. Essas criaturas\n");
                printf("foram fortemente abatidas, porém, a defesa do castelo não foi capaz de deter a todos os monstros, e um deles,\n");
                printf("ao invadir o castelo, raptou a princesa, e fugiu. A princesa foi presa sob uma maldição em um labirinto cheio\n ");
                printf("de armadilhas, com um orc e um goblin o protegendo. A filha do rei recebeu 100 vidas, e a maldição faria com\n ");
                printf("que ela fosse torturada, perdendo suas vidas, cada vez que alguém a tentasse resgatar do labirinto, assim,\n ");
                printf("quem a fosse resgatar teria de ser forte, preciso e rápido.  O rei decretou então, que aquele que salvasse\n ");
                printf("sua filha das mãos dos inimigos a teria por esposa e viveriam felizes para sempre, e seu legado de herói\n ");
                printf("lendário seria espalhado por todos os reinos. Seria você esse herói lendário?\n");
                printf("\n\n");
                printf("\t\t[0] Voltar\n");
                printf("\t\t->");
                scanf("%c", &voltar);
                //printf("\e[H\e[2J");
				system("cls");
            }while(voltar!='0');   
            //printf("\e[H\e[2J"); 
			system("cls");
            break;
        }

        case 4:
        {
            do{
                //printf("\e[H\e[2J"); 
				system("cls");
                mostrarRecord();
                printf("\n\n");
                printf("\t\t[0] Voltar\n");
                printf("\t\t->");
                scanf("%c", &voltar);
            }while(voltar!= '0');   
            //printf("\e[H\e[2J"); 
			system("cls");
        }
    
        default:
        
            break;
    }
    }while(menu!=5);

    return 0;
}

/*
    FUNÇÔES
*/

void executarJogo(char m[][tamMatriz]){
    for(int i=0; i<tamMatriz; i++){
        for(int j=0; j<tamMatriz; j++){
            m[i][j] = '*';
        }
    }
    
    Personagens personagens;
    personagens.rei = 'R';
    personagens.goblin = 'G';
    personagens.ogro = 'O';
    personagens.cura = 'C';
    personagens.escudo = 'E';

    int cont = 0;
    int linha = 0;
    int coluna = 0;
    
    //Usando arquivos para salvar
    FILE* arqSaida = fopen("gabarito.txt","w");
    srand(time(NULL));
    do{
        linha = rand() % tamMatriz;
        coluna = rand() % tamMatriz;
        if (m[linha][coluna]=='*'){
        
            switch (cont){
                case 0:
                    m[linha][coluna] = personagens.rei;
                     fprintf(arqSaida,"%d %d %c \n",linha,coluna, personagens.rei);
                    break;
                case 1:
                    m[linha][coluna] = personagens.goblin;
                    fprintf(arqSaida,"%d %d %c \n",linha,coluna, personagens.goblin);
                    break;
                case 2:
                    m[linha][coluna] =  personagens.ogro;
                    fprintf(arqSaida,"%d %d %c \n",linha,coluna, personagens.ogro);
                    break;
                
                case 3:
                    m[linha][coluna] =  personagens.ogro;
                    fprintf(arqSaida,"%d %d %c \n",linha,coluna, personagens.cura);
                    break;
                case 4:
                    m[linha][coluna] =  personagens.ogro;
                    fprintf(arqSaida,"%d %d %c \n",linha,coluna, personagens.escudo);
                    break;
                
                default:
                    break;
            }
            cont++;
        }
        
    }while(cont != 5);
    fclose(arqSaida);

    for(int i=0; i<tamMatriz; i++){
        for(int j=0; j<tamMatriz; j++){
            m[i][j] = '*';
        }
    }

    Jogador jogador = infoJogador();
    /*ACAHR O ALVO*/
    encontrarAlvo(m,personagens,jogador);
    /*ACAHR O ALVO*/
}

void encontrarAlvo(char matriz[][tamMatriz], Personagens personagens,Jogador jogador){
    
    int contador = 0;
    int linha, coluna;
    int alvo = 0;
    int inimigos = 0;
    int efeitoEscudo = 0;

    do
    {
  
        printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t       %s              \n",jogador.nome);
        printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t     HP: %d                       \n",jogador.HP);
        printf("\t\t* * * * * * * * * * * * * * * * * * * *\n");
        printf("\n\n");
        for(int i=0; i<tamMatriz; i++){
            printf("\t\t\t\t");
            for(int j=0; j<tamMatriz; j++){
                printf(" %c", matriz[i][j]);
            }
            printf("\n");
        }
        
        do{
            printf("\n\n");
            printf("Digite a linha: ");
            scanf("%d",&linha);
            printf("Digite a coluna: ");
            scanf("%d",&coluna);
        } while ((linha < 0 || coluna < 0) || (linha > tamMatriz || coluna > tamMatriz));
        
        
        char alvo = verificarArquivo(linha,coluna);
        if (alvo=='R'||alvo=='O'||alvo=='G' ||alvo=='C' ||alvo=='E'){
            matriz[linha][coluna] = alvo;
            jogador.record+=15;
            if (alvo == 'C')
            {
                printf("Que sorte, você chegou até o altar da cura. Graças a isso a princesa ganhou 25HP\n");
                jogador.HP+=25;
                sleep(3);
            }else
            {
                if (alvo == 'E')
                {
                    printf("Você encontrou o cetro da proteção. Graças a ele a princesa recebeu 35HP.\n");
                                    jogador.HP+=35;
                    sleep(4);
                }else{
                    inimigos+=1;
                }
            }
            
        }else{
            matriz[linha][coluna] = 'X';
            jogador.HP -= 5;
        }
        //printf("\e[H\e[2J");
		system("cls");
                
    if (jogador.HP <= 0){
            printf("Infelizmente você PERDEU\n");
            record(jogador.record, jogador.nome);
        }else{
            if (inimigos==3)
            {
            printf("Você VENCEU e conseguiu salvar a princesa!!! \n");
            record(jogador.record, jogador.nome);
            }
            
        }
    } while (jogador.HP > 0 || inimigos != 3) ;

    
}

Jogador infoJogador(){
    Jogador jogador;
    printf("Nome do jogador: ");
    scanf(" %[^\n]",jogador.nome);
    jogador.HP = 100;
    jogador.record = 0;
    return jogador;
}

char verificarArquivo(int linha, int coluna){
    FILE* arqnome ;
    arqnome = fopen("gabarito.txt","r");
    char personagem;
    int colunaMatriz = 0;
    int linhaMatriz = 0;

    if (arqnome != NULL){
            while (fscanf(arqnome, "%d %d %c",&linhaMatriz, &colunaMatriz, &personagem) != EOF){
                
                if ((linha==linhaMatriz) && (coluna == colunaMatriz)){

                    switch (personagem){
                        case 'R':
                            return personagem;
                        break;
                        
                        case 'G':
                            return personagem;
                        break;

                        case 'O':
                            return personagem;
                        
                        case 'C':
                            return personagem;

                        case 'E':
                            return personagem;
                        break;
                    }
                }
                
            }  
        }
        
        fclose(arqnome);
    
}
void record(int record, char nome[40]){
    FILE* arqRecord = fopen("record.txt","a");
    fprintf(arqRecord,"%d %s \n", record, nome);
    fclose(arqRecord);
    mostrarRecord();
    main();
}

void  mostrarRecord(){
    printf("\n");
    FILE* fileRecord = fopen("record.txt","r");
    int contador = 0;
    char nome[40];
    int pontos;


    if (fileRecord != NULL){
        while (fscanf(fileRecord, "%d %[^\n]s",&pontos, nome) != EOF){
            
            printf("Nome do jogador: %s | Record: %d\n",nome,pontos);
            printf("\n");

            contador++;
        }  
    }

    fclose(fileRecord);

}