#include <stdio.h>
#include <math.h>

int primo(int numero)
{
    int count = 0;
    if (numero < 2){
        return 0;
    }
    for (int i = 1; i <= numero; i++){
        if (numero % i == 0){
            count++;
        }
    }
    if (count == 2){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int numero;

    printf("Digite o numero a ser verificado: ");
    scanf("%d", &numero);
    if (primo(numero)){
        printf("O numero %d é primo\n", numero);
    }
    else{
        printf("O numero %d nao é primo\n", numero);
    }
    return 0;
}
