#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void ordemCodigo(int tam, char cod[][5])
{
    int menor;
    char aux[5];
    for (int i = 0; i < tam - 1; i++){
        menor = i;
        for (int j = i + 1; j < tam; j++){
            if (strcmp(cod[j], cod[menor]) < 0){
                menor = j;
            }
        }
        if (i != menor){
            strcpy(aux, cod[menor]);
            strcpy(cod[menor], cod[i]);
            strcpy(cod[i], aux);
        }
    }
}

int main()
{
    int quant;
    printf("Quantos codigos serao cadastrados: ");
    scanf("%d", &quant);
    char codigos[quant][5];
    for (int i = 0; i < quant; i++){
        printf("Digite o codigo: ");
        scanf("%s", codigos[i]);
    }
    printf("\n");
    ordemCodigo(quant, codigos);
    for (int i = 0; i < quant; i++){
        printf("%s\n", codigos[i]);
    }
}
