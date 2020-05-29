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

void ordenar(int esq, int dir, champion *C);

int particaoTier(champion *C, int start, int end, int subvet);

int particaoChampionName(champion *C, int start, int end);

void quickSortTier(champion *C, int start, int end, int subve);

void quickSortChampionName(champion *C, int start, int end);

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
    ordenar(0, n, C);
}

void ordenar(int start, int end, champion *C)
{

    //ordena por número de tier
    quickSortTier(C, start, end, 0);

    //ordenar por nome do campẽo
    int tier_cont = C[0].tier, comeco = 0;

    for (int i = 0; i <= end; i++)
    {
        //procura posição em que muda o tier
        if (C[i].tier != tier_cont)
        {
            /* Devido ao tier trocar, encontra-se a posição final do tier atribuido ao tier_cont
            captura então o começo e o final do tier na lista
            como parametro é passado i-1 e começo, que representam a posição final e inicial do tier */
            quickSortChampionName(C, comeco, i - 1);
            //start recebe a posição inicial do novo tier
            comeco = i;
            //tier_cont pega o novo tier
            tier_cont = C[i].tier;
        }
    }
}

int particaoTier(champion *C, int start, int end, int subvet)
{

    //tamanho vetor control
    int control = (end - start) + 1;
    int posicao = 0;
    int esq = 0, dir = 0;
    //srand para não repetir valores
    srand(time(NULL));

    champion pivo, temp;
    pivo = C[start];
    esq = start;
    dir = end;

    if (subvet)
    {
        //aleatório
        if (control <= 5)
            posicao = start + (rand() % (control));
        //mediana das posições
        else
            posicao = ((start + (rand() % (control))) + (start + (rand() % (control))) + (start + (rand() % (control)))) / 3;

        //por a posição aleatória escolhida, na posição de pivo
        temp = C[start];
        C[start] = C[posicao];
        C[posicao] = temp;
        pivo = C[start];
    }

    while (esq < dir)
    {
        // Vai pra posição da esquerda até encontrar numero maior que o pivo
        while (C[esq].tier <= pivo.tier)
            esq++;

        // Volta a posição da direita até encontrar numero menor que o pivo
        while (C[dir].tier > pivo.tier)
            dir--;

        // Muda esq e dir
        if (esq < dir)
        {
            temp = C[esq];
            C[esq] = C[dir];
            C[dir] = temp;
        }
    }
    C[start] = C[dir];
    C[dir] = pivo;
    //retorna a posição do pivo escolhido
    return dir;
}

int particaoChampionName(champion *C, int start, int end)
{
    int esq, dir, posicao;
    //Encontra tamanho do vetor
    int control = (end - start) + 1;
    champion pivo, temp;
    esq = start;
    dir = end;
    pivo = C[start];

    //posição aleatoria
    if (control <= 5)
        posicao = start + (rand() % (control));
    //mediana das 3 posições
    else
        posicao = ((start + (rand() % (control))) + (start + (rand() % (control))) + (start + (rand() % (control)))) / 3;

    //posiciona a posição aleatória escolhida, na posição de pivo
    temp = C[start];
    C[start] = C[posicao];
    C[posicao] = temp;
    pivo = C[start];
    pivo = C[start];

    while (esq < dir)
    {
        // Vai pra posição da esquerda até encontrar numero maior que o pivo
        while (strcmp(C[esq].name, pivo.name) <= 0)
        {
            esq++;
            if (esq == end)
                break;
        }
        // Volta a posição da direita até encontrar numero menor que o pivo
        while (strcmp(C[dir].name, pivo.name) > 0)
        {
            dir--;
            if (dir == start)
                break;
        }
        //Muda esq e dir
        if (esq < dir)
        {
            temp = C[esq];
            C[esq] = C[dir];
            C[dir] = temp;
        }
    }

    C[start] = C[dir];
    C[dir] = pivo;
    //retorna a posição do pivo
    return dir;
}

void quickSortTier(champion *C, int start, int end, int subve)
{
    //subvet controla subvetores
    int pivo = 0, subvet = subve;

    //ordenar por número de tier
    if (end > start)
    {
        //separa os dados em 2 partições
        pivo = particaoTier(C, start, end, subvet);
        subvet = 1;
        //Primeira metade
        quickSortTier(C, start, pivo - 1, subvet);
        //Segunda metade
        quickSortTier(C, pivo + 1, end, subvet);
    }
}

void quickSortChampionName(champion *C, int start, int end)
{
    int pivo;
    //ordenar por nome de campeo
    if (end > start)
    {
        //separa os dados em 2 partições
        pivo = particaoChampionName(C, start, end);
        //Primeira metade
        quickSortChampionName(C, start, pivo - 1);
        //Segunda metade
        quickSortChampionName(C, pivo + 1, end);
    }
}
