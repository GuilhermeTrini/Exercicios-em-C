#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listaE.c"


int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int option = 0;
    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    criar(lista);

    while (option != 8){
        printf("Editor de Lista ------------------------------------\n1 - Exibir Lista\n2 - Inserir\n3 - Remover\n4 - Exibir posição\n5 - Esvaziar Lista\n6 - Obter nome na posicao\n7 - Inserir nome na posicao\n8 - Sair\nDigite a opção: ");
        scanf("%d", &option);
        printf("\n");
        switch (option){
        case 1:
            printf("\nTamanho da lista: %d\n", tamanho(lista));
            exibir(lista);
            printf("\n");
            break;
        case 2:
            {
            char nome[MAX];
            printf("Digite o nome a ser lido: ");
            scanf(" %[^\n]", nome);
            printf("\n");
            inserir(lista, nome);
            }
            break;
        case 3:
            {
            char nome[MAX];
            printf("Digite o elemento a ser removido: ");
            scanf(" %[^\n]", nome);
            remover(lista, nome);
            }
            break;
        case 4:
            {
            char nome[MAX];
            int pos = posicao(lista,nome);
            printf("Digite o elemento a ser exibido a posicao: ");
            scanf(" %[^\n]", nome);
            if (pos == -1){
                printf("O nome nao esta na lista\n\n");
                break;
            }else{
                printf("Posicao da string na lista: %d\n\n");
            }
            }
            break;
        case 5:
            esvaziar(lista);
            break;
        case 6:
            {
            int pos;

            printf("Digite a posicao do elemento: ");
            scanf("%d", &pos);
            char *dado = obterElemento(lista, pos);

            if (dado == NULL){
                printf("\nPosicao invalida\n\n");
                break;
            }
            printf("O elemento da posicao %d: %s\n\n", pos, dado);
            }
            break;
        case 7:
            {
            int pos;
            char nome [MAX];
            printf("Digite o nome deseja inserir: ");
            scanf(" %[^\n]", nome);
            printf("Digite a posicao que deseja inserir: ");
            scanf("%d", &pos);
            inserirNaPosicao(lista, nome, pos);
            }
            break;
        }
    }
    free (lista);

    return 0;
}
