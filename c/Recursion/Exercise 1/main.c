/*
Escreva uma programa que calcule e imprima o fatorial de n.
Implemente:
I Uma função recursiva: int fatRecursiva(int n).
I Uma função iterativa (utilizando laços): int fatIterativa(int n).
Escreva um programa que calcule e imprima o n-ésimo número na
sequência de Fibonacci. Implemente:
I Uma função recursiva: int fibRecursiva(int n).
I Uma função iterativa (utilizando laços): int fibIterativa(int n).
*/
#include <stdio.h>
#include <stdlib.h>

int recursiveFactorial(int n);

int iterativeFactorial(int n);

int recursiveFibonacci(int n);

int iterativeFibonacci(int n);

int main(){
	int n, factorial, fibonacci;
	printf("Enter the value: ");
	scanf("%d", &n);
	
	factorial = recursiveFactorial(n);
	printf("The factorial of number [%d] by using recursion is %d.\n\n", n, factorial);
	
	factorial = iterativeFactorial(n);
	printf("The factorial of number [%d] by using iterative method is %d.\n\n", n, factorial);

	fibonacci = recursiveFibonacci(n);
	printf("The %dth Fibonacci number by using recursion is: %d.\n\n", n, fibonacci); 
	
	fibonacci = iterativeFibonacci(n);
	printf("The %dth Fibonacci number by using iterative method is: %d.\n\n", n, fibonacci); 

	//Extra
	printf("Print all the n Fibonacci's numbers: ");
	for(int i=0; i<n; i++){
		printf("%d ", recursiveFibonacci(i));
	}
	return 0;
}

int recursiveFactorial(int n){
	if(n==0){
		return 1;
	}else{
		return n* recursiveFactorial(n-1);
	}
	
}

int iterativeFactorial(int n){
	int factorial = 1;
	
	for(int i=n; i>0; i--){
		factorial *= i;
	}
	
	return factorial;
}

int recursiveFibonacci(int n){
	if(n==0){
		return 0;
	}else if(n==1){
		return 1;
	}else{
		return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
	}
	
}

int iterativeFibonacci(int n){
	int t1 = 0, t2 = 1, nextTerm;
    
    for (int i = 0; i < n; i++){
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
	return t1;
}