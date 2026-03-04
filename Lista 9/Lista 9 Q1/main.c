#include <stdio.h>
#include <stdlib.h>
#include "listaduen.c"

int main()
{
    int option = 0;
    ListaProdutos *carrinho = (ListaProdutos*)malloc(sizeof(ListaProdutos));
    if (carrinho == NULL){
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    criaCarrinho(carrinho);
    while (option != 6){
        printf(">>> Bem-vindo ao Carrinho de Compras!\n\n1 - Adicionar Produto\n2 - Remover Produto\n3 - Atualizar Produto\n4 - Visualizar Todo o Carrinho\n5 - Filtrar Produtos\n6 - Terminar Programa\n\n");
        printf("Digite a opcao: ");
        scanf("%d", &option);
        switch (option){
            case 1:
                {
                Produto produto;
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", produto.nome),
                printf("Digite a categoria do produto: ");
                scanf(" %[^\n]", produto.categoria);
                printf("Digite a quantidade de itens do produto: ");
                scanf("%d", &produto.quantidade);
                printf("Digite o valor da unidade do produto (R$): ");
                scanf("%f", &produto.valor);
                if (inserirProd(carrinho, produto) == 1){
                    printf("\nProduto adicionado com sucesso!\n");
                }else{
                    printf("Erro na adicao de produto!\n\n");
                    }
                }
                break;
            case 2:
                {
                char nome[20];
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", nome);
                if (removerProd(carrinho, nome) == 1){
                    printf("\nProduto removido com sucesso!\n");
                }else{
                    printf("Erro na remocao!\n\n");
                    }
                }
                break;
            case 3:
                {
                Produto produto;
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", produto.nome),
                printf("Digite a nova categoria do produto: ");
                scanf(" %[^\n]", produto.categoria);
                printf("Digite a nova quantidade de itens do produto: ");
                scanf("%d", &produto.quantidade);
                printf("Digite o novo valor da unidade do produto (R$): ");
                scanf("%f", &produto.valor);
                if (atualizaProd(carrinho, produto) == 1){
                    printf("\nProduto atualizado com sucesso!\n\n");
                }else{
                    printf("\nErro na atualizacao do produto!\n\n");
                    }
                }
                break;
            case 4:
                exibirCarrinho(carrinho);
                break;
            case 5:
                {
                char categoria[15];
                printf("Digite a categoria desejada: ");
                scanf(" %[^\n]", categoria);
                filtrarProd(carrinho, categoria);
                }
                break;
        }
    }
}
