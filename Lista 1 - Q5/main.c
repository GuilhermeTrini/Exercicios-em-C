#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Aviso: todas as letras estão contidas no mesmo código, de forma que é necessário passar pelas 3 para
verificar a funcionalidade de cada uma.
*/

typedef struct funcionario{
    char nome[50];
    float valor_hora;
    int horas_mes;
}Funcionario;

void ordem_alfabetica_func(int tam, Funcionario *vf)
{
    int menor;
    Funcionario aux;
    for (int i = 0; i < tam - 1; i++){
        menor = i;
        for (int j = i + 1; j < tam; j++){
            if (strcmp(vf[j].nome, vf[menor].nome) < 0){
                menor = j;
            }
        }
        if (i != menor){
            aux = vf[menor];
            vf[menor] = vf[i];
            vf[i] = aux;
        }
    }
}

Funcionario *busca_func(int n, Funcionario *vf, char *nome)
{
    int inicio = 0;
    int fim = n - 1;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (strcmp(vf[meio].nome, nome) == 0){
            return &vf[meio];
        }
        else if (strcmp(vf[meio].nome, nome) > 0){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    return NULL;
}

void exibe_top3_salarios(int n, Funcionario *vf)
{
    int j;
    for (int i = 1; i < n; i++){
        Funcionario atual = vf[i];
        float salarioi = vf[i].horas_mes * vf[i].valor_hora;
        j = i - 1;
        float salarioj = vf[j].horas_mes * vf[j].valor_hora;
        while (j >= 0 && salarioi > salarioj){
            vf[j + 1] = vf[j];
            j--;
            if (j >= 0){
                salarioj = vf[j].horas_mes * vf[j].valor_hora;
            }
        }
        vf[j + 1] = atual;
    }
    printf("Top 3 salarios dos funcionarios: \n");
    for (int i = 0; i < 3; i++){
        printf("%s\n", vf[i].nome);
    }
}

int main()
{
    int tam = 5;
    Funcionario *funcionario;
    funcionario = (Funcionario*)malloc(tam*sizeof(Funcionario));
    if (funcionario == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    printf("Entrando com os 5 funcionarios no vetor: \n");
    for (int i = 0; i < tam; i++){
        printf("Digite o nome do funcionario: ");
        scanf(" %[^\n]", funcionario[i].nome);
        printf("Digite o valor por hora que o funcionario ganha: ");
        scanf(" %f", &funcionario[i].valor_hora);
        printf("Digite quantas horas por mes o funcionario trabalhou: ");
        scanf(" %d", &funcionario[i].horas_mes);
    }
    printf("Funcionarios ordenados em ordem alfabetica: \n");
    ordem_alfabetica_func(tam, funcionario);
    for (int i = 0; i < tam; i++){
        printf("%s\n", funcionario[i].nome);
    }

    printf("\nBuscar funcionario usando busca binaria: \n\n");
    char nome[50];
    printf("Digite o nome do funcionario que deseja encontrar: ");
    scanf(" %[^\n]", nome);
    Funcionario *func = busca_func(tam, funcionario, nome);
    if (func == NULL){
        printf("Funcionario nao encontrado");
    }
    else{
        printf("Funcionario encontrado:\nNome: %s\nValor ganho por hora: %.2f\nHoras trabalhadas: %d\n\n", func->nome, func->valor_hora, func->horas_mes);
    }
    exibe_top3_salarios(tam, funcionario);

}
