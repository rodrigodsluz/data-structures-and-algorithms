#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definição do struct
typedef struct champion
{
    char name[100];
    int tier;
} champion;

//Protótipo da função da ordenação por seleção
void selectionSort(champion *C, int n);

int main()
{
    //Número de linhas
    int n = 0;
    scanf("%d", &n);

    //Alocando espaço na memória para o struct champion
    champion *C = (champion *)calloc(n, sizeof(champion));

    printf("\n---------INPUT---------\n\n");

    //Pegar dados do usuário (um nome sem espaços e um inteiro)
    for (int i = 0; i < n; i++)
    {
        //Esse scanf é utilizado por maratonistas de programação, nesse caso ele pega todos os caracteres fornecidos pelo usuário até o caractere de espaço aparecer.
        scanf(" %[^ ] %d", C[i].name, &(C[i].tier));
    }

    //Chamada da função para ordenar os números em estratos e os nomes entre eles em ordem alfabética
    selectionSort(C, n);

    printf("\n---------OUTPUT---------\n\n");

    //Imprimindo os valores de saída ordenados
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", C[i].name, C[i].tier);
    }

    return 0;
}

//Implementação da função de ordenação por seleção
void selectionSort(champion *C, int n)
{
    int i, j, min = 0;
    champion x;

    //Alocando espaço na memória para o struct temporário
    champion *temp = (champion *)calloc(n, sizeof(champion));

    for (i = 0; i < n - 1; i++)
    {
        //Procura o menor elemento em relação a "i"
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (C[j].tier < C[min].tier)
            {
                min = j;
            }

            //Ordena os nomes que estão entre cada estrato em ordem alfabética
            if (C[j].tier == C[min].tier)
            {
                //Se o nome do personagem que está em determinado estrato for alfabeticamente maior que o próximo será retornado uma valor > 0
                if (strcmp(C[min].name, C[j].name) > 0)
                {
                    //Essa função copia o valor da variável do segundo parâmetro para a variável do primeiro. E com a ajuda da variável temporária é possível ordenar
                    strcpy(temp->name, C[j].name);
                    strcpy(C[j].name, C[min].name);
                    strcpy(C[min].name, temp->name);
                }
            }
        }
        //Troca os valores da posição atual com a "menor"
        x = C[min];
        C[min] = C[i];
        C[i] = x;
    }
}
