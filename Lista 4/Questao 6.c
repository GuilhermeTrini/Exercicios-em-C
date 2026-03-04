#include <stdio.h>
#include <math.h>

int somaPrimos(int x, int y)
{
    int numero = y - x + 1, count = 0, soma = 0;

    while (numero > 0){
        for (int i = 2; i <= sqrt(x); i++){
            if (x % i == 0){
                count++;
            }
        }
        if (count == 0){
            soma += x;
        }
        x++;
        numero--;
        count = 0;
    }
    return soma;
}

int main()
{
    int x, y;
    printf("Digite os números a serem verificados (exemplo: x y): ");
    scanf("%d %d", &x, &y);

    printf("O valor de x: %d\nO valor de y: %d\nA somatória dos números primos entre eles: %d", x, y, somaPrimos(x, y));
    return 0;
}
