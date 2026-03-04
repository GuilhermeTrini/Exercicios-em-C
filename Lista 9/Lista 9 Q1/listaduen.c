#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaduen.h"

void criaCarrinho(ListaProdutos *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}
int inserirProd(ListaProdutos *lista, Produto prod)
{
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro na alocacao de memoria\n\n");
        exit(1);
    }
    atribuiDados(novo, prod);
    if (lista->tamanho == 0){
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho++;
        return 1;
    }
    No *aux = lista->fim;
    aux->prox = novo;
    novo->ant = aux;
    lista->fim = novo;
    lista->tamanho++;
    return 1;
}

void atribuiDados(No *novo, Produto prod)
{
    strcpy(novo->prod.categoria, prod.categoria);
    strcpy(novo->prod.nome, prod.nome);
    novo->prod.quantidade = prod.quantidade;
    novo->prod.valor = prod.valor;
    novo->prox = NULL;
    novo->ant = NULL;
}

int removerProd(ListaProdutos *lista, char nome[20])
{
    if (lista->tamanho == 0){
        printf("Sem itens no carrinho\n");
        return -1;
    }
    int pos = posProd(lista, nome);
    if (pos == -1){
        printf("\nProduto nao encontrado no carrinho!\n");
        return -1;
    }
    No *temp = lista->inicio;
    for (int i = 1; i < pos; i++){
        temp = temp->prox;
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

int atualizaProd(ListaProdutos *lista, Produto prod)
{
    if (lista->tamanho == 0){
        printf("\nSem itens no carrinho\n");
        return -1;
    }
    int pos = posProd(lista, prod.nome);
    if (pos == -1){
        printf("\nProduto nao encontrado no carrinho!\n");
        return -1;
    }
    No *aux = lista->inicio;
    for (int i = 1; i < pos; i++){
        aux = aux->prox;
    }
    strcpy(aux->prod.categoria, prod.categoria);
    aux->prod.quantidade = prod.quantidade;
    aux->prod.valor = prod.valor;
    return 1;
}

void exibirCarrinho(ListaProdutos *lista)
{
    float soma = 0;
    No *aux = lista->inicio;
    printf("\nMeu carrinho: \n");
    while (aux != NULL){
        printf("\n- %s\n Categoria: %s\n Quantidade: %d\n Valor da unidade: R$ %.2f\n", aux->prod.nome, aux->prod.categoria, aux->prod.quantidade, aux->prod.valor);
        soma += (aux->prod.quantidade * aux->prod.valor);
        aux = aux->prox;
    }
    printf("\n- Valor Total: R$ %.2f\n\n", soma);
}

int posProd(ListaProdutos *lista, char nome[20])
{
    No *aux = lista->inicio;
    int pos = 1;
    while (aux != NULL){
        if (strcmp(aux->prod.nome, nome) == 0){
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1;
}

void filtrarProd(ListaProdutos *lista, char categoria[15])
{
    float soma = 0;
    No *aux = lista->inicio;
    printf("\nProdutos da categoria %s:\n", categoria);
    while (aux != NULL){
        if (strcmp(aux->prod.categoria, categoria) == 0){
            soma += aux->prod.quantidade * aux->prod.valor;
        }
        aux = aux->prox;
    }
    aux = lista->inicio;
    while (aux != NULL){
        if (strcmp(aux->prod.categoria, categoria) == 0){
            printf("\n- %s\n Categoria: %s\n Quantidade: %d\n Valor da unidade: R$ %.2f\n", aux->prod.nome, aux->prod.categoria, aux->prod.quantidade, aux->prod.valor);
        }
        aux = aux->prox;
    }
    printf("\nValor Total da Categoria: R$ %.2f\n\n", soma);
}
