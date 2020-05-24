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

void ordena(int esq, int dir, champion *C);

void particao(int esq, int dir, int *i, int *j, champion *C);

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

//Implementação da função de ordenação por seleção

void particao(int esq, int dir, int *i, int *j, champion *C)
{
    srand(time(NULL));
    champion x, w;
    *i = esq;
    *j = dir;
    x = C[(*i + *j) / 2]; //obtem o pivô
    int a = 0;

    //x.tier = (rand() % 6) + 1;
    printf("%d", x);
    for (int r = *i; r < x.tier; r++)
    {
        a++;
        if (a == 5)
        {
            x.tier = (rand() % 6) + 1;
            printf("%d", x.tier);
        }
    }
    /* for (int r = *i; r < *j; r++)
    {
        if (x.tier == C[1].tier)
        {
            x = C[(*i + *j) / 2];
        }
    } */

    do
    {
        while (x.tier > C[*i].tier)
            (*i)++;

        while (x.tier < C[*j].tier)
            (*j)--;

        if (*i <= *j)
        {
            w = C[*i];
            C[*i] = C[*j];
            C[*j] = w;
            (*i)++;
            (*j)--;
        }

    } while (*i < *j);
}

void ordena(int esq, int dir, champion *C)
{
    int i = 0, j = 0;
    char temp[50];

    particao(esq, dir, &i, &j, C);

    if (esq < j)
    {
        ordena(esq, j, C);
    }
    if (i < dir)
    {
        ordena(i, dir, C);
    }

    for (int k = 0; k < dir; k++)
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

void randomizedQuickSort(champion *C, int n)
{
    ordena(0, n - 1, C);
}

//Se o nome do personagem do primeiro parâmetro for alfabeticamente maior que o do segundo parâmetro será retornado uma valor > 0. Nesse caso, o nome com índice de j valor será alfabeticamente maior do que o nome que possui índice superior. Por isso, será preciso trocá-los de lugar.
/* if (strcmp(C[j].name, C[j].name) > 0)
                {
                    //Essa função copia o valor da variável do segundo parâmetro para a variável do primeiro. E com a ajuda da variável temporária é possível ordenar alfabeticamente. Na primeira linha a variável temp recebe o nome que possui valor alfabeticamente j
                    strcpy(temp, C[j].name);
                    //Nessa segunda linha o nome que possui valor alfabético maior será copiado para C[j]
                    strcpy(C[j].name, C[j].name);
                    //E finalmente, o nome que estava na varíavel temp será copiada para C[j], ordenando tudo
                    strcpy(C[j].name, temp);
                } */
