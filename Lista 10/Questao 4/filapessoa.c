#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filapessoa.h"

void cria(Fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

void exibir(Fila *f)
{
    No *aux = f->inicio;
    while (aux != NULL){
        printf("%s - ", aux->pessoa.nome);
        aux = aux->prox;
    }
    printf("\n");
}

int enfileirar(Fila *f, Pessoa pessoa)
{
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo->pessoa = pessoa;
    novo->prox = NULL;

    if (f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
        return 1;
    }

    No *aux = f->inicio;
    No *ant = NULL;

    if (novo->pessoa.gestante){
        while (aux != NULL && aux->pessoa.gestante){
            ant = aux;
            aux = aux->prox;
        }
        if (ant == NULL){
            novo->prox = f->inicio;
            f->inicio = novo;
        }else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }
        return 1;

    }else if (novo->pessoa.idade >= 65){
        No *aux = f->inicio;
        No *ant = NULL;
        while (aux != NULL && (aux->pessoa.idade >= 65 || aux->pessoa.gestante)){
            ant = aux;
            aux = aux->prox;
        }
        if (aux == NULL){
            novo->prox = f->inicio;
            f->inicio = novo;
        }
        else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }
        return 1;
    }
    f->fim->prox = novo;
    f->fim = novo;
    return 1;
}

int desenfileirar(Fila *f, char nome[20])
{
    if (f->inicio == NULL){
        printf("Fila vazia! Nao foi possivel sair da fila!\n");
        return 0;
    }
    strcpy(nome, f->inicio->pessoa.nome);
    No* temp = f->inicio;
    f->inicio = temp->prox;
    free(temp);
    return 1;
}

void exibir1(Fila *f)
{
    if (f->inicio == NULL){
        printf("Fila vazia! Nao foi possivel exibir\n");
        return;
    }
    Pessoa aux = f->inicio->pessoa;
    printf("O primeiro da fila:\nNome: %s\nIdade: %d\nCPF: %d\n", aux.nome, aux.idade, aux.cpf);
    if (aux.gestante){
        printf("Eh gestante: Sim\n");
    }else{
        printf("Eh gestante: Nao\n");
    }
}

int tamanho(Fila *f)
{
    int count = 0;
    No *aux = f->inicio;
    while (aux != NULL){
        count++;
        aux = aux->prox;
    }
    return count;
}
