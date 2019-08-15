/* Made by Leal */
#include <stdlib.h>
#include <stdio.h>

typedef struct Aluno{
    int matricula;
    char nome[50];
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    float nota;
}Aluno;

Aluno *alocarVetorAluno(int n){
    Aluno *a = (Aluno*) malloc(n * sizeof(Aluno));
    return a;
}


void preencheAluno(Aluno *a, int pos){
    printf("Matricula: ");
    scanf("%d",&a[pos].matricula);
    printf("Nome: ");
    scanf(" %s",a[pos].nome);
    printf("Dia de Nascimento: ");
    scanf("%d",&a[pos].dia_nasc);
    printf("Mes de Nascimento: ");
    scanf("%d",&a[pos].mes_nasc);
    printf("Ano de Nascimento: ");
    scanf("%d",&a[pos].ano_nasc);
    printf("Nota final: ");
    scanf("%f",&a[pos].nota);
}

void preencheVetor(Aluno *a, int n){
    for(int i=0;i<n;i++){
        preencheAluno(a,i);
    }
}

void imprimeAluno(Aluno *a, int pos){
    if(a[pos].nota >= 6){
        printf("----------------------Aluno %d APROVADO ----------------------\n", pos);
        printf("Matricula: %d\nNome: %s\nData de nascimento: %d/%d/%d\nNota: %.2f\n\n", a[pos].matricula, a[pos].nome, a[pos].dia_nasc, a[pos].mes_nasc, a[pos].ano_nasc, a[pos].nota);
    }
}

void imprimeVetor(Aluno *a, int n){
    for(int i=0;i<n;i++){
        imprimeAluno(a, i);
    }
}

int main(){
    int n;
    Aluno *aluno;
    
    printf("Digine o falor N de alunos a serem cadastrados: ");
    scanf("%d", &n);
    
    aluno = alocarVetorAluno(n);
    preencheVetor(aluno,n);
    imprimeVetor(aluno,n);
    
    
    free(aluno);
    return 0;
}
