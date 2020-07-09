/*
	Rodrigo Duarte Silva Luz - 2019003520
	Yasmin Karolyne Aniceto- 2018010440
	Matheus de Souza - 2019005909
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definição do struct
typedef struct champion
{
    char *name;
    int tier;
} champion;

//Protótipos
void randomizedQuickSort(champion *C, int n);

void ordenar(champion *C, int start, int end, int subve);

int particionaTier(champion *C, int start, int end, int subve);

int main()
{
    //Número de linhas
    int n = 0;
    scanf("%d", &n);

    //Alocando espaço na memória para o struct champion
    champion *C = (champion *)calloc(n, sizeof(champion));

    //Pegar dados do usuário (um nome sem espaços e um inteiro)
    for (int i = 0; i < n; i++)
    {
        //Aloca espaço na memória para cada nome
        C[i].name = (char *)calloc(50, sizeof(char));
        scanf("%s %d", C[i].name, &(C[i].tier));
    }

    //Chamada da função para ordenar os números em estratos e os nomes entre eles em ordem alfabética
    randomizedQuickSort(C, n);

    //Imprimindo os valores de saída ordenados
    printf("\n\n--------OUTPUT--------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", C[i].name, C[i].tier);
    }

    //Libera espaço alocado na memória

    for (int i = 0; i < n; i++)
    {
        free(C[i].name);
    }

    free(C);

    return 0;
}

//Implementação das funções
void randomizedQuickSort(champion *C, int n)
{
    ordenar(C, 0, n, 0);
}

void ordenar(champion *C, int start, int end, int subve)
{
    int pivo, subvet = subve;
    char temp[50];
    //a variaveis subvet é para o controle de subvetores
    //ordenar por tier
    if (end > start)
    {
        //separa os dados em 2 partições
        pivo = particionaTier(C, start, end, subvet);
        subvet = 1;
        //Função para a primeira metade
        ordenar(C, start, pivo - 1, subvet);
        //Função para a segunda metade
        ordenar(C, pivo + 1, end, subvet);
    }

    for (int k = 0; k < end; k++)
    {
        if (C[k].tier == C[k + 1].tier)
        {

            if (strcmp(C[k].name, C[k + 1].name) > 0)
            {

                strcpy(temp, C[k].name);
                strcpy(C[k].name, C[k + 1].name);
                strcpy(C[k + 1].name, temp);
            }
        }
    }
}

int particionaTier(champion *C, int start, int end, int subvet)
{
    int esq, dir;

    int controle = (end - start) + 1; //controle do tamanho do vetor
    int posi;
    srand(time(NULL)); // Para valores aleatórios não se repetirem

    champion pivo, aux;
    esq = start;
    dir = end;
    pivo = C[start];

    //caso seja um subvetor
    if (subvet)
    {
        //posição aleatoria
        if (controle <= 5)
            posi = start + (rand() % (controle));
        //mediana de 3 posições aleatórias
        else
            posi = ((start + (rand() % (controle))) + (start + (rand() % (controle))) + (start + (rand() % (controle)))) / 3;

        //posicionar a posição aleatória escolhida, na posição de pivo
        aux = C[start];
        C[start] = C[posi];
        C[posi] = aux;
        pivo = C[start];
    }

    while (esq < dir)
    {
        // Avança posição da esquerda até encontrar numero maior que o pivo
        while (C[esq].tier <= pivo.tier)
            esq++;

        // Recua a posição da direita até encontrar numero menor que o pivo
        while (C[dir].tier > pivo.tier)
            dir--;

        // Trocar esq e dir
        if (esq < dir)
        {
            aux = C[esq];
            C[esq] = C[dir];
            C[dir] = aux;
        }
    }
    C[start] = C[dir];
    C[dir] = pivo;
    //retorna a posição do pivo
    return dir;
}
