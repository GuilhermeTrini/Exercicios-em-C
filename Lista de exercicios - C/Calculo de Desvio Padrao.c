#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    float numeros[5], media = 0, varianciaAmostral = 0, varianciaPopulacional = 0, somaMedia = 0, somaDesvio = 0, desvio = 0;
    float n = 5, desvioPopulacional = 0, desvioAmostral = 0;

    for (int i = 0; i < n; i++){
        scanf(" %f", &numeros[i]);
    }
    for (int i = 0; i < n; i++){
        somaMedia += numeros[i];
    }
    media = somaMedia / n;
    for (int i = 0; i < n; i++){
        desvio = (numeros[i] - media) * (numeros[i] - media);
        somaDesvio += desvio;
    }
    varianciaAmostral = somaDesvio / (n - 1);
    varianciaPopulacional = somaDesvio / n;
    desvioPopulacional = sqrt(varianciaPopulacional);
    desvioAmostral = sqrt(varianciaAmostral);
    printf("Variancia Amostral: %.1f\n", varianciaAmostral);
    printf("Variancia Populacional: %.1f\n", varianciaPopulacional);
    printf("Media: %.1f\n", media);
    printf("Desvio Populacional: %.1f\n", desvioPopulacional);
    printf("Desvio Amostral: %.1f\n", desvioAmostral);
}
