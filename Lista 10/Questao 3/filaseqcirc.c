#include <stdio.h>
#include <stdlib.h>
#include "filaseqcirc.h"

void cria(Fila *f)
{
    f->inicio = 0;
    f->tamanho = 0;
    f->fim = -1;
}

int enfileirar(Fila *f, int dado)
{
    if (f->tamanho == MAX){
        printf("A fila esta cheia! Nao foi possivel fazer o enfileiramento.\n");
        return 0;
    }
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = dado;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, int *dado)
{
    if (f->tamanho == 0){
        printf("A fila esta vazia! Nao foi possivel desenfileirar.\n");
        return 0;
    }
    *dado = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

void exibir(Fila *f)
{
    int count = f->inicio;
    printf("Fila: \n");
    for (int i = 0; i < f->tamanho; i++){
        printf("%d\n", f->dados[count]);
        count = (count + 1) % MAX;
    }
}

