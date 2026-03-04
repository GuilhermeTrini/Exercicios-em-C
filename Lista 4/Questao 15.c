#include <stdio.h>

void inverte(char *frase, char *ifrase)
{
    int i = 0, j;
    while (frase[i] != '\0'){
        i++;
    }
    ifrase[i] = '\0';
    i--;
    for (int j = 0; frase[j] != '\0'; j++, i--){
        ifrase[i] = frase[j];
    }

}

int main()
{
    char frase[50], ifrase[50];

    printf("Digite a frase desejada: ");
    scanf("%[^\n]", frase);

    inverte(frase, ifrase);

    printf("Frase digitada: %s\nSaida na tela: %s\n", frase, ifrase);
}
