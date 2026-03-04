#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string1[80], string2[80], string3[160], string4[160], stringMod[80], letter;
    int tamanho1, tamanho2, j, modulo = 0;
    printf("String1: ");
    scanf("%[^\n]", string1);
    printf("String2: ");
    scanf(" %[^\n]", string2);
    printf("Digite o caracter a ser buscado na string1: ");
    scanf(" %c", &letter);

    printf("String1 Maiusculas: ");
    for (int i = 0; string1[i] != '\0'; i++){
        if (islower(string1[i])){
            stringMod[i] = toupper(string1[i]);
        }
        else{
            stringMod[i] = string1[i];
        }
        printf("%c", stringMod[i]);
    }
    printf("\nString1 Minusculas: ");
    for (int i = 0; string1[i] != '\0'; i++){
        if (isupper(string1[i])){
            stringMod[i] = tolower(string1[i]);
        }
        else{
            stringMod[i] = string1[i];
        }
        printf("%c", stringMod[i]);
    }
    printf("\nString3: ");
    tamanho1 = strlen(string1);
    tamanho2 = strlen(string2);
    for (j = 0; j < tamanho1; j++){
        string3[j] = string1[j];
        printf("%c", string3[j]);
    }
    string3[j] = ' ';
    printf("%c", string3[j]);
    j++;
    for (int i = 0; i < tamanho2; i++, j++){
        string3[j] = string2[i];
        printf("%c", string3[j]);
    }
    printf("\n");
    for (int i = 0; string1[i] != '\0'; i++){
        if (string1[i] == letter){
            printf("O caracter esta na posicao %d\n", i);
            modulo = 1;
            break;

        }
    }
    if (modulo == 0){
        printf("O caractere nao esta na string\n");
    }
    j--;
    for (int i = 0; string3[i] != '\0'; i++, j--){
        string4[i] = string3[j];
    }
    printf("A string 4: %s", string4);
    return 0;
}
