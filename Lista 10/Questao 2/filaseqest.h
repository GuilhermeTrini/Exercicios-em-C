#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#ifndef FILASEQEST_H_INCLUDED
#define FILASEQEST_H_INCLUDED

typedef struct fila {
    char nome[MAX][MAX];
    int inicio;
    int fim;
    int tamanho;
}Fila;

void cria(Fila *f);
int enfileirar(Fila *f, char nome[MAX]);
int desenfileirar(Fila *f, char nome[MAX]);
void exibirFila(Fila *f);

#endif // FILASEQEST_H_INCLUDED
