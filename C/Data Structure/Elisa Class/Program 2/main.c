/*
2. Crie um registro (struct) ALUNO que contenha os seguintes campos:
(a) int matricula;
(b) char nome[50];
(c) int dia_nasc;
(d) int mes_nasc;
(e) int ano_nasc;
(f) float nota;
Escreva um programa que leia o número n de alunos a serem cadastrados. Em seguida, um
vetor V com n posições deve ser alocado dinamicamente usando uma função que retorna
um ponteiro do tipo ALUNO. O programa deve preencher o vetor V e imprimir o registro dos
alunos aprovados, isto é, com nota maior ou igual a 6,0. Para executar tais tarefas devem ser
criadas funções para:
(a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
(b) Preencher o vetor de alunos.
(c) Imprimir o vetor de alunos.
(d) Preencher o registro de um aluno.
(e) Imprimir o registro de um aluno.
*/

#include <stdio.h>
#include <stdlib.h>

struct aluno{
	int matricula;
	char nome[50];
	int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    float nota;	
};

int main(){
	
	
	return 0;
}

