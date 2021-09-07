#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <windows.h>

struct T_lista {
  char nome[50]; //P pernson name
  char telefone[20]; //person's phone
  int idade; // person's age
  struct T_lista * prox;
  struct T_lista * ant;
};

typedef struct T_lista lista;

lista * inicio = NULL;
lista * atual = NULL;

/*================================= INITIALIZES =================================*/

void inicializa() {
  inicio = (lista * ) malloc(sizeof(lista));
  if (!inicio) {
    printf("\n There is no memory space \n");
  }
  inicio -> ant = NULL;
  inicio -> prox = NULL;
  atual = inicio;
}

/*================================= INITIALIZES =================================*/

/*================================= INSERT =================================*/

void insere() {
  lista * novo = NULL;
  novo = (lista * ) malloc(sizeof(lista));
  if (!novo) {
    printf("No space\n");
    exit(1);
  }
  printf("Type your name\n");
  scanf("%s", novo -> nome);
  printf("enter your age\n");
  scanf("%d", & novo -> idade);
  printf("enter your phone\n");
  scanf("%s", novo -> telefone);
  novo -> ant = atual;
  novo -> prox = NULL;
  atual -> prox = novo;
  atual = novo;
}

/*================================= INSERT =================================*/

/*================================= PRINT =================================*/

void imprime() {
  if (inicio -> prox == NULL) {
    printf("Empty\n");
  } else {
    atual = inicio;
    do {
      atual = atual -> prox;
      printf("---------------------------");
      printf("\n Persons name: %s \n", atual -> nome);
      printf("\n Age %d \n", atual -> idade);
      printf("\n Phone %s \n", atual -> telefone);
      printf("---------------------------\n");
    }
    while (atual -> prox != NULL);
  }

}

/*================================= PRINT =================================*/

/*================================= SEARCH =================================*/

void busca() {
  int encontrou;
  char nome_buscado[50];
  encontrou = 0;
  printf("Enter a name to be searched \n");
  scanf("%s", nome_buscado);
  if (inicio -> prox == NULL) {
    printf("Empty list\n");
  } else {
    for (atual = inicio -> prox; atual != NULL; atual = atual -> prox) {
      if (strcmp(nome_buscado, atual -> nome) == 0) {
        printf("Name: %s \n", atual -> nome);
        printf("Age: %d \n", atual -> idade);
        printf("Phone: %s \n", atual -> telefone);
        encontrou++;
      }
      if ((atual -> prox == NULL) && (encontrou == 0)) {
        printf("Value not found\n");
        break;
      }
      if (atual -> prox == NULL) {
        break;
      }
    }
  }
}

/*================================= SEARCH =================================*/

/*================================= REMOVE =================================*/

void exclui() {
  int encontrou;
  char nome_buscado[50];
  encontrou = 0;
  printf("Enter a name to be searched \n");
  scanf("%s", nome_buscado);
  if (inicio -> prox == NULL) {
    printf("empty list\n");
  } else {
    for (atual = inicio -> prox; atual != NULL; atual = atual -> prox) {
      if (strcmp(nome_buscado, atual -> nome) == 0) {
        encontrou++;
        if (atual -> prox == NULL) {
          atual -> ant -> prox = NULL;
          free(atual);
          atual = inicio;
        } else {
          atual -> ant -> prox = atual -> prox;
          atual -> prox = atual -> ant;
          free(atual);
          atual = inicio;
        }
      }
      if ((atual -> prox == NULL) && (encontrou == 0)) {
        printf("Value not found\n");
        break;
      }
      if (atual -> prox == NULL) {
        break;
      }
    }
  }
  printf("Individual successfully deleted \n");
}

/*================================= REMOVE =================================*/

/*================================= MENU =================================*/

void menu() {
  int opcao;
  do {
    printf(" \n \n \n \n \n \n ");
    printf("			  **** MENU ****");
    printf(" \n \n \n ");
    printf("\n - option 1: Insert student\n");
    printf("\n - option 2: Find student \n");
    printf("\n - option 3: Delete student \n");
    printf("\n - option 4: Show students \n");
    printf("\n - option 0: exit \n");
    printf("\n \n Enter an option ");
    printf(" \n \n \n \n \n");
    scanf("%d", & opcao);
    switch (opcao) {
    case 1:
      insere();
      break;
    case 2:
      busca();
      break;
    case 3:
      exclui();
      break;
    case 4:
      imprime();
      break;
    case 0:
      exit(0);
      break;
    default:
      printf(" # Incorrect option # \n");
      Sleep(3);
    }
  }
  while (opcao != 0);
}

/*================================= MENU =================================*/

main() {
  inicializa();
  menu();
}