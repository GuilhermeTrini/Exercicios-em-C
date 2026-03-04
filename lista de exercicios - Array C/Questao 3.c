#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int VN[30], maior = 0, menor = -1;
    srand(time(NULL));

    for (int i = 0; i < 30; i++){
        VN[i] = rand();
    }
    for (int i = 0; i < 30; i++){
        if (maior < VN[i]){
            maior = VN[i];
        }
        if (menor > VN[i] || menor == -1){
            menor = VN[i];
        }
    }
    printf("%d e %d\n", maior, menor);
    for (int i = 0; i < 30; i++){
        printf("%d ", VN[i]);
    }
    return 0;
}
