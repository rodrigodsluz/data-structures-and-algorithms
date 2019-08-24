/*
4. A seguinte função calcula o maior divisor comum dos inteiros positivos m e n. Escreva uma
função recursiva equivalente.
1. int Euclides(int m, int n){
2. int r;
3. do{
4. 	r = m % n;
5. 	m = n;
6. 	n = r;
7. }while(r != 0);
8. return m;}
*/

#include <stdio.h>
#include <stdlib.h>

int recursiveMdc(int m, int n);

int main(){
	int a, b;
	printf("Enter two numbers:\n");
	scanf("%d %d", &a, &b);
	
	int mdc = recursiveMdc(a, b);
	
	printf("The MDC between %d and %d is: %d", a, b, mdc);
	
	return 0;
}

int recursiveMdc(int m, int n){
	if(n==0){
		return m;
	}else{
		return recursiveMdc(n, m%n);
	}
}