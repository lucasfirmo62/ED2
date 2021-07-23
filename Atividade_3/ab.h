#ifndef __AB_H__
#define __AB_H__

typedef struct AB{
    struct AB *esq;
    struct AB *dir;
    int dado;
    int* no;
} AB;

AB* AB_Criar(int dado, AB *esq, AB *dir);
void AB_Destruir(AB* A);
AB* AB_Busca(AB *A, int dado);
void AB_inserir(AB **A, int dado);
void AB_imprimir(AB *A);
void AB_remove(AB **A, int dado);
void ABB_Sort(int* v, int n);
void ABB_Sort_R(AB* A, int* v, int* count);

#endif