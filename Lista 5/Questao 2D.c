#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto{
    float x;
    float y;
};

float distanciaNova(struct Ponto *p1, struct Ponto *p2 )
{
    float dist;
    dist = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    return dist;
}
int main()
{
    struct Ponto *p1, *p2;

    p1 = (struct Ponto*)malloc(sizeof(struct Ponto));
    p2 = (struct Ponto*)malloc(sizeof(struct Ponto));

    printf("Informe o ponto 1: ");
    scanf("%f %f", &p1->x, &p1->y);

    printf("Agora informe o ponto 2: ");
    scanf("%f %f", &p2->x, &p2->y);

    printf("A distancia entre o ponto 1 e o ponto 2 eh: %.2f", distanciaNova(p1, p2));

    free(p1);
    free(p2);
    return 0;
}


