#include <stdio.h>
#include <string.h>

int calcular_digito(char chave[])
{
    int maior1 = 0, maior2 = 0, maior3 = 0, resultado = 0;
    for (int i = 0; i < 3; i++){
        if (maior1 < (chave[i] - '0')){
            maior1 = chave[i] - '0';
        }
    }
    for (int i = 4; i < 7; i++){
        if (maior2 < (chave[i] - '0')){
            maior2 = chave[i] - '0';
        }
    }
    for (int i = 8; i < 11; i++){
        if (maior3 < (chave[i] - '0')){
            maior3 = chave[i] - '0';
        }
    }
    resultado = (maior1 + maior2 + maior3) % 10;
    return resultado;
}

int main()
{
    char chave[13];

    while(1){
        printf("Informe a chave: ");
        scanf("%s", chave);
        if (strcmp(chave, "FIM") == 0){
            break;
        }
        if (calcular_digito(chave) == (chave[12] - '0')){
            printf("VALIDO\n");
        }
        else{
            printf("INVALIDO\n");
        }
    }
    return 0;
}
