#include <stdio.h>

#include <stdlib.h>


struct Node {
  int num;
  struct Node * prox;
};
typedef struct Node node;

void inicia(node * LISTA) {
  LISTA -> prox = NULL;
}

void opcao(node * LISTA, int op) {
  switch (op) {
  case 0:
    libera(LISTA);
    break;

  case 1:
    exibe(LISTA);
    break;

  case 2:
    insereInicio(LISTA);
    break;

  case 3:
    insereFim(LISTA);
    break;

  case 4:
    inicia(LISTA);
    break;

  default:
    printf("Invalid command\n\n");
  }
}

int vazia(node * LISTA) {
  if (LISTA -> prox == NULL)
    return 1;
  else
    return 0;
}

void insereFim(node * LISTA) {
  node * novo = (node * ) malloc(sizeof(node));
  if (!novo) {
    printf("No memory available!\n");
    exit(1);
  }
  printf("New element: ");
  scanf("%d", & novo -> num);
  novo -> prox = NULL;

  if (vazia(LISTA))
    LISTA -> prox = novo;
  else {
    node * tmp = LISTA -> prox;

    while (tmp -> prox != NULL)
      tmp = tmp -> prox;

    tmp -> prox = novo;
  }
}

void insereInicio(node * LISTA) {
  node * novo = (node * ) malloc(sizeof(node));
  if (!novo) {
    printf("No memory available!\n");
    exit(1);
  }
  printf("New element: ");
  scanf("%d", & novo -> num);

  node * oldHead = LISTA -> prox;

  LISTA -> prox = novo;
  novo -> prox = oldHead;
}

void exibe(node * LISTA) {
  if (vazia(LISTA)) {
    printf("Empty list!\n\n");
    return;
  }

  node * tmp;
  tmp = LISTA -> prox;

  while (tmp != NULL) {
    printf("%5d", tmp -> num);
    tmp = tmp -> prox;
  }
  printf("\n\n");
}

void libera(node * LISTA) {
  if (!vazia(LISTA)) {
    node * proxNode,
      * atual;

    atual = LISTA -> prox;
    while (atual != NULL) {
      proxNode = atual -> prox;
      free(atual);
      atual = proxNode;
    }
  }
}

int menu(void) {
  int opt;

  printf("Choose option\n");
  printf("0. Exit\n");
  printf("1. Display list\n");
  printf("2. Add node at start\n");
  printf("3. Add node at the end\n");
  printf("4. Reset list\n");
  printf("Option: ");
  scanf("%d", & opt);
  switch (opt) // switch que define a decisão do usuario //
  {
  case 1:

    exibe( & L);
    break;
  case 2:

    insereInicio( & L);
    break;
  case 3:

    insereFim( & L);
    break;
  case 4:
    Particiona_Merge_Sort(vetor, 0, numero_de_celulas - 1);
    break;
  }
  return opt;
}

int main(void) {
  node * LISTA = (node * ) malloc(sizeof(node));
  if (!LISTA) {
    printf("No memory available!\n");
    exit(1);
  }
  inicia(LISTA);
  int opt;

  do {
    opt = menu();
    opcao(LISTA, opt);
  } while (opt);

  free(LISTA);
  return 0;
}