#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vetorA[10], vetorB[10], count = 0;
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        vetorA[i] = rand() % 10;
    }
    for (int j = 0; j < 10; j++){
        vetorB[count] = vetorA[9 - j];
        count++;
    }
    for (int z = 0; z < 10; ++z){
        printf("%d\n", vetorA[z]);
    }
    printf("\n");
    for (int y = 0; y < 10; ++y){
        printf("%d\n", vetorB[y]);
    }
    return 0;
}
