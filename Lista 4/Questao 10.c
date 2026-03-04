#include <stdio.h>

int matLinha(int tamanho, int matriz[tamanho][tamanho])
{
    int soma = 0, vetor[tamanho];

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            soma += matriz[i][j];
        }
        vetor[i] = soma;
        soma = 0;
    }
    for (int i = 0; i < tamanho - 1; i++){
        if(vetor[i] != vetor[i + 1]){
            return 0;
        }
    }
    return 1;
}

int matColuna(int tamanho, int matriz[tamanho][tamanho])
{
    int soma = 0, vetor[tamanho];

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            soma += matriz[j][i];
        }
        vetor[i] = soma;
        soma = 0;
    }
    for (int i = 0; i < tamanho - 1; i++){
        if(vetor[i] != vetor[i + 1]){
            return 0;
        }
    }
    return 1;
}

int matDiag(int tamanho, int matriz[tamanho][tamanho])
{
    int diagonal[2] = {0, 0};

    for (int i = 0; i < tamanho; i++){
        diagonal[0] += matriz[i][i];
        diagonal[1] += matriz[i][tamanho - i - 1];
    }
    if(diagonal[0] == diagonal[1]){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int tamanho;

    printf("Digite a tamanho da matriz quadrada (ex: 2x2, 3x3): ");
    scanf("%d", &tamanho);

    int matriz[tamanho][tamanho];
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    if (matLinha(tamanho, matriz) && matColuna(tamanho, matriz) && matDiag(tamanho, matriz)){
        printf("A matriz eh magica");
    }
    else{
        printf("A matriz nao eh magica");
    }
    return 0;
}
