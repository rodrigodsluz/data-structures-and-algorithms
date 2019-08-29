/*
1. Implemente uma TAD para representar números complexos. Sabe-se que um número complexo
é representado por a + bi, onde a e b são números reais e i a unidade imaginária. O TAD deve
implementar as seguintes operações:
(a) Função para criar um número complexo, dados a e b.
(b) Função para liberar um número complexo previamente criado.
(c) Função para somar dois números complexos, retornando um novo número com o resultado
da operação. Sabe-se que
		(a + bi) + (c + di) = (a + c) + (b + d)i (1)
(d) Função para subtrair dois números complexos, retornando um novo número com o resul-
tado da operação. Sabe-se que
		(a + bi) 􀀀 (c + di) = (a 􀀀 c) + (b 􀀀 d)i (2)
(e) Função para multiplicar dois números complexos, retornando um novo número com o
resultado da operação. Sabe-se que
		(a + bi)(c + di) = (ac 􀀀 bd) + (bc + ad)i (3)
(f) Função para dividir dois números complexos, retornando um novo número com o resultado
da operação. Sabe-se que
		(a + bi)=(c + di) = ((ac + bd)=(c2 + d2)) + ((bc 􀀀 ad)=(c2 + d2))i (4)
Escreva uma função main que use números complexos para testar as funções implementadas.
(Sugestão: criar dois números complexos, executar todas as operações (+, -, *, /), imprimir
os resultados e liberar a memória.)
*/
#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

int main(){
	ComplexNumber *n = allocateMemory();
	
	ComplexNumber *create = createComplexNumber(n);
	
	 
	
	
	
	return 0;
}