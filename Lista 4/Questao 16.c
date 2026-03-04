#include <stdio.h>
#include <math.h>

double desvioPadrao(double *v, int n)
{

    double media = 0, somatorio = 0, desvio = 0, soma = 0, *p;
    p = v;

    for (int i = 0; i < n; i++){
        soma += *p;
        p++;
    }

    media = soma/n;

    for (int i = 0; i < n; i++){
        somatorio += pow(media - *v, 2);
        v++;
    }
    desvio = sqrt(somatorio/(n - 1));

    return desvio;

}
int main()
{
    int n;
    printf("Digite a quantidade de valores: ");
    scanf("%d", &n);

    double v[n];
    for (int i = 0; i < n; i++){
        printf("Digite um valor: ");
        scanf("%lf", &v[i]);
    }
    printf("O desvio eh: %.4f", desvioPadrao(v, n));

}
