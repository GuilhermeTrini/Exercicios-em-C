#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"

int main()
{

    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL){
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    cria(pilha);
    char exp[20];
    while(1){
        printf("Digite a expressao: ");
        scanf(" %[^\n]", exp);
        if (strcmp(exp, "sair") == 0){
            break;
        }
        int valida = 1;
        for (int i = 0; exp[i] != '\0'; i++){
            char c = exp[i];
            if (c == '(' || c == '[' || c == '{'){
                empilha (pilha, c);
            }
            else if (c == ')' || c == ']' || c == '}'){
                if (vazia(pilha)){
                    valida = 0;
                    break;
                }else{
                    char topo = desempilha(pilha);
                    if (topo == '(' && c != ')' || topo == '[' && c != ']' || topo == '{' && c != '}'){
                        valida = 0;
                        break;
                    }
                }
            }
        }
        if (vazia(pilha) != 1){
        valida = 0;
        }
        if (valida != 0){
            printf("Valida\n");
        }else{
            printf("Invalida\n");
        }
        printf("Digite sair para encerrar\n");
    }

}
