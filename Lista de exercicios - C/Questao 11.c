#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int numero = 0, count = 0;
    while (numero != -1){
    printf("Informe o número a ser verificado: ");
    scanf("%d", &numero);
    for (int i = 1; i <= numero; i++){
        if (numero % i == 0){
            count++;
        }
    }
    if (numero == 1){
        printf("O numero nao e primo\n");
    }
    else if (count <= 2){
        printf("O numero e primo!\n");
    }
    else{
        printf("O numero nao e primo!\n");
    }
    count = 0;
    }
    return 0;
}
