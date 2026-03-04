#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[10][10], maior = 0;
    srand(time(0));

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matriz[i][j] = rand();
            printf("%d ", matriz[i][j]);
            if (maior < matriz[i][j]){
                maior = matriz[i][j];
            }
        }
    }
    printf("\n%d", maior);
    return 0;
}
