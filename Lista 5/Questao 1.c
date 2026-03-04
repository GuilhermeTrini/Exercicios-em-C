#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    int matricula;
    int media;
};

int maiorMedia(int n, struct Aluno turma[n])
{
    int maiorMed = turma[0].media;
    for (int i = 0; i < n; i++){
        if (maiorMed < turma[i].media){
            maiorMed = turma[i].media;
        }
    }
    return maiorMed;
}

int main()
{
    int n, maior, count = 0;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    struct Aluno turma[n];

    for (int i = 0; i < n; i++){
        printf("Digite a matricula e a media do aluno: ");
        scanf("%d %d", &turma[i].matricula, &turma[i].media);
    }
    maior = maiorMedia(n, turma);
    for (int i = 0; i < n; i++){
        if (maior == turma[i].media){
            printf("%d\n", turma[i].matricula);
            count++;
        }
    }
    printf("Quantidade de aluno premiado: %d\n", count);
    return 0;
}
