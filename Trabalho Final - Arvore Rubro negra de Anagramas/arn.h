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

void ARN_imprimir(ARN *A, int linha);
void ARN_inserir_R(ARN **A, char chave[50], char valor[50]);
void ARN_inserir(ARN **A, char valor[50]);
static ARN* ARN_Criar(char chave[50], char valor[50]);
static inline int vermelho(ARN *A);
static void inverter(ARN* A);
static void rot_esq(ARN **A);
static void rot_dir(ARN **A);
void ARN_Sort(char v[300000][50], int n);
void zerar_vetor(int* v, int n);
void ARN_Sort_R(ARN* A, int* v, int* count);
void destrutor(ARN* A);
void print_vetor(int* v, int n);