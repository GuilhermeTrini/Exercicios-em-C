#include <stdio.h>
#include <stdlib.h>

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct no{
    char car;
    struct no *prox;
}No;

typedef struct pilha{
    No *topo;
}Pilha;

void cria(Pilha *p);
int empilha(Pilha *p, char c);
char desempilha(Pilha *p);
int vazia(Pilha *p);


#endif // PILHA_H_INCLUDED
