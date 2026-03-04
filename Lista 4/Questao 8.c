#include <stdio.h>

int contaAcertos(char gabOficial[], char gabAluno[])
{
    int count = 0;
    for (int i = 0; i < 10; i++){
        if (gabOficial[i] == gabAluno[i]){
            count++;
        }
    }
    return count;
}

int main()
{
    char gabOficial[11], aluno[20], gabAluno[11], melhorAluno[20];
    int quantAluno, maiorNota = 0, quantAcertos = 0;
    printf("Digite o gabarito oficial: ");
    scanf("%s", gabOficial);
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantAluno);

    while (quantAluno > 0){
        quantAluno--;
        printf("Digite o nome do aluno sem espaços: ");
        scanf("%s", aluno);
        printf("Digite o gabarito desse aluno: ");
        scanf("%s", gabAluno);
        quantAcertos = contaAcertos(gabOficial, gabAluno);
        printf("%s tirou nota %d.\n", aluno, quantAcertos);

        if (maiorNota < quantAcertos){
            int i;
            maiorNota = quantAcertos;
            for (i = 0; aluno[i] != '\0'; i++){
                melhorAluno[i] = aluno[i];
            }
            melhorAluno[i] = '\0';
        }
    }
    printf("%s tirou a melhor nota.\n", melhorAluno);
}
