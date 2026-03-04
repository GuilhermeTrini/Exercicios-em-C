#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriza[2][3], matrizb[2][3], matrizc[2][3];
    srand(time(NULL));

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            matriza[i][j] = rand() % 10;
            matrizb[i][j] = rand() % 10;
            printf("%d ", matriza[i][j]);
            printf("%d \n", matrizb[i][j]);
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            matrizc[i][j] = matriza[i][j] + matrizb[i][j];
            printf("%d ", matrizc[i][j]);
        }
    }
    return 0;
}
