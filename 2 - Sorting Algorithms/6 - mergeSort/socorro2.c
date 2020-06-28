/*
	Rodrigo Duarte Silva Luz - 2019003520
	Yasmin Karolyne Aniceto- 2018010440
	Matheus de Souza - 2019005909
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Definição do struct
typedef struct champion
{
    char *name;
    int tier;
} champion;

//Protótipos
void ordernar(champion *V, int inicio, int fim);

void ordenaTier(champion *V, int inicio, int fim);

void mergeSort_IterativoTier(champion *V, int inicio, int fim);

void mergeSortTier(champion *V, int inicio, int fim);

void ordenaCamp(champion *V, int inicio, int fim);

void mergeSort_IterativoCamp(champion *V, int inicio, int fim);

void mergeSortCamp(champion *V, int inicio, int fim);

int min(int x, int y);

void mergeTier(champion *V, int inicio, int meio, int fim);

void mergeCamp(champion *V, int inicio, int meio, int fim);

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
void ordernar(champion *V, int inicio, int fim)
{

    //ordenar por tier
    ordenaTier(V, inicio, fim);

    //ordenar por campeao
    int origem = 0, cont_tier = V[0].tier;
    //percorrendo a lista
    for (int i = 0; i <= fim; i++)
    {
        //procurando a posição em que se altera o tier
        if (V[i].tier != cont_tier)
        {
            //com a mudança de tier, encontramos a posição final do tier atribuido ao cont_tier
            //possui aqui então o inicio e fim do tier na lista
            //é passado como parametro "i-1" e "origem", que representam respectivamente a posição final e inicial do tier
            ordenaCamp(V, origem, i - 1);
            //"inicio" recebe a posição inicial do novo tier
            origem = i;
            //"cont_tier" recebe o novo tier
            cont_tier = V[i].tier;
        }
    }

    //ordernar ultimo tier que a função não encontra
    ordenaCamp(V, origem, fim);
}

//Verica qual merge sorte utilizará para ordenar
void ordenaTier(champion *V, int inicio, int fim)
{

    int subvetor = floor((inicio + fim) / 2); //achando o tamanho do subvetor

    if (subvetor <= 9)
    {
        mergeSort_IterativoTier(V, inicio, fim);
    }
    else
    {
        mergeSortTier(V, inicio, fim);
    }
}

//Ordernar de forma iterativa
void mergeSort_IterativoTier(champion *V, int inicio, int fim)
{
    int i, m;
    for (m = 1; m <= fim - inicio; m = m + m)
        for (i = inicio; i <= fim - m; i += m + m)
            mergeTier(V, i, i + m - 1, min(i + m + m - 1, fim));
}

void mergeSortTier(champion *V, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {

        meio = floor((inicio + fim) / 2);
        //divide o vetor em 2 subetores
        mergeSortTier(V, inicio, meio);
        mergeSortTier(V, meio + 1, fim);
        //junta os vetores de ordem ordenada
        mergeTier(V, inicio, meio, fim);
    }
}

//Verica qual merge sorte utilizará para ordenar
void ordenaCamp(champion *V, int inicio, int fim)
{

    int subvetor = floor((inicio + fim) / 2); //achando o tamanho do subvetor

    if (subvetor <= 9)
    {
        mergeSort_IterativoCamp(V, inicio, fim);
    }
    else
    {
        mergeSortCamp(V, inicio, fim);
    }
}

//Ordernar de forma iterativa
void mergeSort_IterativoCamp(champion *V, int inicio, int fim)
{
    int i, m;
    for (m = 1; m <= fim - inicio; m = m + m)
        for (i = inicio; i <= fim - m; i += m + m)
            mergeCamp(V, i, i + m - 1, min(i + m + m - 1, fim));
}

void mergeSortCamp(champion *V, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {

        meio = floor((inicio + fim) / 2);
        //divide o vetor em 2 subetores
        mergeSortCamp(V, inicio, meio);
        mergeSortCamp(V, meio + 1, fim);
        //junta os vetores de ordem ordenada
        mergeCamp(V, inicio, meio, fim);
    }
}

// Função para encontrar no mínimo dois números inteiros
int min(int x, int y)
{
    return (x < y) ? x : y;
}

void mergeCamp(champion *V, int inicio, int meio, int fim)
{
    int p1, p2, tam;
    int fim1 = 0, fim2 = 0;

    tam = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    //Criando vetor auxiliar
    champion *sub = (champion *)calloc(tam, sizeof(champion));
    //alocação dinâmica de espaço para a lista de campeões

    for (int i = 0; i < tam; i++)
        sub[i].name = (char *)calloc(50, sizeof(char));

    if (sub != NULL)
    {

        for (int i = 0; i <= tam; i++)
        {
            if (!fim1 && !fim2)
            {
                // Combinar ordenando
                if (strcmp(V[p1].name, V[p2].name) <= 0)
                    sub[i] = V[p1++];
                else
                    sub[i] = V[p2++];
                // Vetor acabou?
                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                // Copia o que sobrar
                if (!fim1)
                    sub[i] = V[p1++];
                else
                    sub[i] = V[p2++];
            }
        }
        //Transferindo valores do vetor auxiliar, para o original
        for (int i = 0, k = inicio; i < tam; i++, k++)
        {
            V[k] = sub[i];
        }
    }

    /*   for (int i = 0; i < tam; i++)
        free((sub[i].name)); */

    //free(sub);
}

void mergeTier(champion *V, int inicio, int meio, int fim)
{
    int p1, p2, tam;
    int fim1 = 0, fim2 = 0;

    tam = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    //Criando vetor auxiliar
    champion *sub = (champion *)calloc(tam, sizeof(champion));
    //alocação dinâmica de espaço para a lista de campeões

    /*  for (int i = 0; i < tam; i++)
        sub[i].name = (char *)calloc(50, sizeof(char)); */

    if (sub != NULL)
    {

        for (int i = 0; i < tam; i++)
        {
            if (!fim1 && !fim2)
            {
                // Combinar ordenando
                if (V[p1].tier < V[p2].tier)
                    sub[i] = V[p1++];
                else
                    sub[i] = V[p2++];
                // Vetor acabou?
                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                // Copia o que sobrar
                if (!fim1)
                    sub[i] = V[p1++];
                else
                    sub[i] = V[p2++];
            }
        }
        //Transferindo valores do vetor auxiliar, para o original
        for (int i = 0, k = inicio; i < tam; i++, k++)
        {
            V[k] = sub[i];
        }
    }

    //liberando vetor auxiliar
    /* 
    for (int i = 0; i < tam; i++)
        free(sub[i].name); */

    free(sub);
}
