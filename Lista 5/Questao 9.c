#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verifyListInt(const char *s );
int *splitInt(const char *s , int *size );


int main()
{
    char input[100];
    printf("Digite inteiros separados por espacos: ");
    fgets(input, 100, stdin);

    int size;

    int *vetInt = splitInt (input, &size);

    if (vetInt == NULL){
        printf("String invalida\n");
        return -1;
    }

    printf("Size: %d\n", size);
    for (int i = 0; i < size; i++){
        printf("%d ", vetInt[i]);
    }
    printf("\n");

    free(vetInt);
    return 0;
}

int verifyListInt(const char *s )
{
    int i = 0, count = 0, numero = 0;
    while (s[i] != '\0'){
        if ((isdigit(s[i])) == 0 && (isspace(s[i])) == 0){
            return 0;
        }
        if (isdigit(s[i])){
            numero = 1;
        }
        if (isspace(s[i]) && numero == 1){
            count++;
            numero = 0;
        }
        i++;
    }
    return count;
}

int *splitInt(const char *s , int *size)
{
    *size = verifyListInt(s);
    if (*size == 0){
        return 0;
    }
    int *inteiros, i = 0, j = 0, k = 0;
    char aux[20];

    inteiros = (int*) malloc (*size * sizeof(int));
    while (s[i] != '\0'){
        if (isdigit(s[i])){
            aux[j] = s[i];
            j++;
        }
        else if (isspace(s[i])){
            aux[j] = '\0';
            inteiros[k] = atoi(aux);
            k++;
            j = 0;
        }
        i++;
    }
    if (j > 0){
        aux[j] = '\0';
        inteiros[k] = atoi(aux);
        k++;
    }
    return inteiros;
}
