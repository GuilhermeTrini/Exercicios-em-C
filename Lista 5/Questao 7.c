#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct planoDeSaude{
    char nomeDoPlano[21];
    int numPacientes;
};
typedef struct planoDeSaude PlanoDeSaude;

struct paciente{
    char nome[51];
    int idade;
    char plano[21];
};
typedef struct paciente Paciente;

Paciente* criaNovoPaciente(char nome[], int idade, char plano[])
{
    Paciente *pacienteNew;
    pacienteNew = (Paciente*) malloc (sizeof(Paciente));
    if (pacienteNew == NULL){
        printf("Erro de alocacao de memoria");
        return NULL;
    }
    strcpy(pacienteNew->nome, nome);
    pacienteNew->idade = idade;
    strcpy(pacienteNew->plano, plano);
    return pacienteNew;
}

int processaCadastroDosPlanos(PlanoDeSaude planos[], int numPlanos, Paciente paciente[], int numPacientes)
{
    int count = 0;
    for (int i = 0; i < numPlanos; i++){
        for (int j = 0; j < numPacientes; j++){
            if (strcmp(planos[i].nomeDoPlano, paciente[j].plano) == 0){
                planos[i].numPacientes++;
                count++;
            }
        }
    }
    if (count == numPacientes){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int i;
    PlanoDeSaude planos[] = {{"Amil", 0},{"SulAmerica", 0},{"Unimed", 0},{"GoldenC", 0}};
    Paciente pacientes[] = {{"Ana", 50, "Amil"}, {"Paulo", 55, "Amil"},{"Abdala", 30, "PlanoX"},{"Beatrice", 51, "SulAmerica"},
    {"Braz", 18, "GoldenC"},{"Fred", 75,"Unimed"},{"Cid", 80, "SulAmerica"},{"Maria", 30, "SulAmerica"},
    {"Ada", 15,"Unimed"},{"Carlos", 70 ,"Unimed"}};


    if (processaCadastroDosPlanos(planos, 4, pacientes, 10) == 0){
        printf("Atencao: Existem pacientes com planos desconhecidos!\n\n");
    }
    printf("Total de pacientes por plano:\n");
    for (i = 0; i < 4; i++)
    {
        printf("%s - Total: %d\n", planos[i].nomeDoPlano, planos[i].numPacientes);
    }
    /* Aqui é o codigo colocando os valores dos pacientes um por um.
    Paciente *pacientes[];
    for (int i = 0; i < quantPacientes; i++){
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        printf("Idade: ");
        scanf(" %d", &idade);
        printf("Plano: ");
        scanf(" %[^\n]", plano);
        pacientes[i] = criaNovoPaciente(nome, idade, plano);
        printf("Paciente: %s\nIdade: %d\nPlano: %s\n", pacientes[i]->nome, pacientes[i]->idade, pacientes[i]->plano);
    }
    for (int i = 0; i < quantPacientes; i++){
        free(pacientes[i]);
    }
    */

    return 0;
}
