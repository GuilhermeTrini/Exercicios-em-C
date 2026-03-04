#include <stdio.h>
#include <ctype.h>

int contaDigitos(char* string[])
{
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        if (isdigit(string[i])){
            count++;
        }
    }
    return count;
}

int main()
{
    char string[50];

    printf("Digite a string sem espaços: ");
    scanf(" %s", string);

    printf("A string tem %d digitos", contaDigitos(string));
}
