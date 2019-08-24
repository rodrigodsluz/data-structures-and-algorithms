/*
3. Escreva:
(a) Uma função para converter uma matriz representada por um vetor numa matriz represen-
tada por um vetor de ponteiros:
float **converte_a(int m, int n, float *mat);
(b) Uma função para converter uma matriz representada por um vetor de ponteiros numa
matriz representada por um vetor:
float *converte_b(int m, int n, float **mat);
Escreva também as funções para criar as matrizes e implemente uma função main para testar
as conversões.
*/

#include <stdio.h>
#include <stdlib.h>

float **converte_a(int m, int n, float *mat);

float *converte_b(int m, int n, float **mat2);

int main(){
	int m, n;
	printf("Enter the number of rows: ");
	scanf("%d", &m);
	printf("Enter the number of columns: ");
	scanf("%d", &n);
	
	float *mat = (float*)malloc((m*n)*sizeof(float));
	
	for(int i=0; i<m*n; i++){
		scanf("%f", &mat[i]);
	}
	
	
	float **mat2 = converte_a(m, n, mat);
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%.2f ", mat2[i][j]);
		}
		printf("\n");
	}
	
	float *newArray;
	newArray = converte_b(m, n, mat2);
	for(int i=0; i<(m*n); i++){
		printf("%.2f ", newArray[i]);
	}
	
	return 0;
}

float **converte_a(int m, int n, float *mat){
	float **mat2 = (float**)malloc(m*sizeof(float*));
	
	for(int i=0; i<m; i++){
		mat2[i] = (float*)malloc(n*sizeof(float));
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			mat2[i][j] = mat[i*n+j];
		}
	}
	
	return mat2;
}

float *converte_b(int m, int n, float **mat2){
	float *newArray = (float*)malloc((m*n)*sizeof(float));
	
	//int temp = 0;
	for(int i = 0; i < m; i++ ){
		for(int j = 0; j < n; j++ ){
			newArray[i*n+j] = mat2[i][j];
			//temp++;
		}
	}
	/*
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			newArray[i*n+j] = mat2[i][j];
		}
	}
	*/
	
	return newArray;
}