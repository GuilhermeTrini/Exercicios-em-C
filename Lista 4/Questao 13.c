#include <stdio.h>

void trocaLetra(char *string, char original, char novo)
{
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == original){
            string[i] = novo;
        }
    }
}

int main()
{
    char string[50], original, novo;

    printf("Digite a string desejada: ");
    scanf("%[^\n]", string);

    printf("Digite o caracter antigo e novo (ex: original novo): ");
    scanf(" %c %c", &original, &novo);

    trocaLetra(string, original, novo);

    printf("String modificada: %s", string);
}
