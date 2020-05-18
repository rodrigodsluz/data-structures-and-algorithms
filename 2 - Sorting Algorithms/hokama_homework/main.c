#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct champion
{
    char *name;
    int tier;
} champion;

//Protótipo
void selection(champion *P, int n);

int main()
{
    int n;
    scanf("%d", &n);
    champion *P = (champion *)calloc(n, sizeof(champion));

    for (int i = 0; i < n; i++)
    {
        //scanf(" %[^\n]", P[i].name);
        //P[i].name[strlen(P[i].name) - 1] = '\0';
        scanf("%d", &(P[i].tier));
    }

    selection(P, n);

    for (int i = 0; i < n; i++)
    {
        //     printf("%s %d\n", P[i].name, P[i].tier);

        printf("%d\n", P[i].tier);
    }

    return 0;
}

void selection(champion *P, int n)
{
    int i, j, min;
    champion x;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (P[j].tier < P[min].tier)
            {
                min = j;
            }
        }
        x = P[min];
        P[min] = P[i];
        P[i] = x;
    }
}