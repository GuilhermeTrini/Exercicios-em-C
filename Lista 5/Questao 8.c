#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char nome[31];
    char cpf[12];
    int idade;
    int qntDisciplinas;
    float *notas;
}Aluno;

Aluno* novoAluno(char nome[], char cpf[], int idade, int qntDisciplinas)
{
    Aluno *aluno;
    aluno = (Aluno*) malloc (sizeof(Aluno));
    if (aluno == NULL){
        printf("Erro na alocacao de memoria");
        free(aluno);
        exit(1);
    }
    strcpy(aluno->nome, nome);
    strcpy(aluno->cpf, cpf);
    aluno->idade = idade;
    aluno->qntDisciplinas = qntDisciplinas;

    aluno->notas = (float*) malloc(qntDisciplinas * sizeof(float));
    if (aluno->notas == NULL){
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    for (int i = 0; i < qntDisciplinas; i++){
        aluno->notas[i] = 0.0;
    }
    return aluno;
}

void atribuiNota(Aluno *aluno, int indice, float nota)
{
    if ((indice >= 0 && indice < aluno->qntDisciplinas) && (nota <= 100 && nota >= 0)){
        aluno->notas[indice] = nota;
    }
}

float mediaGeral(Aluno *aluno)
{
    float soma = 0, media = 0;
    for (int i = 0; i < aluno->qntDisciplinas; i++){
        soma += aluno->notas[i];
    }
    media = soma/aluno->qntDisciplinas;
    return media;
}

void desalocar(Aluno *aluno)
{
    free(aluno);
}

int main()
{
    Aluno *aluno;
    char nome[31], cpf[12];
    int idade, qntDisciplinas, indice;
    float nota;

    printf("Nome: ");
    scanf(" %[^\n]", nome);
    printf("CPF: ");
    scanf(" %[^\n]", cpf);
    printf("Idade: ");
    scanf(" %d", &idade);
    printf("Quantidade de disciplinas: ");
    scanf(" %d", &qntDisciplinas);

    aluno = novoAluno(nome, cpf, idade, qntDisciplinas);


    for (int i = 0; i < qntDisciplinas; i++){
        printf("Indice do array de notas (0 a %d): ", qntDisciplinas - 1);
        scanf(" %d", &indice);
        printf("Nota: ");
        scanf("%f", &nota);
        atribuiNota(aluno, indice, nota);
    }
    printf("A media das notas do aluno: %.2f", mediaGeral(aluno));

    desalocar(aluno);

    return 0;
}
