#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
	RUBRO, NEGRO
} Cor;

typedef struct ARN{
	struct ARN *esq;
	struct ARN *dir;
	int dado;
	int valor;
	Cor cor;
}ARN;

void ARN_imprimir(ARN *A);
void ARN_inserir_R(ARN **A, int dado, int valor);
void ARN_inserir(ARN **A, int dado, int valor);
static ARN* ARN_Criar(int dado, int valor);
static inline int vermelho(ARN *A);
static void inverter(ARN* A);
static void rot_esq(ARN **A);
static void rot_dir(ARN **A);
void ARN_Sort(int* v, int n);
void zerar_vetor(int* v, int n);
void ARN_Sort_R(ARN* A, int* v, int* count);
void destrutor(ARN* A);
void print_vetor(int* v, int n);