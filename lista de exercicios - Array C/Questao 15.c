#include <stdio.h>

int main()
{
    char string[50], letter;
    int count = 0, V[50], tamanho = 0;

    printf("Digite uma string: ");
    scanf("%[^\n]", string);
    printf("Digite o caractere: ");
    scanf(" %c", &letter);

    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == letter){
            V[count] = i;
            count++;
        }
        tamanho = i + 1;
    }
    printf("Posições onde ocorre o caractere %c: ", letter);
    for (int i = 0; i < count; i++){
        printf("%d ", V[i]);
    }
    printf("\nA String tem tamanho = %d", tamanho);
    return 0;
}

