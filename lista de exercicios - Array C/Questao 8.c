#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vetor[40], count = 0;
    srand(time(0));

    for (int i = 0; i < 40; i++){
        vetor[i] = rand();
        if (vetor[i] % 2 == 0){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
