#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[10][10];
    srand(time(0));

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matriz[i][j] = rand() % 10;
            printf("%d ", matriz[i][j]);
        }
        printf("-- %d --\n", matriz[i][i]);
    }
    return 0;
}
