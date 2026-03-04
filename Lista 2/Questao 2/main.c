#include <stdio.h>
#include <stdlib.h>

/*
Resultado do sorteio dos numeros do vetor: https://resulta.do/ac20149c758f
*/

int comparar(const void *a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main()
{
    int vetor[] = {15, 77, 79, 80, 35, 39, 57, 13, 86, 25, 6, 2, 27, 24, 75};
    int n = sizeof(vetor) / sizeof(vetor[0]); /* o tamanho do vetor = 15*/
    printf("Vetor: ");
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\nVetor ordenado: ");
    qsort(vetor, n, sizeof(int), comparar);
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}
