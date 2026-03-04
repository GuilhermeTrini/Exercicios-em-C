#include <stdio.h>
#include <stdlib.h>
#ifndef PILHAENC_H_INCLUDED
#define PILHAENC_H_INCLUDED

typedef struct no{
    int dado;
    struct no *prox;
}No;

typedef struct pilha{
    No *topo;
}Pilha;

void inicializa(Pilha *p);
int empilhar(Pilha *p, int dado);
int desempilhar(Pilha *p);
void topo(Pilha *p);
void exibirPilha(Pilha *p);
void invertePilha(Pilha *p);

#endif // PILHAENC_H_INCLUDED
