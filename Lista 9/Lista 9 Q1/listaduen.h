#ifndef LISTADUEN_H_INCLUDED
#define LISTADUEN_H_INCLUDED

typedef struct produto {
    char nome[20];
    char categoria[15];
    int quantidade;
    float valor;
}Produto;

typedef struct no {
    Produto prod;
    struct no *ant;
    struct no *prox;
}No;
typedef struct lista {
    No *inicio;
    No *fim;
    int tamanho;
}ListaProdutos;

int inserirProd(ListaProdutos *lista, Produto prod);
void atribuiDados(No *novo, Produto prod);
void criaCarrinho(ListaProdutos *lista);
int removerProd(ListaProdutos *lista, char nome[20]);
int atualizaProd(ListaProdutos *lista, Produto prod);
void exibirCarrinho(ListaProdutos *lista);
int posProd(ListaProdutos *lista, char nome[20]);
void filtrarProd(ListaProdutos *lista, char categoria[15]);

#endif // LISTADUEN_H_INCLUDED
