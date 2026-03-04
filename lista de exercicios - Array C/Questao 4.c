#include <stdio.h>

int main()
{
    int vetor[8], posicao, numero;

    for (int i = 0; i < 8; i++){
        vetor[i] = i * 4;
    }
    scanf("%d", &numero);
    for (int i = 0; i < 8; i++){
        if (vetor[i] == numero){
            posicao = i;
            printf("O número existe na posicao %d\n", posicao);
            break;
        }
        else{
            posicao = -1;
        }
    }
    if (posicao == -1){
        printf("O número não existe no vetor\n");
    }
    return 0;
}
