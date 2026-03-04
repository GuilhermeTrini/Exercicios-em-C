#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaE.h"

void criar(Lista *l){
    l->inicio = NULL;
}
int vazia(Lista *l){
    return (l->inicio == NULL);
}
int tamanho(Lista *l){
    int cont = 0;
    No *aux = l->inicio;

    while(aux!=NULL){
        aux=aux->prox;
        cont++;
    }
    return cont;
}
int inserir(Lista *l, char dado[MAX]){
    No *novo = (No *) malloc(sizeof(No));
    strcpy(novo->dado, dado);
    novo->prox = NULL;

    if (vazia(l)){
        l->inicio = novo;
        return 1;
    }

    No *aux = l->inicio;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox = novo;
    return 1;
}

void exibir(Lista *l){
    No *aux = l->inicio;
    printf("[ ");
    while(aux!=NULL){
        printf("- %s ", aux->dado);
        aux=aux->prox;
    }
    printf("- ]\n");
}

int remover(Lista *l, char dado[MAX]){
    if (l == NULL)
        return 0;
    int pos;
    pos = posicao(l, dado) - 1;
    if (pos == -2){
        printf("O nome nao esta na lista\n");
        return 0;
    }
    No *aux = l->inicio;
    No *temp;
    if (pos == 0){
        l->inicio = aux->prox;
        free(aux);
        return 1;
    }
    for(int i = 1; i < pos; i++){
        aux = aux->prox;
    }
    temp = aux->prox;
    aux->prox = temp->prox;
    free(temp);

    return 1;
}

int posicao(Lista *l, char dado[MAX]){
    int pos = 1;
    if (l == NULL)
        return 0;
    No *aux = l->inicio;
    while (aux != NULL){
        if (strcmp(aux->dado, dado) == 0){
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1;
}

int esvaziar(Lista *l){
    int confirm;
    printf("Por favor, confirme o esvaziamento da lista (1 - sim, 2 - nao): ");
    scanf("%d", &confirm);

    if (vazia(l))
        printf("A lista ja esta vazia\n");
        return 0;
    if (confirm == 1){
        No* aux = l->inicio;
        No* temp;
        while (aux != NULL){
            temp = aux->prox;
            free(aux);
            aux = temp;
        }
        l->inicio = NULL;
        return 0;
    }
    return -1;
}
char* obterElemento(Lista *l, int pos){
    if (vazia(l))
        return 0;

    if (tamanho(l) < pos || pos <= 0) {
        return NULL;
    }
    No *aux = l->inicio;
    for (int i = 1; i < pos; i++){
        aux = aux->prox;
    }
    return aux->dado;

}

int inserirNaPosicao(Lista *l, char dado[MAX], int pos){
    if (vazia(l))
        return 0;
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->dado, dado);
    novo->prox = NULL;
    if (pos == 1){
        No *aux = l->inicio;
        l->inicio = novo;
        novo->prox = aux;
        return 1;
    }
    if (pos < 1 || pos > tamanho(l) + 1){
        printf("Posicao invalida\n\n");
        return 0;
    }
    No *aux = l->inicio;
    for (int i = 1; i < pos - 1; i++){
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;\
    return 1;
}
