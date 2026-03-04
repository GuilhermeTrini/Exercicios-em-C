#ifndef LISTADUEN_H_INCLUDED
#define LISTADUEN_H_INCLUDED

typedef struct trecho{
    int idTrecho;
    char direcao[10];
    float distancia;
} TipoTrecho;

typedef struct no {
    TipoTrecho trecho;
    struct no *ant;
    struct no *prox;
}No;

typedef struct lista {
    No *inicio;
    No *fim;
    int tamanho;
}ListaTrecho;

int inserirTrecho(ListaTrecho *lista, TipoTrecho trecho);
int removerTrecho (ListaTrecho *lista, int idTrecho);
int atualizaTrecho(ListaTrecho *lista, TipoTrecho trecho);
void exibirPercurso(ListaTrecho *lista);
int posTrecho(ListaTrecho *lista, int idTrecho);
void atribuiDados(No *novo, TipoTrecho trecho);
void criaPercurso(ListaTrecho *lista);
void filtrarTrecho(ListaTrecho *lista, int idTrecho);


#endif // LISTADUEN_H_INCLUDED
