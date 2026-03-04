#ifndef LISTA_H
#define MAX 30
#define LISTA_H

typedef struct no{
    char dado[MAX];
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
}Lista;

void criar(Lista *l);
int vazia(Lista *l);
int tamanho(Lista *l);
int inserir(Lista *l, char nome[MAX]);
void exibir(Lista *l);
int buscarDado(Lista *l, char dado[MAX]);
int remover(Lista *l, char dado[MAX]);
int posicao(Lista *l, char dado[MAX]);
int esvaziar(Lista *l);
char* obterElemento(Lista *l, int pos);
int inserirNaPosicao(Lista *l, char dado[MAX], int posicao);



#endif // LISTA_H
