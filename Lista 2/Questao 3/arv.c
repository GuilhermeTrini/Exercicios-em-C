#include "arv.h"
#include <stdio.h>
#include <stdlib.h>

void criar(Arvore *a){
    a->raiz = NULL; }

// in-ordem
void exibir(NoArv *r){
  if (r!=NULL){
    exibir(r->esq);
    printf("%d ",r->dado);
    exibir(r->dir);
  }
}

void exibir_pares(NoArv *ra){
  if (ra!=NULL){
    exibir_pares(ra->esq);
    if (ra->dado % 2 == 0){
        printf("%d ",ra->dado);
    }
    exibir_pares(ra->dir);
  }
}


NoArv *inserir(NoArv *raiz, int dado) {
  if (raiz == NULL) {
    NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
    novo->dado = dado;
    novo->esq = novo->dir = NULL;
    raiz = novo;
  } else {
    if (dado < raiz->dado) {
      raiz->esq = inserir(raiz->esq, dado);
    } else {
      raiz->dir = inserir(raiz->dir, dado);
    }
  }
  return raiz;
}

void insere(Arvore *a, int dado)
{ a->raiz = inserir(a->raiz, dado); }

NoArv *busca(NoArv *raiz, int dado) {
    if(raiz == NULL || raiz->dado == dado)
        return raiz;
    else if (dado < raiz->dado)
        return busca(raiz->esq, dado);
    else
        return busca(raiz->dir, dado);
}

NoArv* remover(NoArv* raiz, int dado) {
    if(raiz == NULL) return NULL;
    else if (dado < raiz->dado) raiz->esq = remover(raiz->esq, dado);
    else if (dado > raiz->dado) raiz->dir = remover(raiz->dir, dado);
    else {
        //remoção de nó sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
        free(raiz);
        return NULL;
        }
        //único filho à esquerda
        else if (raiz->dir == NULL) {
            NoArv *t = raiz;
            raiz = raiz->esq;
            free(t);
        }
        //único filho à direita
        else if (raiz->esq == NULL) {
            NoArv *t = raiz;
            raiz = raiz->dir;
            free(t);
        }
        //dois filhos
        else {
            NoArv* f = raiz->esq; //buscar nó mais à direita da sub-árvore à esquerda
            while(f->dir != NULL) f = f->dir;
            raiz->dado = f->dado;
            f->dado = dado;
            raiz->esq = remover(raiz->esq, dado);
        }
    }
    return raiz;
}
int contaFolhas(NoArv *ra)
{
    if (ra == NULL)
        return 0;

    if (ra->esq == NULL && ra->dir == NULL)
        return 1;

    return contaFolhas(ra->esq) + contaFolhas(ra->dir);
}
int folhas(Arvore *a){
    if (a == NULL || a->raiz == NULL){
        return 0;
    }
    NoArv *ra = a->raiz;
    contaFolhas(ra);
    int count = contaFolhas(ra);
    return count;
}
