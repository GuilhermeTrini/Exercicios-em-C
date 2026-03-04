#include <stdio.h>

int main()
{
    char frase [100];
    int count = 0;

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);

    for (int i = 0; frase[i] != '\0'; i++){
        if (frase[i] == ' '){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
