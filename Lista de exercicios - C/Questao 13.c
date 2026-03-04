#include <stdio.h>

int main()
{
    float numero = 1, soma = 0;
    for (int i = 1; i <= 50; i++){
        soma += numero/i;
        numero += 2;
    }
    printf("%.4f\n", soma);
    return 0;
}
