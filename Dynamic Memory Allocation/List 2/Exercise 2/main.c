/*
2. Escreva funções para lidar com matrizes triangulares inferiores de dimensão n * n, onde todos
os elementos abaixo da diagonal são iguais a zero e não devem ser alocados. No entanto, um
acesso a um elemento abaixo da diagonal deve retornar o valor zero. Escreva as seguintes
funções, usando a estratégia de vetor de ponteiros para armazenar a matriz.
(a) Função para criar uma matriz, onde n representa a dimensão da matriz, inicialmente com
os valores todos iguais a zero:
float **cria(int n);
(b) Função para atribuir o valor de um elemento da matriz, assumindo que i <= j:
void atribui(int i, int j, float x, float **m, int n);
(c) Função para acessar o valor de um elemento da matriz, inclusive elementos acima da
diagonal:
float acessa(int i, int j);
(d) Função para liberar a memória da matriz alocada:
void libera(int n, float **mat);
Escreva uma função main para testar as funções implementadas.
*/

#include <stdio.h>
#include <stdlib.h>

float **cria(int n);

void atribui(int i, int j, float x, float **m, int n);

float acessa(int i, int j, float **m, int n);

void libera(int n, float **m);

int main(){
	int n;
	printf("Enter the size: ");
	scanf("%d", &n);
	
	//(a)
	float **m = cria(n);
	
	//(b)
	printf("Enter the values:\n");
	float x;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%f", &x);
			atribui(i, j, x, m, n);
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%.2f ", m[i][j]);
		}
		printf("\n");
	}
	
	//(c)
	int a, b;
	printf("Enter the row: ");
	scanf("%d", &a);
	printf("Enter the column: ");
	scanf("%d", &b);
	
	float value =  acessa(a, b, m, n);
	
	printf("%.2f", value);
	
	//(d)
	libera(n, m);
	
	
	return 0;
}

float **cria(int n){
	float **m = (float**)calloc(n, sizeof(float*));
	
	if(m == NULL){ 
		printf("Insufficient memory!");
		return NULL;
	}
   
	for(int i=0; i<n; i++){
		m[i] = (float*)calloc((n-i), sizeof(float));
		
		if(m[i] == NULL){ 
			printf("Insufficient memory!");
			return NULL;
		}
	}
	
	return m;
	
}

void atribui(int i, int j, float x, float **m, int n){
	if(i<=j){
		m[i][j-i] = x;
	}
}

float acessa(int i, int j, float **m, int n){
	float value =  m[i][j];
	
	return value;
}

void libera(int n, float **m){
	free(*m);
}