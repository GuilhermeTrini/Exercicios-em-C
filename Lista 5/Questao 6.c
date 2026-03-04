#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro{
    char titulo[20];
    char autor[20];
    float preco;
}Livro;

float mediaPreco(Livro livros[20], int count)
{
    float media, soma = 0;
    for (int i = 0; i < count; i++){
        soma += livros[i].preco;
    }
    media = soma/count;
    return media;
}

int countAcima(Livro livros[20], int count, float media)
{
    int contagem = 0;
    for (int i = 0; i < count; i++){
        if (livros[i].preco > media){
            contagem++;
        }
    }
    return contagem;
}

void localizar(Livro livros[20], int count, char nome[])
{
    for (int i = 0; i < count; i++){
        if (strcmp(livros[i].titulo, nome) == 0 || strcmp(livros[i].autor, nome) == 0){
            printf("\nTitulo: %s\nAutor: %s\nPreço: %.2f\n", livros[i].titulo, livros[i].autor, livros[i].preco);
            break;
        }
    }
}

int main()
{
    Livro livros[20];
    int count = 0;

    while (1){
        int opcao = 0;
        printf("Digite a opcao que deseja acessar: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Escreva o titulo do livro: ");
                scanf(" %[^\n]", livros[count].titulo);
                printf("Escreva o nome de autor do livro: ");
                scanf(" %[^\n]", livros[count].autor);
                printf("Preço do livro: ");
                scanf("%f", &livros[count].preco);
                count++;
                break;
            case 2:
                printf("A media dos preços dos livros eh: %.2f\n", mediaPreco(livros, count));
                break;
            case 3:
                float media;
                int contagem;
                media = mediaPreco(livros, count);
                contagem = countAcima(livros, count, media);
                printf("Tem %d livros acima da media de preços.\n", contagem);
                break;
            case 4:
                char nome[20];
                printf("Digite o titulo/autor do livro que deseja localizar: ");
                scanf(" %[^\n]", nome);
                localizar(livros, count, nome);
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}
