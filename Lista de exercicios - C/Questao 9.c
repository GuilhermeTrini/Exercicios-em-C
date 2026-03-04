#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int numero;
    scanf("%d", &numero);
    for (int i = 1; i <= numero; i++){
        for (int j = 1; j <= numero; j++){
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
