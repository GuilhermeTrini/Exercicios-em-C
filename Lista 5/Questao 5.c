#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto{
    float x;
    float y;
};

struct Circulo{
    char nome[11];
    struct Ponto centro;
    float raio;
};

struct Circulo criaCirculo(char nome[11], struct Ponto centro, float raio)
{
    int i;
    struct Circulo circulo;

    for (i = 0; nome[i] != '\0'; i++){
        circulo.nome[i] = nome[i];
    }
    circulo.nome[i] = '\0';
    circulo.centro = centro;
    circulo.raio = raio;

    return circulo;
}

int contem(struct Circulo* circulos)
{
    int posContem, posContido;
    float dist;
    printf("Digite qual circulo contem (digite em numeros ex: 1, 2 ou 3): ");
    scanf("%d", &posContem);
    printf("Digite qual circulo esta contido (digite em numeros ex: 1, 2 ou 3): ");
    scanf("%d", &posContido);

    dist = sqrt(pow(circulos[posContem - 1].centro.x - circulos[posContido - 1].centro.x, 2) + pow(circulos[posContem - 1].centro.y - circulos[posContido - 1].centro.y, 2));
    if ((dist + circulos[posContido - 1].raio) <= circulos[posContem - 1].raio){
        return 1;
    }
    return 0;
}

int main()
{
    int quant;
    char nome[11];
    float raio;
    printf("Digite quantos circulos quer verificar: ");
    scanf("%d", &quant);

    struct Circulo *circulos;
    struct Ponto centro;


    circulos = (struct Circulo*) malloc (quant * sizeof(struct Circulo));
    if (circulos == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }

    for (int i = 0; i < quant; i++){
        printf("Digite o nome do circulo %d: ", i+1);
        scanf(" %s", nome);
        printf("Digite as coordenadas do centro do circulo %d: ", i+1);
        scanf(" %f %f", &centro.x, &centro.y);
        printf("Digite o raio do circulo %d: ", i + 1);
        scanf(" %f", &raio);
        circulos[i] = criaCirculo(nome, centro, raio);
    }
    for (int i = 0; i < (quant - 1); i++){
        printf("%d\n", contem(circulos));
    }
    free(circulos);
    return 0;
}
