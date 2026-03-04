#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz1[5][5], matriz2[5][5];
    srand(time(0));

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matriz1[i][j] = rand() % 10;
            matriz2[i][j] = matriz1[i][j] * 2;
            printf("%d %d\n", matriz1[i][j], matriz2[i][j]);
        }
    }
    return 0;
}
