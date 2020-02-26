#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main(){
    
    double a, b;
    Ponto *p, *q, *sum, *sub, *mul, *div;
    
    // lê valores a e b do numero p
    printf("Enter a and b where a + bi is the first complex number.");
    printf("\na = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    
    // criar o número complexo p
    p = pontoCriar(a, b);
    
    // lê valores a e b do numero q 
    printf("Enter a and b where a + bi is the first complex number.");
    printf("\na = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);

    // criar o número complexo p
    q = pontoCriar(a, b);
    
    // soma dois numeros complexos
	sum = add(p, q);
    printf("The sum is: ");
    print(sum);

    sub = subtraction(p, q);
    printf("The subtraction is: ");
    print(sub);

    mul = multiplication(p, q);
    printf("The multiplication is: ");
    print(mul);

    div = division(p, q);
    printf("The division is: ");
    print(div);

    //(b) Função para liberar um número complexo previamente criado.
    freeComplexNumber(p);
    freeComplexNumber(q);
  
	return 0;
}