/*
	Rodrigo Duarte Silva Luz - 2019003520
	Yasmin Karolyne Aniceto- 2018010440
	Matheus de Souza - 2019005909
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Definição do struct
typedef struct champion
{
    char *name;
    int tier;
} champion;

//Protótipos
void ordernar(champion *C, int start, int end);

void ordenaTier(champion *C, int start, int end);

void mergeSortIterativeTier(champion *C, int start, int end);

void mergeSortRecursiveTier(champion *C, int start, int end);

void ordenaChampionName(champion *C, int start, int end);

void mergeSortIterativeChampion(champion *C, int start, int end);

void mergeSortRecursiveChampion(champion *C, int start, int end);

int minimum(int a, int b);

void mergeTier(champion *C, int start, int middle, int end);

void mergeCamp(champion *C, int start, int middle, int end);

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
    ordernar(C, 0, n - 1);

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
void ordernar(champion *C, int start, int end)
{
    //ordena por número de tier
    ordenaTier(C, start, end);

    int tier_cont = C[0].tier, comeco = 0;
    //ordenar por nome do campẽo

    for (int i = 0; i <= end; i++)
    {
        if (C[i].tier != tier_cont)
        {

            ordenaChampionName(C, comeco, i - 1);
            comeco = i;
            tier_cont = C[i].tier;
        }
    }

    ordenaChampionName(C, comeco, end);
}

void ordenaTier(champion *C, int start, int end)
{

    int subvetor = floor((start + end) / 2);
    //versão iterativa
    if (subvetor <= 9)
    {
        mergeSortIterativeTier(C, start, end);
    }
    else
    {
        //versão recursiva
        mergeSortRecursiveTier(C, start, end);
    }
}

void mergeSortIterativeTier(champion *C, int start, int end)
{
    int i = 0, j = 0;
    for (i = 1; i <= end - start; i = i + i)
        for (j = start; j <= end - i; j += i + i)
            mergeTier(C, j, j + i - 1, minimum(j + i + i - 1, end));
}

void mergeSortRecursiveTier(champion *C, int start, int end)
{
    int middle = 0;

    if (start < end)
    {

        middle = floor((start + end) / 2);
        mergeSortRecursiveTier(C, start, middle);
        mergeSortRecursiveTier(C, middle + 1, end);
        mergeTier(C, start, middle, end);
    }
}

void ordenaChampionName(champion *C, int start, int end)
{

    int subvetor = floor((start + end) / 2);

    if (subvetor <= 9)
    {
        mergeSortIterativeChampion(C, start, end);
    }
    else
    {
        mergeSortRecursiveChampion(C, start, end);
    }
}

void mergeSortIterativeChampion(champion *C, int start, int end)
{

    int i = 0, j = 0;
    for (i = 1; i <= end - start; i = i + i)
        for (j = start; j <= end - i; j += i + i)
            mergeCamp(C, j, j + i - 1, minimum(j + i + i - 1, end));
}

void mergeSortRecursiveChampion(champion *C, int start, int end)
{
    int middle = 0;

    if (start < end)
    {

        middle = floor((start + end) / 2);
        mergeSortRecursiveChampion(C, start, middle);
        mergeSortRecursiveChampion(C, middle + 1, end);
        mergeCamp(C, start, middle, end);
    }
}

int minimum(int x, int y)
{
    // retorna o mínimo de dois números

    return (x < y) ? x : y;
}

void mergeCamp(champion *C, int start, int middle, int end)
{
    int size = 0, k1 = 0, k2 = 0, final1 = 0, final2 = 0;

    size = end - start + 1;
    k1 = start;
    k2 = middle + 1;

    champion *subv = (champion *)calloc(size, sizeof(champion));

    for (int i = 0; i < size; i++)
        subv[i].name = (char *)calloc(50, sizeof(char));

    if (subv != NULL)
    {

        for (int i = 0; i <= size; i++)
        {
            if (!final1 && !final2)
            {
                if (strcmp(C[k1].name, C[k2].name) <= 0)
                    subv[i] = C[k1++];
                else
                    subv[i] = C[k2++];
                if (k1 > middle)
                    final1 = 1;
                if (k2 > end)
                    final2 = 1;
            }
            else
            {
                if (!final1)
                    subv[i] = C[k1++];
                else
                    subv[i] = C[k2++];
            }
        }
        for (int i = 0, j = start; i < size; i++, j++)
        {
            C[j] = subv[i];
        }
    }
}

void mergeTier(champion *C, int start, int middle, int end)
{
    int size = 0, k1 = 0, k2 = 0, final1 = 0, final2 = 0;

    size = end - start + 1;
    k1 = start;
    k2 = middle + 1;

    champion *subv = (champion *)calloc(size, sizeof(champion));

    if (subv != NULL)
    {

        for (int i = 0; i < size; i++)
        {
            if (!final1 && !final2)
            {
                if (C[k1].tier < C[k2].tier)
                    subv[i] = C[k1++];
                else
                    subv[i] = C[k2++];
                if (k1 > middle)
                    final1 = 1;
                if (k2 > end)
                    final2 = 1;
            }
            else
            {
                if (!final1)
                    subv[i] = C[k1++];
                else
                    subv[i] = C[k2++];
            }
        }
        for (int i = 0, j = start; i < size; i++, j++)
        {
            C[j] = subv[i];
        }
    }

    free(subv);
}
