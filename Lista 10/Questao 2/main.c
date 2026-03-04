#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaseqest.c"

int main()
{
    Fila *filaPe, *filaPa, *filaE;
    filaPe = (Fila*)malloc(sizeof(Fila));
    filaPa = (Fila*)malloc(sizeof(Fila));
    filaE = (Fila*)malloc(sizeof(Fila));
    if (filaPe == NULL || filaPa == NULL || filaE == NULL){
        printf("Erro de alocacao de memora");
        exit(1);
    }
    cria(filaPe);
    cria(filaPa);
    cria(filaE);
    int option = -1;
    char nome[MAX];
    while (option != 0){
        printf("--------Editor de Fila--------\n1 - Inserir na fila de pedido\n2 - Remover da fila de pedido\n3 - Remover da fila de pagamento\n4 - Remover da fila de encomenda\n5 - Exibir filas\n0 - Sair\nDigite sua opcao: ");
        scanf("%d", &option);
        printf("\n");
        switch (option){
            case 1:
                printf("Digite o nome do cliente: ");
                scanf(" %[^\n]", nome);
                if (enfileirar(filaPe, nome) == 1){
                    printf("Enfileiramento concluido com sucesso!\n");
                }
                break;
            case 2:
                if (desenfileirar(filaPe, nome) == 1){
                    printf("Desenfileiramento concluido com sucesso!\n");
                    if (enfileirar(filaPa, nome) == 1){
                        printf("O cliente foi para a fila de pagamento!\n");
                    }
                }
                break;
            case 3:
                if (desenfileirar(filaPa, nome) == 1){
                    printf("Desenfileiramento concluido com sucesso!\n");
                    if (enfileirar(filaE, nome) == 1){
                        printf("O cliente foi para a fila de pagamento!\n");
                    }
                }
                break;
            case 4:
                if (desenfileirar(filaE, nome) == 1){
                    printf("Desenfileiramento concluido com sucesso!\n");
                }
                printf("Cliente atendido: %s\n\n", nome);
                break;
            case 5:
                printf("- Fila Pedidos -\n");
                exibirFila(filaPe);
                printf("\n- Fila Pagamentos -\n");
                exibirFila(filaPa);
                printf("\n- Fila Encomendas -\n");
                exibirFila(filaE);
                break;
        }
    }
}
