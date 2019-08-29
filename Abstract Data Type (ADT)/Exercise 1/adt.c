#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

struct complexNumber{
	double x;
	double y;
};

ComplexNumber *allocateMemory(){
	ComplexNumber *new = (ComplexNumber*)malloc(sizeof(ComplexNumber));
	if(new==NULL){
		printf("Insufficient memory");
	}
	
	return new;
}

//(a) Função para criar um número complexo, dados a e b.
ComplexNumber *createComplexNumber(ComplexNumber *n){
	printf("Enter a and b where a + bi is the first complex number.");
    printf("\na = ");
    scanf("%lf", &n->x);
    printf("b = ");
    scanf("%lf", &n->y);
	
	printf("The created complex number is: ");
	printf("a + bi = %.2lf + %.2lfi", n->x, n->y);

	return n;
}