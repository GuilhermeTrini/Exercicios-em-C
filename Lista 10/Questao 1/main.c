#include <stdio.h>
#include <stdlib.h>
#include "pilhaenc.c"

/*
1
2
5
2
3
5
8
1
2
7
2
4
5
8
1
2
9
2
8
5

*/
int main()
{
    int option = -1, count = 2;
    Pilha *pilha1, *pilha2, *pilha3;
    pilha1 = (Pilha*) malloc(sizeof(Pilha));
    pilha2 = (Pilha*) malloc(sizeof(Pilha));
    pilha3 = (Pilha*) malloc(sizeof(Pilha));
    if (pilha1 == NULL || pilha2 == NULL || pilha3 == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    Pilha *pilhaAtual = pilha1;
    while (option != 0){
        printf("\nEditor de Pilha v1.0\n==================\n1 -> Inicializar\n2 -> Empilhar\n3 -> Desempilhar\n4 -> Elemento do topo\n5 -> Imprimir pilha\n6 -> Inverter elementos da pilha\n7 -> Esvaziar a pilha\n8 -> Mudar de pilha\n");
        printf("Digite sua opcao: ");
        scanf("%d", &option);
        printf("\n");
        switch (option){
            case 1:
                inicializa(pilhaAtual);
                printf("Pilha inicializada!\n");
                break;
            case 2:
                {
                int dado;
                printf("Digite o dado: ");
                scanf("%d", &dado);
                if (empilhar(pilhaAtual, dado) == 1){
                    printf("Empilhamento concluido com sucesso!\n");
                }
                }
                break;
            case 3:
                int valor = desempilhar(pilhaAtual);
                if (valor == -1){
                    break;
                }
                printf("Desempilhamento concluido com sucesso!\n");
                printf("Valor desempilhado: %d\n", valor);
                break;
            case 4:
                topo(pilhaAtual);
                break;
            case 5:
                exibirPilha(pilhaAtual);
                break;
            case 6:
                invertePilha(pilhaAtual);
                break;
            case 7:
                esvaziarPilha(pilhaAtual);
                break;
            case 8:
                if (count % 3 == 1){
                    pilhaAtual = pilha1;
                    printf("Pilha mudada! Voce esta manipulando a Pilha 1 agora!\n");
                }
                else if (count % 3 == 2){
                    pilhaAtual = pilha2;
                    printf("Pilha mudada! Voce esta manipulando a Pilha 2 agora!\n");
                }
                else{
                    pilhaAtual = pilha3;
                    printf("Pilha mudada! Voce esta manipulando a Pilha 3 agora!\n");
                }
                count++;
                break;
        }
    }
}
