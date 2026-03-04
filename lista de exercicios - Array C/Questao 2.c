#include <stdio.h>

int main()
{
    int P[10], V[10], S[10], count = 0;

    for (int i = 2; i <= 20; i += 2){
        P[count] = i;
        count++;
    }
    count = 0;
    for (int i = 10; i <= 19; i++){
        V[count] = i;
        count++;
    }
    for (int i = 0; i < 10; i++){
        S[i] = P[i] + V[i];
    }
    printf("Vetor P: ");
    for (int i = 0; i < 10; i++){
        printf("%d ", P[i]);
    }
    printf("\nVetor V: ");
    for (int i = 0; i < 10; i++){
        printf("%d ",V[i]);
    }
    printf("\nVetor S: ");
    for (int i = 0; i < 10; i++){
        printf("%d ", S[i]);
    }

    return 0;
}
