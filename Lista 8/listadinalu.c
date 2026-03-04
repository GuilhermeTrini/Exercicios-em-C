#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadinalu.h"

void cria(ListaAluno *la)
{
    la->inicio = NULL;
}

int tamanho(ListaAluno *la)
{
    int count = 0;
    No *aux = la->inicio;
    while(aux != NULL){
        aux = aux->prox;
        count++;
    }
    return count;
}

int vazia(ListaAluno *la)
{
    return(la->inicio == NULL);
}

int buscaPosMat(ListaAluno *la, int mat, int *pos)
{
    *pos = 1;
    No *aux = la->inicio;
    while(aux != NULL){
        if (aux->dado.matricula == mat){
            return 1;
        }
        (*pos)++;
        aux = aux->prox;
    }
    return -1;
}

int buscaAlunoPos(ListaAluno *la, int pos, Aluno *al)
{
    No *aux = la->inicio;

    if (pos > tamanho(la) || pos < 1){
        printf("Posicao invalida\n");
        return -1;
    }

    for (int i = 1; i < pos; i++){
        aux = aux->prox;
    }

    strcpy(al->nome, aux->dado.nome);
    return 1;
}

int insereFinal(ListaAluno *la, Aluno al)
{
    No *novo = (No*)malloc(sizeof(No));
    atribuiDados(novo, al);
    if (la->inicio == NULL){
        la->inicio = novo;
        return 1;
    }
    No *aux = la->inicio;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;

    return 1;
}

int removeAlunoMat(ListaAluno *la, int mat)
{
    if (vazia(la)){
        printf("A lista esta vazia, remocao invalida\n");
        return -1;
    }
    int pos;
    buscaPosMat(la, mat, &pos);
    if (pos == 1){
        No* temp = la->inicio;
        la->inicio = temp->prox;
        free(temp);
        return 1;
    }
    if (pos == -1){
        printf("A matricula nao esta na lista");
        return -1;
    }
    No* aux = la->inicio;
    for (int i = 1; i < pos - 1; i++){
        aux = aux->prox;
    }
    No* temp = aux->prox;
    aux->prox = temp->prox;
    free(temp);
    return 1;
}

void exibirAlunos(ListaAluno *la)
{
    No *aux = la->inicio;
    while (aux != NULL){
        printf("------------\n");
        printf("Matricula: %d\nNome: %s\nNota 1: %.2f\nNota 2: %.2f\n", aux->dado.matricula, aux->dado.nome, aux->dado.nota1, aux->dado.nota2);
        aux = aux->prox;
    }
}

void atribuiDados(No *novo, Aluno al)
{
    novo->dado.matricula = al.matricula;
    strcpy(novo->dado.nome, al.nome);
    novo->dado.nota1 = al.nota1;
    novo->dado.nota2 = al.nota2;
    novo->prox = NULL;
}

int insereNaPosicao(ListaAluno *la, Aluno al, int pos)
{
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
    int tam = tamanho(la);
    atribuiDados(novo, al);
    if (vazia(la)){
        la->inicio = novo;
        return 1;
    }
    if (pos <= 1){
        No* aux = la->inicio;
        la->inicio = novo;
        novo->prox = aux;
        return 1;
    }
    if (pos > tam){
        No* aux = la->inicio;
        for(int i = 1; i < tam; i++){
            aux = aux->prox;
        }
        aux->prox = novo;
        return 1;
    }
    No* aux = la->inicio;
    for (int i = 1; i < pos - 1; i++){
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    return 1;
}

int insereOrdenado(ListaAluno *la, Aluno al)
{
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
    atribuiDados(novo, al);
    No *aux = la->inicio;
    if (aux == NULL){
        la->inicio = novo;
        return 1;
    }
    if (novo->dado.matricula < aux->dado.matricula){
        la->inicio = novo;
        novo->prox = aux;
        return 1;
    }
    while (aux->prox != NULL && novo->dado.matricula > aux->prox->dado.matricula){
        aux = aux->prox;
        }
    novo->prox = aux->prox;
    aux->prox = novo;

    return -1;
}

int removeNaPosicao(ListaAluno *la, int pos)
{
    if (vazia(la)){
        printf("A lista ja esta vazia");
        return -1;
    }
    if (pos == 1){
        No* temp = la->inicio;
        la->inicio = la->inicio->prox;
        free(temp);
        return 1;
    }
    No* aux = la->inicio;
    for (int i = 1; i < pos - 1; i++){
        aux = aux->prox;
    }
    No* temp = aux->prox;
    aux->prox = temp->prox;
    free(temp);
    return 1;
}

void buscaAlunoNome(ListaAluno *la, char nome[30])
{
    if (vazia(la)){
        printf("Sem alunos na lista");
        return;
    }
    int count = 0;
    No* aux = la->inicio;
    while (aux != NULL){
        if (strcmp(aux->dado.nome, nome) == 0){
            printf("Matricula: %d\nNome: %s\nNota 1: %.2f\nNota 2: %.2f\n", aux->dado.matricula, aux->dado.nome, aux->dado.nota1, aux->dado.nota2);
            count++;
        }
        aux = aux->prox;
    }
    if (count == 0){
        printf("Aluno nao encontrado na lista");
    }
}

void buscaAlunoMatricula(ListaAluno *la, int mat)
{
    if (vazia(la)){
        printf("Sem alunos na lista");
        return;
    }
    int count = 0;
    No* aux = la->inicio;
    while (aux != NULL){
        if (aux->dado.matricula == mat){
            printf("\nMatricula: %d\nNome: %s\nNota 1: %.2f\nNota 2: %.2f\n", aux->dado.matricula, aux->dado.nome, aux->dado.nota1, aux->dado.nota2);
            count++;
        }
        aux = aux->prox;
    }
    if (count == 0){
        printf("Aluno nao encontrado na lista");
    }
}
