#include <stdio.h>



int amigos(int num1, int num2)
{
    int soma1, soma2;

    for (int i = 1; i <= (num1/2); i++){
        if (num1 % i == 0){
            soma1 += i;
        }
    }
    for (int i = 1; i <= (num2/2); i++){
        if (num2 % i == 0){
            soma2 += i;
        }
    }
    if ((soma1 == num2) && (soma2 == num1)){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int num1, num2;

    printf("Digite o numero 1: ");
    scanf("%d", &num1);
    printf("Digite o numero 2: ");
    scanf("%d", &num2);

    if (amigos(num1, num2)){
        printf("Sao amigos\n");
    }
    else{
        printf("Nao sao amigos\n");
    }
    return 0;
}
