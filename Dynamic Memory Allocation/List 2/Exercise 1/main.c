/*
1. Escreva uma função que receba um vetor V de n números inteiros e tenha como valor de retorno
um novo vetor, alocado dinamicamente, com os elementos do vetor original em ordem reversa.
A função deve ter como valor de retorno o ponteiro do vetor alocado, seguindo o protótipo:
int *reverso (int n, int *v)
Faça uma função main para testar sua função. Na função main, não esqueça de liberar a
memória alocada pela função auxiliar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *reverso(int n, int *v);

int main(){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
	int *v = (int*)malloc(n*sizeof(int));

	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	
	int *reverseArray = reverso(n, v);
	
	for(int i=0; i<n; i++){
		printf("%d ", reverseArray[i]);
	}
	
	free(reverseArray);
	return 0;
}

int *reverso(int n, int *v){
	//Optimized code by Leal
	int aux = 0;                                                                                                                                                                                  
    int retirar = n-1;
    
    for(int j = 0; j < floor(n/2); j++){
        aux = v[j];
        v[j] = v[retirar];
        v[retirar] = aux;
        retirar--;
        
    }
    
    return v;
	
	//Normal code
	/*
	int *array = (int*)malloc(n*sizeof(int));
	int j;
	for(int i=(n-1), j=0; i>=0; i--, j++){
		array[j] = v[i];
	}
		
	return array;
	*/
}