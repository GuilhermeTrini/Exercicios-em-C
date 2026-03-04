#include <stdio.h>

void remover(char *frase, int pos)
{
    frase[pos] = ' ';
    for (int i = pos; frase[i] != '\0'; i++){
        frase[i] = frase[i + 1];
    }
}

int main()
{
    int pos;
    char frase[50];

    printf("Digite a frase: ");
    scanf("%[^\n]", frase);
    printf("Digite a posicao: ");
    scanf("%d", &pos);
    remover(frase, pos);
    printf("Frase sem o caracter: %s", frase);
}
