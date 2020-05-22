#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definição do struct
typedef struct champion
{
    char *name;
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

    //Pegar dados do usuário (um nome sem espaços e um inteiro)
    for (int i = 0; i < n; i++)
    {
        //Aloca espaço na memória para cada nome
        C[i].name = (char *)calloc(50, sizeof(char));
        scanf("%s %d", C[i].name, &(C[i].tier));
    }

    //Chamada da função para ordenar os números em estratos e os nomes entre eles em ordem alfabética
    selectionSort(C, n);

    //Imprimindo os valores de saída ordenados
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", C[i].name, C[i].tier);
    }

    //Libera espaço alocado na memória
    free(C);

    for (int i = 0; i < n; i++)
    {
        free(C[i].name);
    }

    return 0;
}

//Implementação da função de ordenação por seleção
void selectionSort(champion *C, int n)
{
    int i = 0, j = 0, menor = 0;
    champion x;
    champion *temp;
    //Alocando espaço na memória para o array temporário
    temp->name = (char *)calloc(50, sizeof(char));

    for (i = 0; i < n - 1; i++)
    {
        //Procura o menor elemento em relação a "i"
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (C[j].tier < C[menor].tier)
            {
                menor = j;
            }

            //Ordena os nomes que estão entre cada estrato em ordem alfabética
            if (C[j].tier == C[menor].tier)
            {
                //Se o nome do personagem do primeiro parâmetro for alfabeticamente maior que o do segundo parâmetro será retornado uma valor > 0. Nesse caso, o nome com índice de menor valor será alfabeticamente maior do que o nome que possui índice superior. Por isso, será preciso trocá-los de lugar.
                if (strcmp(C[menor].name, C[j].name) > 0)
                {
                    //Essa função copia o valor da variável do segundo parâmetro para a variável do primeiro. E com a ajuda da variável temporária é possível ordenar alfabeticamente. Na primeira linha a variável temp recebe o nome que possui valor alfabeticamente menor
                    strcpy(temp->name, C[j].name);
                    //Nessa segunda linha o nome que possui valor alfabético maior será copiado para C[j]
                    strcpy(C[j].name, C[menor].name);
                    //E finalmente, o nome que estava na varíavel temp será copiada para C[menor], ordenando tudo
                    strcpy(C[menor].name, temp->name);
                }
            }
        }
        //Troca os valores da posição atual com a "menor"
        x = C[menor];
        C[menor] = C[i];
        C[i] = x;
    }

    //Libera espaço alocado na memória
    free(temp->name);
}
