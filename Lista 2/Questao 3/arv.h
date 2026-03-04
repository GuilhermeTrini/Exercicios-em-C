typedef struct noarv{
    struct noarv *esq;
    struct noarv *dir;
    int dado;
}NoArv;

typedef struct arvore {
    NoArv *raiz;
}Arvore;

void criar(Arvore *a);
void exibir(NoArv *r);
NoArv *inserir(NoArv *raiz, int dado);
void insere(Arvore *a, int dado);
NoArv *busca(NoArv *raiz, int dado);
NoArv* remover(NoArv* raiz, int dado);
void exibir_pares(NoArv *ra);
int folhas(Arvore *a);
int contaFolhas(NoArv *ra);
