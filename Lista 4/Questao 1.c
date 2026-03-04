#include <stdio.h>

void somaImpar(int listaNotas[], int tamanho){
    int soma = 0;
    for (int i = 0; i < tamanho; i++){
        if (listaNotas[i] % 2 != 0){
            soma += listaNotas[i];
        }
    }
    printf("A soma dos numeros impares da lista é: %d\n", soma);
}

void mediaPar(int listaNotas[], int tamanho)
{
    int count = 0, soma = 0;
    float media;
    for (int i = 0; i < tamanho; i++){
        if (listaNotas[i] % 2 == 0){
            soma += listaNotas[i];
            count++;
        }
    }
    media = (float) soma/count;
    printf("A media de todos os valores pares é: %.2f\n", media);
}

void menor70(int listaNotas[], int tamanho)
{
    int count = 0;
    for (int i = 0; i < tamanho; i++){
        if (listaNotas[i] < 70){
            count++;
        }
    }
    printf("A contagem de notas abaixo de 70 é: %d notas\n", count);
}

void acimaMedia(int listaNotas[], int tamanho)
{
    int soma = 0, count = 0;
    float media;
    for (int i = 0; i < tamanho; i++){
        soma += listaNotas[i];
    }
    media = (float) soma/tamanho;
    for(int i = 0; i < tamanho; i++){
        if (listaNotas[i] > media){
            count++;
        }
    }
    printf("A quantidade de notas acima da média é: %d notas\n", count);
}


int main()
{
    int tamanho, nota;

    printf("Digite o tamanho da lista de notas: ");
    scanf("%d", &tamanho);
    int listaNotas[tamanho];
    for (int i = 0; i < tamanho; i++){
        printf("Digite as notas: ");
        scanf("%d", &nota);
        listaNotas[i] = nota;
    }
    somaImpar(listaNotas, tamanho);
    mediaPar(listaNotas, tamanho);
    menor70(listaNotas, tamanho);
    acimaMedia(listaNotas, tamanho);
    return 0;
}
