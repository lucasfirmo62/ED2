#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
	char palavra[50];
	struct no *ant;
	struct no *prox;

}No;

typedef struct lista{
	int quantidade;

	struct No* proximo;
	struct No* inicio;
	struct No* fim;

}Lista;

Lista* criar();

No* criar_no(char palavra[50]);

void inserir(Lista* l, char str[50]);

void lista_imprimir(Lista* l);