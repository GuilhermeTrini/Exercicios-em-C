#include <stdio.h>
#include <stdlib.h>
#include "filaseqcirc.c"

int main()
{
    Fila *fila;
    fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    cria(fila);
    int dado;
    int option = -1;
    while (option != 0){
        printf("----------- Editor de fila circular -----------\n1 - Enfileirar\n2 - Desenfileirar\n3 - Exibir fila\nDigite sua opcao: ");
        scanf("%d", &option);
        printf("\n");
        switch (option){
            case 1:
                printf("Digite o valor que deseja inserir na fila: ");
                scanf("%d", &dado);
                if (enfileirar(fila, dado) == 1){
                    printf("Valor enfileirado com sucesso!\n");
                }
                break;
            case 2:
                if ((desenfileirar(fila, &dado)) == 1){
                    printf("Desenfileirado com sucesso! O valor removido foi: %d.\n", dado);
                }
                break;
            case 3:
                exibir(fila);
                break;
        }
    }
}
