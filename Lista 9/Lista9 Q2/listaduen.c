#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaduen.h"

void criaPercurso(ListaTrecho *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
int inserirTrecho(ListaTrecho *lista, TipoTrecho trecho)
{
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro na alocacao de memoria\n\n");
        exit(1);
    }
    atribuiDados(novo, trecho);
    if (lista->tamanho == 0){
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho++;
        novo->trecho.idTrecho = 1;
        return 1;
    }
    No *aux = lista->fim;
    aux->prox = novo;
    novo->ant = aux;
    lista->fim = novo;
    lista->tamanho++;
    novo->trecho.idTrecho = novo->ant->trecho.idTrecho + 1;
    return 1;
}
int removerTrecho (ListaTrecho *lista, int idTrecho)
{
    if (lista->tamanho == 0){
        printf("Sem nenhum trecho no percurso\n");
        return -1;
    }
    int pos = posTrecho(lista, idTrecho);
    if (pos == -1){
        printf("\nTrecho nao encontrado no percurso\n");
        return -1;
    }
    No *temp = lista->inicio;
    for (int i = 1; i < pos; i++){
        temp = temp->prox;
    }
    No *aux = temp->prox;
    while(aux != NULL){
        aux->trecho.idTrecho--;
        aux = aux->prox;
    }
    if (temp == lista->inicio){
        lista->inicio = temp->prox;
        if (lista->inicio != NULL){
            lista->inicio->ant = NULL;
        }
        else{
            lista->fim = NULL;
        }
        free(temp);
        lista->tamanho--;
        return 1;
    }
    if (temp == lista->fim){
        lista->fim = temp->ant;
        lista->fim->prox = NULL;
        free (temp);
        lista->tamanho--;
        return 1;
    }
    temp->ant->prox = temp->prox;
    temp->prox->ant = temp->ant;
    free(temp);
    lista->tamanho--;
    return 1;
}

int atualizaTrecho(ListaTrecho *lista, TipoTrecho trecho)
{
    if (lista->tamanho == 0){
        printf("\nSem trecho no percurso\n");
        return -1;
    }
    int pos = posTrecho(lista, trecho.idTrecho);
    if (pos == -1){
        printf("\nTrecho nao encontrado no percurso!\n");
        return -1;
    }
    No *aux = lista->inicio;
    for (int i = 1; i < pos; i++){
        aux = aux->prox;
    }
    strcpy(aux->trecho.direcao, trecho.direcao);
    aux->trecho.distancia = trecho.distancia;
    return 1;
}

void atribuiDados(No *novo, TipoTrecho trecho)
{
    novo->trecho.idTrecho = trecho.idTrecho;
    strcpy(novo->trecho.direcao, trecho.direcao);
    novo->trecho.distancia = trecho.distancia;
    novo->prox = NULL;
    novo->ant = NULL;
}


void exibirPercurso(ListaTrecho *lista)
{
    float soma = 0;
    No *aux = lista->inicio;
    printf("\nPercurso:\n");
    while (aux != NULL){
        printf("\n-Id do Trecho: %d\n Direcao: %s\n Distancia: %.2f\n", aux->trecho.idTrecho, aux->trecho.direcao, aux->trecho.distancia);
        soma += (aux->trecho.distancia);
        aux = aux->prox;
    }
    printf("\n- Distancia total: %.2f metros\n\n", soma);
}

int posTrecho(ListaTrecho *lista, int idTrecho)
{
    No *aux = lista->inicio;
    int pos = 1;
    while (aux != NULL){
        if (aux->trecho.idTrecho == idTrecho){
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1;
}
void filtrarTrecho(ListaTrecho *lista, int idTrecho)
{
    float soma = 0;
    No *aux = lista->inicio;
    if (posTrecho(lista, idTrecho) == -1){
        printf("\nTrecho nao encontrado no percurso\n");
        return;
    }
    while (aux != NULL){
        if (aux->trecho.idTrecho == idTrecho){
            printf("\n-Id do Trecho: %d\n Direcao: %s\n Distancia: %.2f\n", aux->trecho.idTrecho, aux->trecho.direcao, aux->trecho.distancia);
            soma += aux->trecho.distancia;
        }
        aux = aux->prox;
    }
    printf("\n- Distancia total: %.2f metros\n\n", soma);
}
