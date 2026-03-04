#include <stdio.h>
#include <string.h>

int main()
{
    char nomes[10][20] = {"joao", "carlos", "roberto", "junior", "chico", "travis", "scott", "rihanna", "adele", "ladygaga"};
    char maior[10], menor [10] = {"aaaaaaaaa"};
    for (int i = 0; i < 10; i++){
        if (strlen(nomes[i]) < strlen(menor)){
            strcpy(menor, nomes[i]);
        }
        if (strlen(nomes[i]) > strlen(maior)){
            strcpy(maior, nomes[i]);
        }
    }
    if (strcmp(maior, menor) == 1){
        printf("%s\n%s", menor, maior);
        }
    else{
        printf("%s\n%s", maior, menor);
    }
}
