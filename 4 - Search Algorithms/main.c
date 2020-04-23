/*
    Rodrigo Duarte Silva Luz - 2019003520
    Yasmin Karolyne Ancieto Carvalho - 2018010440
    Matheus de Souza - 2019005909
*/

// Nesse trabalho você vai implementar uma busca sequencial, uma busca sequencial para quando o arranjo está ordenado, e uma busca binária. Na busca binária você deve verificar o elemento que está na posição (esquerda + direita) / 2 e imprimir esse elemento durante a busca.

// A entrada é dada da seguinte forma:
// n x0 x1 x2 ... x(n-1) e

// c
// Onde "n" é o número de elementos da lista, x0 até x(n-1) são os elementos da lista (por praticidade existe um espaço em branco depois do ultimo elemento), "e" é o elemento que queremos encontrar na lista e "c" é um caractere que diz qual busca estamos interessados, podendo ser:

// s - Busca sequencial padrão S - Busca sequencial que tira proveito de um vetor ordenado B - Busca binária

// No final o seu programa deverá imprimir a posição em que o elemento foi encontrado ou -1 caso não esteja na lista, seguido por uma quebra de linha (sugiro imprimir com "%d\n"), seu programa deve dar um "return 0" no final.

#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int x[], int n, int e);

int buscaOrdenada(int x[], int n, int e);

int buscaBinaria(int x[], int n, int e);

int main()
{
    //número de elementos da lista
    int n = 0;

    scanf("%d", &n);

    //x0 até x(n-1) são os elementos da lista
    int x[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    //elemento que queremos encontrar na lista
    int e = 0;
    scanf("%d", &e);

    //caractere que diz qual busca estamos interessados
    char c;
    scanf("%c ", &c);

    // s - Busca sequencial padrão S - Busca sequencial que tira proveito de um vetor ordenado B - Busca binária
    char s, S, B;

    int retorna = 0;

    if (c == 's')
    {
        retorna = buscaLinear(x, n, e);
        printf("%d\n", retorna);
    }
    else if (c == 'S')
    {
        retorna = buscaOrdenada(x, n, e);
        printf("%d\n", retorna);
    }
    else
    {
        retorna = buscaBinaria(x, n, e);
        printf("%d\n", retorna);
    }

    return 0;
}

int buscaLinear(int x[], int n, int e)
{
    int i;
    for (i = 0; i < n; i++)
        if (e == x[i])
            return i;

    return -1;
}

int buscaOrdenada(int x[], int n, int e)
{
    int i;
    for (i = 0; i < n; i++)
        if (e == x[i])
            return i;
        else if (e < x[i])
            return -1;

    return -1;
}

int buscaBinaria(int x[], int n, int e)
{
    int inicio, meio, fim;
    inicio = 0;
    fim = n - 1;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (e < x[meio])
            fim = meio - 1;
        else if (e > x[meio])
            inicio = meio + 1;
        else
            return meio;
    }
    return -1;
}