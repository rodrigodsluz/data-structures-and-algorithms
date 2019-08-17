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

//Array allocation
int *arrayAllocation(int l, int c);
//To fill array
void fillArray(int l, int c, int *V);
//Print array
void printArray(int l, int c, int *V);

//2D array allocation
int **matrixAllocation(int l, int c);
//To fill 2D array
void fillMatrix(int l, int c, int **M, int *V);
///Print 2D array
void printMatrix(int l, int c, int **M);


int main(){
	int l, c;
	printf("Enter the number of rows: ");
	scanf("%d", &l);
	printf("Enter the number of columns: ");
	scanf("%d", &c);
	
	//Array allocation
	int *V;
	V = arrayAllocation(l, c);
	
	//To fill array
	printf("Enter the values of array:\n");
	fillArray(l, c, V);
   
	//Print array
	printf("The values in array are:\n");
	printArray(l, c, V);
	
	//2D array allocation
	int **M;
	M = matrixAllocation(l, c);
	
	//To fill 2D array
	fillMatrix(l, c, M, V);
	
	///Print 2D array
	printf("The values in matrix are:\n");
	printMatrix(l, c, M);
	
	//Deallocates both
	free(V);
	free(*M);
	
	return 0;
}

//Array allocation
int *arrayAllocation(int l, int c){
	int *V;
	V = (int*)malloc((l*c)*sizeof(int));
	
	if(V == NULL){ 
		printf("Insufficient memory!");
		return NULL;
   }
   
   return V;
}

//To fill array
void fillArray(int l, int c, int *V){
	for(int i=0; i<l*c; i++){
		scanf("%d", &V[i]);		
	}
}

//Print array
void printArray(int l, int c, int *V){
	for(int i=0; i<l*c; i++){
		printf("%d ", V[i]);		
	}
	printf("\n");
}

//2D array allocation
int **matrixAllocation(int l, int c){
	int **M;	
	M = (int**)malloc(l*sizeof(int*));
	
	if(M == NULL){ 
		printf("Insufficient memory!");
		return NULL;
   }
   
   for(int i=0;i<l;i++){
    
		M[i] = (int*) malloc(c * sizeof(int));
    
		if(M[i] == NULL){ 
			printf("Insufficient memory!");
			return NULL;
		}
	}
	
	return M;
}

//To fill 2D array
void fillMatrix(int l, int c, int **M, int *V){
	//int x=0;
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
      
      M[i][j] = V[i*c+j];
	  //M[i][j] = v[x];
	  //x++;
		}
    }
}

///Print 2D array
void printMatrix(int l, int c, int **M){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}