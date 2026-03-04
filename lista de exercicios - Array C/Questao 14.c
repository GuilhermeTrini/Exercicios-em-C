#include <stdio.h>

int main()
{
    char string[50], letter;
    int count = 0;

    scanf("%[^\n]", string);
    scanf(" %c", &letter);

    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == letter){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
