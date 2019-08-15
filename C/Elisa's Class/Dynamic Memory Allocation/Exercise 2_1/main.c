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

//(a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
struct ALUNO* studentArray(int n);

//(b) Preencher o vetor de alunos.
void fillStudentArray(int n, struct ALUNO* V);

//(c) Imprimir o vetor de alunos.
void printStudentArray(int n, struct ALUNO* V);

//(d) Preencher o registro de um aluno.
void fillStudentRecord(int n, struct ALUNO* V);
	
//(e) Imprimir o registro de um aluno.	
void printStudentRecord(int n, struct ALUNO* V);

int main(){
	int n;
	do{
		printf("How many students do you want to register? ");
		scanf("%d", &n);
	}while(!(n>0));
	
	//(a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
	struct ALUNO *V;
	V = studentArray(n);
	
	//(b) Preencher o vetor de alunos.
	fillStudentArray(n, V);
	
	//(c) Imprimir o vetor de alunos.
	printStudentArray(n, V);
	
	//(d) Preencher o registro de um aluno.
	fillStudentRecord(n, V);
	
	//(e) Imprimir o registro de um aluno.
	printStudentRecord(n, V);
	
	//Deallocate array
	free(V);
	
	return 0;
}

//(a) Alocar memória dinamicamente para um vetor do tipo ALUNO.
struct ALUNO* studentArray(int n){
	struct ALUNO* V;
	V = (struct ALUNO*)malloc(n*sizeof(struct ALUNO));
	
	if(V == NULL){
		printf("Insufficient memory!");
		return NULL;
	}
	
	return V;
}

//(b) Preencher o vetor de alunos.
void fillStudentArray(int n, struct ALUNO* V){
	printf("What are the student names?\n");
	for(int i=0; i<n; i++){
		printf("Student [%d] - ", i+1);
		scanf(" %[^\n]", &(V+i)->nome);
	}
		
}

//(c) Imprimir o vetor de alunos.
void printStudentArray(int n, struct ALUNO* V){
	for(int i=0; i<n; i++){
		printf("The student [%d] is: %s\n", i+1, (V+i)->nome);	
	}
	
	
}

//(d) Preencher o registro de um aluno.
void fillStudentRecord(int n, struct ALUNO* V){
	printf("Registering the students record!\n");
	for(int i=0; i<n; i++){
		printf("Student [%d]\n", i+1);
		printf("Name: %s\n", (V+i)->nome);
		
		do{
			printf("Registration number: ");
			scanf("%d", &(V+i)->matricula);	
		}while(!((V+i)->matricula >0));
		
		printf("When he or she was born?\n");
		do{
			printf("Day: ");
			scanf("%d", &(V+i)->dia_nasc);
		}while(!((V+i)->dia_nasc>=1 && (V+i)->dia_nasc <=31));
		
		do{
			printf("Month: ");
			scanf("%d", &(V+i)->mes_nasc);
		}while(!((V+i)->mes_nasc>=1 && (V+i)->mes_nasc<=12));
		
		do{
			printf("Year: ");
			scanf("%d", &(V+i)->ano_nasc);
		}while(!((V+i)->ano_nasc>=1940 && (V+i)->ano_nasc<=2017));
		
		do{
			printf("What grade did he or she get on the test? ");
			scanf("%f", &(V+i)->nota);
		}while(!((V+i)->nota>=0 && (V+i)->nota <=10));
		
	}
	
}
	
//(e) Imprimir o registro de um aluno.	
void printStudentRecord(int n, struct ALUNO* V){
	printf("The approved students are: \n");
	for(int i=0; i<n; i++){
		if((V+i)->nota>=6){
			printf("Student [%d]\n", i+1);
			
			printf("Name: %s \n", (V+i)->nome);
		
			printf("Registration number: %d \n", (V+i)->matricula);
		
			printf("Date of birth: %d/%d/%d \n", (V+i)->dia_nasc, (V+i)->mes_nasc, (V+i)->ano_nasc);
		
			printf("Grade: %.2f \n", (V+i)->nota);
		}	
	}
	
}

	