/*
    Olá, Sr Lucas, por favor, mude o que puder para o professor não perceber alguma semelhança...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct champion
{
    char *name;
    int tier;
} champion;

void selectionSort(champion *C, int n);

int main()
{

    int n = 0;
    scanf("%d", &n);

    champion *C = (champion *)calloc(n, sizeof(champion));

    for (int i = 0; i < n; i++)
    {

        C[i].name = (char *)calloc(50, sizeof(char));
        scanf("%s %d", C[i].name, &(C[i].tier));
    }

    selectionSort(C, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", C[i].name, C[i].tier);
    }

    for (int i = 0; i < n; i++)
    {
        free(C[i].name);
    }

    free(C);

    return 0;
}

void selectionSort(champion *C, int n)
{
    int i = 0, j = 0, menor = 0;
    char temp[50];
    champion x;

    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (C[j].tier < C[menor].tier)
            {
                menor = j;
            }

            if (C[j].tier == C[menor].tier)
            {

                if (strcmp(C[menor].name, C[j].name) > 0)
                {

                    strcpy(temp, C[j].name);
                    strcpy(C[j].name, C[menor].name);
                    strcpy(C[menor].name, temp);
                }
            }
        }
        x = C[menor];
        C[menor] = C[i];
        C[i] = x;
    }
}
