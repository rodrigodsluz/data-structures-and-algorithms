#include<stdio.h>
#include<stdlib.h>

void criaHeap (int *V, int i,  int f)
{
    int aux = V[i];
    int j = i*2+1;
    while (j <= f){
        if (j<f)
            if (V[j] < V[j+1])
                j = j+1;

        if (aux < V[j]){
            V[i] = V[j];
            i = j;
            j = 2*i+1;
        }
        else
            j = f+1;
    }
    V[i] = aux;
}

void heapSort (int *V, int n)
{
    int i, aux;
    for (i=(n-1)/2; i>=0; i--){
        criaHeap (V, i, n-1);
    }
    for (i=n-1; i>=1; i--){
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        criaHeap (V, 0, i-1);
    }
}

int main ()
{
    int *V, n=10, i, inicio, fim;

    V = (int*) malloc(n*sizeof(int));
    printf("\nVetor Criado: \n");
    for (i=0; i<n; i++){
        V[i] = rand() % 100;
        printf (" %d",V[i]);
    }

    heapSort(V, n);

    printf ("\n\nVETOR ORDENADO NO HEAPSORT: \n");
    for (i=0; i<n; i++)
        printf (" %d",V[i]);

    printf("\n\n"); system("pause");
    return 0;
}