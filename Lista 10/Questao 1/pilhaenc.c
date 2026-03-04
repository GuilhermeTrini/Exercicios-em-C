#include <stdio.h>
#include <stdlib.h>
#include "pilhaenc.h"

void inicializa(Pilha *p)
{
    p->topo = NULL;
}

int empilhar(Pilha *p, int dado)
{
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return 1;
}

int desempilhar(Pilha *p)
{
    if (p->topo == NULL){
        printf("A pilha esta vazia\n");
        return -1;
    }
    int dado = p->topo->dado;
    No *temp = p->topo;
    p->topo = temp->prox;
    free(temp);
    return dado;
}

void topo(Pilha *p)
{
    if (p->topo == NULL){
        printf("Pilha vazia, sem valores a exibir\n");
        return;
    }
    printf("Valor do topo: %d\n", p->topo->dado);
}

void exibirPilha(Pilha *p)
{
    if (p->topo == NULL){
        printf("Pilha vazia, sem valores a exibir\n");
        return;
    }
    No *aux = p->topo;
    printf("Valores da pilha:\n");
    while (aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
}

void invertePilha(Pilha *p)
{
    if (p->topo == NULL){
        printf("Pilha vazia, sem valores a inverter\n");
        return;
    }
    int dado;
    Pilha aux, temp;
    temp.topo = NULL;
    aux.topo = NULL;
    while (p->topo != NULL){
       dado = desempilhar(p);
       empilhar(&aux, dado);
    }
    while (aux.topo != NULL){
        dado = desempilhar(&aux);
        empilhar(&temp, dado);
    }
    while (temp.topo != NULL){
        dado = desempilhar(&temp);
        empilhar(p, dado);
    }
    printf("Pilha invertida com sucesso!\n");
}

void esvaziarPilha(Pilha *p)
{
    if (p->topo == NULL){
        printf("Pilha ja esta vazia!\n");
        return;
    }
    No *temp;
    while (p->topo!= NULL){
        temp = p->topo->prox;
        free(p->topo);
        p->topo = temp;
    }
    printf("Pilha esvaziada com sucesso!\n");
}
