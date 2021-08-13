#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


typedef enum{
	RUBRO, NEGRO
} Cor;

typedef struct ARN{
	struct ARN *esq;
	struct ARN *dir;
	char chave[50];
	char valor[50];
	Cor cor;
	int qtd_chave;
	Lista* lista;
}ARN;

static void ARN_inserir_R(ARN **A, char chave[50], char valor[50]);
static void ARN_inserir(ARN **A, char valor[50]);
static ARN* ARN_Criar(char chave[50], char valor[50]);
static inline int vermelho(ARN *A);
static void inverter(ARN* A);
static void rot_esq(ARN **A);
static void rot_dir(ARN **A);
ARN* ARN_Sort(ARN* A, char v[300000][50], int n);
void destrutor(ARN* A);
void buscar(ARN *A, char chave[50]);
