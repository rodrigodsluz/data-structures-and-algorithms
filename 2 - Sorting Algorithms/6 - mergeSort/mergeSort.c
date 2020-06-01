/*
	Rodrigo Duarte Silva Luz - 2019003520
	Yasmin Karolyne Aniceto- 2018010440
	Matheus de Souza - 2019005909
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//Definição do struct
typedef struct champion
{
    char *name;
    int tier;
} champion;

//Protótipos
void mergeSort(champion *C, int esq, int dir);

void mergeTier(champion *C, int esq, int mid, int dir);

void mergeChampionName(champion *C, int esq, int mid, int dir);

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
    mergeSort(C, 0, n - 1);

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

void mergeSort(champion *C, int esq, int dir)
{
    int mid = (esq + dir) / 2;
    if (esq < dir)
    {
        mergeSort(C, esq, mid);
        mergeSort(C, mid + 1, dir);
        mergeTier(C, esq, mid, dir);
        mergeChampionName(C, esq, mid, dir);
    }
}

void mergeTier(champion *C, int esq, int mid, int dir)
{
    int aux[MAX];
    char temp[MAX];
    int i = esq, j = mid + 1, k = 0;

    while (i <= mid && j <= dir)
        if (C[i].tier <= C[j].tier)
        {
            aux[k++] = C[i++].tier;
        }
        else
        {
            aux[k++] = C[j++].tier;
        }

    while (i <= mid)
        aux[k++] = C[i++].tier;
    while (j <= dir)
        aux[k++] = C[j++].tier;

    for (i = esq, k = 0; i <= dir; i++, k++)
        C[i].tier = aux[k];
}

void mergeChampionName(champion *C, int esq, int mid, int dir)
{
    int nL = mid - esq + 1;
    int nR = dir - mid;

    char **L = malloc(sizeof(char *) * nL);
    char **R = malloc(sizeof(char *) * nR);
    int i;
    for (i = 0; i < nL; i++)
    {
        L[i] = malloc(sizeof(C[esq + i]));
        strcpy(L[i], C[esq + i].name);
    }
    for (i = 0; i < nR; i++)
    {

        R[i] = malloc(sizeof(C[mid + i + 1]));
        strcpy(R[i], C[mid + i + 1].name);
    }
    int j = 0, k;
    i = 0;
    k = esq;
    while (i < nL && j < nR)
    {
        if (strcmp(L[i], R[j]) < 0)
            strcpy(C[k++].name, L[i++]);

        else
            strcpy(C[k++].name, R[j++]);
    }

    while (i < nL)
        strcpy(C[k++].name, L[i++]);
    while (j < nR)
        strcpy(C[k++].name, R[j++]);
}
