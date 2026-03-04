#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filapessoa.c"


int main()
{
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL){
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    cria(fila);
    int option = 0;
    while (option != 6){
        printf("\nFILA DE PESSOA\n------------------\n1 - Exibir a fila\n2 - Entrar na fila\n3 - Sair da fila\n4 - Primeiro da fila\n5 - Quantidade de pessoas na fila\n6 - Sair\n\nDigite a opcao: ");
        scanf("%d", &option);
        switch (option){
        case 1:
            exibir(fila);
            break;
        case 2:
            {
            Pessoa pessoa;
            printf("Digite o nome: ");
            scanf(" %[^\n]", pessoa.nome);
            printf("Digite a idade: ");
            scanf("%d", &pessoa.idade);
            printf("Digite o CPF: ");
            scanf("%d", &pessoa.cpf);
            printf("Eh gestante? (0 - nao, 1 - sim): ");
            scanf("%d", &pessoa.gestante);
            if (enfileirar(fila, pessoa)){
                printf("Enfileiramento concluido com sucesso!\n");
            }
            }
            break;
        case 3:
            {
            char nome[20];
            if (desenfileirar(fila, nome)){
                printf("Desenfileiramento concluido com sucesso!\n%s saiu da fila.\n", nome);
            }
            }
            break;
        case 4:
            exibir1(fila);
            break;
        case 5:
            printf("Tem %d pessoa(s) na fila!\n", tamanho(fila));
            break;
        }
    }
}
