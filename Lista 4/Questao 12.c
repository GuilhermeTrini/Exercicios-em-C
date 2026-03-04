#include <stdio.h>

int vetorDobro(int *pt)
{
    for (int i = 0; i < 10; i++){

        *pt = *pt * 2;
        pt++;
    }
}
int main()
{
    int vetor[10];

    for (int i = 0; i < 10; i++){
        printf("Digite os valores para o vetor: ");
        scanf("%d", &vetor[i]);
    }

    vetorDobro(&vetor[0]);

    for (int i = 0; i < 10; i++){
        printf("%d\n", vetor[i]);
    }
}
