/*
1. Escreva um programa que leia um número l de linhas e um número c de colunas. Em seguida,
um vetor V de tamanho l * c e uma matriz M com l linhas e c colunas devem ser alocados
dinamicamente. Seu programa deve executar as tarefas abaixo sequencialmente, através de
chamadas de funções:
(a) Preencher o vetor V com valores inteiros digitados pelo usuário.
(b) Imprimir o vetor V na tela.
(c) Preencher a matriz M, sequencialmente, com os valores do vetor V .
(d) Imprimir a matriz M na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int *arrayAllocation(int l, int c);
void fillArray(int l, int c, int *v);
void printArray(int l, int c, int *v);

int **matrixAllocation(int l, int c);
void fillMatrix(int l, int c, int **M, int *v);
void printMatrix(int l, int c, int **M);


int main(){
	int l, c;
	int *v;
	printf("Enter the number of rows: ");
	scanf("%d", &l);
	printf("Enter the number of columns: ");
	scanf("%d", &c);
	
	v = arrayAllocation(l, c);
	
	printf("Enter the elements of array:\n");
	fillArray(l, c, v);
   
	printf("The numbers in array are: ");
	printArray(l, c, v);
	
	
	int **M;
	
	M = matrixAllocation(l, c);
	
	fillMatrix(l, c, M, v);
	
	printf("The values in matrix are:\n");
	printMatrix(l, c, M);
	
	
	
	return 0;
}

int *arrayAllocation(int l, int c){
	int *v;
	v = (int*)malloc((l*c)*sizeof(int));
	
	if(v == NULL){ 
		printf("Error");
		return NULL;
   }
   
   return v;
}

void fillArray(int l, int c, int *v){
	for(int i=0; i<l*c; i++){
		scanf("%d", &v[i]);		
	}
}

void printArray(int l, int c, int *v){
	for(int i=0; i<l*c; i++){
		printf("%d ", v[i]);		
	}
	printf("\n");
}

int **matrixAllocation(int l, int c){
	int **M;
		
	M = (int**)malloc(l*sizeof(int*));
	
	if(M == NULL){ 
		printf("Error!");
		return NULL;
   }
   
   for(int i=0;i<l;i++){
    
		M[i] = (int*) malloc(c * sizeof(int));
    
		if(M[i] == NULL){ 
			printf("Error!");
			return NULL;
		}
	}
	
	return M;
}
void fillMatrix(int l, int c, int **M, int *v){
	int x=0;
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
      
      M[i][j] = v[i*c+j];
	  //M[i][j] = v[x];
	  //x++;
		}
    }
}
void printMatrix(int l, int c, int **M){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			printf("%d", M[i][j]);
		}
		printf("\n");
	}
}