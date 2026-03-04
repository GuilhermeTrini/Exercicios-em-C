#include <stdio.h>
#include <stdlib.h>
#include "listaduen.c"
/*
1
Esquerda
20
1
Direita
15
1
Cima
10


*/
int main()
{
    int option = 0;
    ListaTrecho *percurso = (ListaTrecho*)malloc(sizeof(ListaTrecho));
    if (percurso == NULL){
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    criaPercurso(percurso);
    while (option != 6){
        printf("\n-------- Bem-vindo ao Montador de Percurso --------\n1 - Inserir trecho\n2 - Remover trecho\n3 - Atualiza dado do trecho\n4 - Exibe percurso\n5 - Exibir apenas um trecho\n6 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &option);
        switch (option){
            case 1:
                {
                TipoTrecho trecho;
                printf("Digite a direcao do trecho: ");
                scanf(" %[^\n]", trecho.direcao);
                printf("Digite a distancia do trecho: ");
                scanf("%f", &trecho.distancia);
                if (inserirTrecho(percurso, trecho) == 1){
                    printf("\nTrecho inserido com sucesso!\n");
                }else{
                    printf("\nErro na insercao do trecho!\n");
                    }
                }
               break;
            case 2:
                {
                int idTrecho;
                printf("Digite o id do trecho que deseja remover: ");
                scanf("%d", &idTrecho);
                if (removerTrecho(percurso, idTrecho) == 1){
                    printf("\nTrecho removido com sucesso!\n");
                }else{
                    printf("\nErro na remocao de trecho!\n");
                    }
                }
                break;
            case 3:
                {
                TipoTrecho trecho;
                printf("Digite o id do trecho que deseja atualizar: ");
                scanf("%d", &trecho.idTrecho);
                printf("Digite a nova direcao: ");
                scanf(" %[^\n]", trecho.direcao);
                printf("Digite a nova distancia: ");
                scanf("%f", &trecho.distancia);
                if (atualizaTrecho(percurso, trecho) == 1){
                    printf("\nTrecho atualizado com sucesso!\n");
                }else{
                    printf("\nErro na atualizacao de trecho!\n");
                    }
                }
                break;
            case 4:
                {
                exibirPercurso(percurso);
                }
                break;
            case 5:
                {
                int idTrecho;
                printf("Digite o id do trecho que deseja exibir: ");
                scanf("%d", &idTrecho);
                filtrarTrecho(percurso, idTrecho);
                }
                break;
        }
    }
}
