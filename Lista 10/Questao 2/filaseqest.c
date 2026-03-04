#include <stdio.h>
#include <stdlib.h>
#include "filaseqest.h"

void cria(Fila *f)
{
    f->inicio = 0;
    f->tamanho = 0;
    f->fim = -1;
}

int enfileirar(Fila *f, char nome[MAX])
{
    if (f->tamanho == MAX){
        printf("Fila cheia! Nao foi possivel enfileirar!\n");
        return 0;
    }
    f->fim++;
    strcpy(f->nome[f->fim], nome);
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, char nome[MAX])
{
    if (f->tamanho == 0){
        printf("Lista vazia, nao foi possivel desenfileirar\n");
        return 0;
    }
    strcpy(nome, f->nome[f->inicio]);
    f->inicio++;
    f->tamanho--;
    return 1;
}

void exibirFila(Fila *f)
{
    if (f->tamanho == 0){
        printf("Fila vazia.\n");
        return;
    }

    for (int i = f->inicio; i <= f->fim; i++){
        printf("%s\n", f->nome[i]);
    }
}
