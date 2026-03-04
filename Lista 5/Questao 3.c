#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2)
{
    int *v3, *aux;
    v3 = (int*) malloc ((n1 + n2) * sizeof(int));
    if (v3 == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    aux = v3;

    for (int i = 0; i < n1; i++){
        *v3 = *v1;
        v3++;
        v1++;
    }
    for(int i = 0; i < n2; i++){
        *v3 = *v2;
        v3++;
        v2++;
    }

    return aux;
}

int main()
{
    int n1, n2;

    printf("Digite a quantidade de elementos do vetor 1: ");
    scanf("%d", &n1);

    printf("Digite a quantidade de elementos do vetor 2: ");
    scanf("%d", &n2);

    int v1[n1], v2[n2], *v3;

    printf("Digite os valores do vetor 1: ");
    for (int i = 0; i < n1; i++){
        scanf("%d", &v1[i]);
    }
    printf("Digite os valores do vetor 2: ");
    for (int i = 0; i < n2; i++){
        scanf("%d", &v2[i]);
    }

    v3 = uniao(v1, n1, v2, n2);
    int *aux = v3;

    printf("A uniao dos vetores: ");
    for (int i = 0; i < (n1 + n2); i++){
        printf("%d ", *aux);
        aux++;
    }
    free(v3);
    return 0;
}
