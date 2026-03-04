#include <stdio.h>
#include <stdlib.h>
#include "listadinalu.c"

/*
Lista de nomes para teste de execucao do programa
Inserindo 4 alunos para teste das funcoes do programa:
Se der Crtl+c Ctrl+v, vai inserir todos esses alunos na lista durante a execucao do programa, para exibir aperte a tecla 7

Teste 1: Inserindo alunos e exibindo
(inserindo no final)
5
212
Jose
9.5
9.3
5
215
Marcos
9.3
8.7
(inserindo na posicao)
8
2
213
Carlos
7.9
8.5
(inserindo ordenado)
9
214
Giuseppe
9.8
8.2
7

Teste 2: Busca de dados
(exibe a posicao pela matricula)
3
215
(exibe o nome do aluno pela posicao)
4
2

Teste 3: Removendo alunos da lista
(removendo pela matricula)
6
213
7
(removendo pela posicao)
10
2
7

teste 5: Busca os dados do aluno pelo nome ou pela matricula
(pelo nome)
11
1
Jose
(pela matricula)
11
2
212

teste 4: Verificar se esta vazia e o tamanho
(se esta vazia)
1
(tamanho)
2
*/


int main()
{
    ListaAluno *listaA;
    listaA = (ListaAluno*) malloc(sizeof(listaA));
    if (listaA == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    cria(listaA);
    int option = 0;

    while (option != 12){
        printf("-----------------------");
        printf("\n");
        printf("Editor de Lista Encadeada\n1 - Verifica se a lista esta vazia\n2 - Exibe o tamanho da lista\n3 - Exibe a posicao do aluno pela matricula\n4 - Exibe o nome do aluno pela posicao do aluno\n5 - Insere aluno no final da lista\n6 - Remove aluno pela matricula\n7 - Exibe todos os aluno\n8 - Insere aluno na posicao\n9 - Insere aluno em ordem crescente de matricula\n10 - Remove aluno na posicao\n11 - Buscar aluno pela matricula ou pelo nome\n12 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &option);
        printf("\n");
        switch (option){
        case 1:
            if (vazia(listaA))
                printf("A lista esta vazia\n");
            else
                printf("A lista nao esta vazia\n");
            break;
        case 2:
            printf("Tamanho da lista: %d\n", tamanho(listaA));
            break;
        case 3:
            {
                int posicao, matricula;
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                buscaPosMat(listaA, matricula, &posicao);
                if (buscaPosMat(listaA, matricula, &posicao) == -1){
                    printf("Matricula nao esta na lista\n");
                    break;
                }
                printf("O aluno esta na posicao %d da lista\n", posicao);
            }
            break;
        case 4:
            {
                int posicao;
                Aluno aluno;
                printf("Digite a posicao do aluno na lista: ");
                scanf("%d", &posicao);
                if (buscaAlunoPos(listaA, posicao, &aluno) == -1)
                    break;
                printf("Nome do aluno: %s\n", aluno.nome);
            }
            break;
        case 5:
            {
                Aluno aluno;
                printf("Digite os dados do aluno\nMatricula: ");
                scanf("%d", &aluno.matricula);
                printf("Nome: ");
                scanf(" %[^\n]", aluno.nome);
                printf("Nota 1: ");
                scanf("%f", &aluno.nota1);
                printf("Nota 2: ");
                scanf("%f", &aluno.nota2);
                if (insereFinal(listaA, aluno) == 1){
                    printf("Insercao concluida com sucesso\n");
                }
            }
            break;
        case 6:
            {
                int matricula;
                printf("Digite a matricula do aluno que deseja remover: ");
                scanf("%d", &matricula);
                if (removeAlunoMat(listaA, matricula) == 1){
                    printf("Remocao concluida com sucesso\n");
                }
            }
            break;
        case 7:
            exibirAlunos(listaA);
            break;
        case 8:
            {
                Aluno aluno;
                int posicao;
                printf("Digite a posicao que deseja inserir o aluno: ");
                scanf("%d", &posicao);
                printf("Digite os dados do aluno\nMatricula: ");
                scanf("%d", &aluno.matricula);
                printf("Nome: ");
                scanf(" %[^\n]", aluno.nome);
                printf("Nota 1: ");
                scanf("%f", &aluno.nota1);
                printf("Nota 2: ");
                scanf("%f", &aluno.nota2);
                if (insereNaPosicao(listaA, aluno, posicao) == 1){
                    printf("Insercao concluida com sucesso\n");
                }
            }
            break;
        case 9:
            {
                Aluno aluno;
                printf("Digite os dados do aluno\nMatricula: ");
                scanf("%d", &aluno.matricula);
                printf("Nome: ");
                scanf(" %[^\n]", aluno.nome);
                printf("Nota 1: ");
                scanf("%f", &aluno.nota1);
                printf("Nota 2: ");
                scanf("%f", &aluno.nota2);
                if (insereOrdenado(listaA, aluno) == 1){
                    printf("Insercao concluida com sucesso\n");
                }
            }
            break;
        case 10:
            {
                int posicao;
                printf("Digite a posicao do aluno que deseja remover: ");
                scanf("%d", &posicao);
                if (removeNaPosicao(listaA, posicao) == 1){
                    printf("Remocao concluida com sucesso\n");
                }
            }
            break;
        case 11:
            {
                int escolha;
                printf("1 - Buscar pelo nome do aluno\n2 - Buscar pela matricula do aluno\nDigite sua opcao: ");
                scanf("%d", &escolha);
                if (escolha == 1){
                    char nome[30];
                    printf("Digite o nome do aluno: ");
                    scanf(" %[^\n]", nome);
                    buscaAlunoNome(listaA, nome);
                }
                else if (escolha == 2){
                    int matricula;
                    printf("Digite a matricula do aluno: ");
                    scanf("%d", &matricula);
                    buscaAlunoMatricula(listaA, matricula);
                }
                else{
                    printf("Opcao invalida");
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
