#include <stdio.h>

int main()
{
    char name[50];

    scanf("%s", name);
    for (int i = 0; name[i] != '\0'; i++){
        if ((i + 1) % 2 != 0){
            printf("%c ", name[i]);
        }
    }
    return 0;
}
