#include <stdio.h>

void valores(int numeros[], int quantidade, int *maior, int *menor, int *soma)
{
    *maior = numeros[0];
    *menor = numeros[0];
    *soma = 0;
    for (int i = 0; i < quantidade; i++){
        *soma += numeros[i];
        if (numeros[i] < *menor){
            *menor = numeros[i];
        }
        if (numeros[i] > *maior){
            *maior = numeros[i];
        }
    }
}

int main()
{
    int quantidade;

    printf("Informe a quantidade de valores da lista de numeros: ");
    scanf("%d", &quantidade);

    int numeros[quantidade], maior, menor, soma;


    for (int i = 0; i < quantidade; i++){
        printf("Digite o número: ");
        scanf(" %d", &numeros[i]);
    }
    valores(numeros, quantidade, &maior, &menor, &soma);

    printf("A soma dos numeros eh: %d\nO maior numero eh: %d\nE o menor eh: %d", soma, maior, menor);
    return 0;
}
