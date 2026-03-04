#ifndef LISTAE_H_INCLUDED
#define LISTAE_H_INCLUDED

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2;
} Aluno;

typedef struct no{
    Aluno dado;
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
}ListaAluno;

// Cria a lista vazia
void cria(ListaAluno *la);
// Retorna o tamanho da lista
int tamanho(ListaAluno *la);
// Retorna se a lista está vazia
int vazia(ListaAluno *la);
//Pesquisa posição pela matricula (retorna a posição no parâmetro *pos)
int buscaPosMat(ListaAluno *la, int mat, int *pos);
// Pesquisa aluno pela pela posição (retorna o Aluno no parâmetro *al)
int buscaAlunoPos(ListaAluno *la, int pos, Aluno *al);
// Insere aluno no final da lista
int insereFinal(ListaAluno *la, Aluno al);
// Remove aluno da lista passando a matricula
int removeAlunoMat(ListaAluno *la, int mat);
// Exibe a Lista de alunos
void exibirAlunos(ListaAluno *la);
// Atribui dados em uma insercao de aluno
void atribuiDados(No *novo, Aluno al);
// Insere aluno na posicao indicada
int insereNaPosicao(ListaAluno *la, Aluno al, int pos);
// Insere aluno em ordem crescente da matricula
int insereOrdenado(ListaAluno *la, Aluno al);
// Remove aluno da posicao indicada
int removeNaPosicao(ListaAluno *la, int pos);
// Busca aluno pelo nome
void buscaAlunoNome(ListaAluno *la, char nome[30]);
// Busca aluno pela matricula
void buscaAlunoMatricula(ListaAluno *la, int mat);


#endif // LISTAE_H_INCLUDED
