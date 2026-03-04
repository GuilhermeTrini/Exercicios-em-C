#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int quantidade, recorde, count = 0, soma = 0, menor = -1, maior = 0;
    printf("Informe a quantidade de Treinos: ");
    scanf("%d", &quantidade);
    printf("Informe o Recorde Regional: ");
    scanf("%d", &recorde);
    while (count < quantidade){
        count++;
        int tempo;
        printf("Digite o tempo %d: ", count);
        scanf("%d", &tempo);
        soma += tempo;
        if (maior < tempo){
            maior = tempo;
        }
        if (menor > tempo || menor == -1){
            menor = tempo;
        }
    }
    float media = (float) soma/count;
    printf("Maior tempo: %d segundos\n", maior);
    printf("Menor tempo: %d segundos\n", menor);
    printf("Média: %.1f segundos\n", media);
    if (media < recorde){
        printf("Você está abaixo do recorde!\n");
    }
    return 0;
}

