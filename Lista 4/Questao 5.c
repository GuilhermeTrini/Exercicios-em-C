#include <stdio.h>

void menorValorDiag(int m, int n, int mat[m][n], int *menor, int *l, int *c)
{
    for (int i = 0; i < m; i++){
        if ((*menor > mat[i][i]) || *menor == -1){
            *menor = mat[i][i];
            *l = i + 1;
            *c = i + 1;
        }
    }
}

int main()
{
    int m, n, menorValor = -1, linha, coluna, *menor, *l, *c;

    printf("Digite a quantidade de linhas e colunas para a matriz (exemplo: linha coluna): ");
    scanf("%d %d", &m, &n);
    int mat[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Digite os valores da linha %d e coluna %d: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
    l = &linha;
    c = &coluna;
    menor = &menorValor;

    menorValorDiag(m, n, mat, menor, l, c);
    printf("O menor elemento da diagonal principal: %d\nNa linha %d e coluna %d\n", menorValor, linha, coluna);
}
