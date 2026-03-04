#include <stdio.h>

int main()
{
    int numero;
    printf("Informe o numero: ");
    scanf("%d", &numero);
    float soma = 0;
    for (int i = 1; i <= numero; i++){
        soma += (float) 1/i;
        printf("1/%d = %.5f\n", i, (float)1/i);
    }
    printf("The result is: %.2f", soma);
    return 0;
}
