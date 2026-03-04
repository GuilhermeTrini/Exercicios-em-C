#include <stdio.h>

int fatorial(int numero)
{
    if (numero == 0){
        return 1;
    }
    int fatorial = 1;
    while (numero != 1){
        fatorial *= numero;
        numero--;
    }
    return fatorial;
}

int vetorF(int vetorA[], int vetorB[])
{
    for (int i = 0; i < 10; i++){
        vetorB[i] = fatorial(vetorA[i]);
    }
}


int main()
{
    int vetorA[10], vetorB[10];
    for (int i = 0; i < 10; i++){
        printf("Digite um valor para o vetor A: ");
        scanf(" %d", &vetorA[i]);
    }
    vetorF(vetorA, vetorB);
    for(int i = 0; i < 10; i++){
        printf("%d   %d\n", vetorA[i], vetorB[i]);
    }
}
