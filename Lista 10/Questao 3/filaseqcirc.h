#include <stdio.h>
#include <stdlib.h>
#define MAX 30

#ifndef FILASEQCIRC_H_INCLUDED
#define FILASEQCIRC_H_INCLUDED

typedef struct fila{
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
}Fila;

void exibir(Fila *f);
int enfileirar(Fila *f, int dado);
int desenfileirar(Fila *f, int *dado);
void exibir(Fila *f);

#endif // FILASEQCIRC_H_INCLUDED
