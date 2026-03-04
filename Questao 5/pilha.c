#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void cria(Pilha *p)
{
    p->topo = NULL;
}

int empilha(Pilha *p, char c)
{
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    novo->car = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilha(Pilha *p)
{
    if (vazia(p)){
        return 0;
    }
    char c = p->topo->car;
    No *temp = p->topo;
    p->topo = temp->prox;
    free(temp);
    return c;
}

int vazia(Pilha *p)
{
    if (p->topo == NULL){
        return 1;
    }
    return 0;
}
