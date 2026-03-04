#include <stdio.h>
#include <stdlib.h>

int* Acertados(int loteria[], int bilhete[], int *count)
{
    int *inicio, *acertos;
    *count = 0;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (loteria[j] == bilhete[i]){
                *count += 1;
            }
        }
    }
    if (*count == 0){
        printf("Nenhum acerto");
        exit(1);
    }
    acertos = (int*) malloc (*count * sizeof(int));
    if (acertos == NULL){
        printf("Erro na alocacao de memoria");
    }
    inicio = acertos;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (loteria[j] == bilhete[i]){
                *acertos = bilhete[i];
                acertos++;
            }
        }
    }
    return inicio;
}

int main()
{
    int loteria[6], bilhete[6], count, *acertados;

    printf("Numeros sorteados pela loteria: ");
    for (int i = 0; i < 6; i++){
        scanf("%d", &loteria[i]);
    }
    printf("Numeros do bilhete: ");
    for (int i = 0; i < 6; i++){
        scanf("%d", &bilhete[i]);
    }
    acertados = Acertados(loteria, bilhete, &count);

    printf("\nNumeros sorteados: ");
    for (int i = 0; i < 6; i++){
        printf("%d ", loteria[i]);
    }
    printf("\nNumeros acertados: ");
    for (int i = 0; i < count; i++){
        printf("%d ", acertados[i]);
    }
    free(acertados);
}
