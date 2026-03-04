#include "arv.c"
#include <stdio.h>

int main(void) {
  Arvore arv;
  criar(&arv);
  Arvore arv2;
  criar(&arv2);

  insere(&arv, 9);
  insere(&arv, 5);
  insere(&arv, 14);
  insere(&arv, 2);
  insere(&arv, 6);
  insere(&arv, 12);
  insere(&arv, 18);
  insere(&arv, 1);

  insere(&arv, 3);
  insere(&arv, 7);
  insere(&arv, 17);

  printf("In-ordem: \n");
  exibir(arv.raiz);
  printf("\nIn-ordem de numeros pares: \n");
  exibir_pares(arv.raiz);
  printf("\nA arvore tem %d folhas!\n", folhas(&arv));

  return 0;
}
