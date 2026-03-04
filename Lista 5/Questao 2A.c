#include <stdio.h>
#include <stdlib.h>

struct Ponto{
    float x;
    float y;
};

int main()
{
    struct Ponto v1, v2, v3;

    printf("Informe os pontos esquerdo inferior e direito superior do retangulo (ex: x y x y): ");
    scanf("%d %d %d %d", &v1.x, &v1.y, &v2.x, &v2.y);

    printf("Agora informe o ponto que deseja verificar: ");
    scanf("%d %d", &v3.x, &v3.y);

    if ((v1.x <= v3.x && v3.x <= v2.x) && (v1.y <= v3.y && v3.y <= v2.y)){
        printf("O ponto esta dentro do retangulo");
    }
    else{
        printf("O ponto nao esta dentro do retangulo");
    }
    return 0;
}
