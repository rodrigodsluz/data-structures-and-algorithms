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

struct ALUNO{
	int matricula;
	char nome[50];
	int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    float nota;	
};

struct ALUNO* studentArray(int n);

void fillStudentArray(int n, struct ALUNO* V);

void printStudentArray(int n, struct ALUNO* V);

int main(){
	int n;
	printf("How many students do you want to register? ");
	scanf("%d", &n);
	
	struct ALUNO *V;
	V = studentArray(n);
	
	fillStudentArray(n, V);
	
	printf("The student record is:\n");
	printStudentArray(n, V);
	
	return 0;
}

struct ALUNO* studentArray(int n){
	struct ALUNO* V;
	V = (struct ALUNO*)malloc(n*sizeof(struct ALUNO));
	
	if(V == NULL){
		printf("Insufficient memory!");
		return NULL;
	}
	
	return V;
}

void fillStudentArray(int n, struct ALUNO* V){
	
	for(int i=0; i<n; i++){
		printf("What is your registration number? ");
		scanf("%d", &(V+i)->matricula);	
		printf("What's your name? ");
		scanf(" %[^\n]", &(V+i)->nome);
		printf("When you were born?\n");
		printf("Day: ");
		scanf("%d", &(V+i)->dia_nasc);
		printf("Month: ");
		scanf("%d", &(V+i)->mes_nasc);
		printf("Year: ");
		scanf("%d", &(V+i)->ano_nasc);
		printf("What grade did you get on the test? ");
		scanf("%f", &(V+i)->nota);
		
	}
}

void printStudentArray(int n, struct ALUNO* V){
	
	for(int i=0; i<n; i++){
		printf("Registration number: %d \n", (V+i)->matricula);
	
		printf("Name: %s \n", (V+i)->nome);
		
		printf("Date of birth: %d/%d/%d \n", (V+i)->dia_nasc, (V+i)->mes_nasc, (V+i)->ano_nasc);
		
		printf("Grade: %.2f \n", (V+i)->nota);
		
	}
}



	