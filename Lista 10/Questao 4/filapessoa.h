#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILAPESSOA_H_INCLUDED
#define FILAPESSOA_H_INCLUDED

typedef struct pessoa{
    char nome[20];
    int idade;
    int cpf;
    int gestante;
}Pessoa;

typedef struct no{
    Pessoa pessoa;
    struct no *prox;
}No;

typedef struct filapessoa{
    No *inicio;
    No *fim;
}Fila;

void cria(Fila *f);
void exibir(Fila *f);
int enfileirar(Fila *f, Pessoa pessoa);
int desenfileirar(Fila *f, char nome[20]);
int tamanho(Fila *f);


#endif // FILAPESSOA_H_INCLUDED
