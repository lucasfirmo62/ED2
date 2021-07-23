#include "ab.h"
#include "arn.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define CLOCKS_PER_SEC 1000000

#define N 100


AB* AB_Criar(int dado, AB* esq, AB* dir){
    AB* a;
    
    a = malloc(sizeof(AB));
    a->dado = dado;
    a->esq = esq;
    a->dir = dir;

    return a;
}

AB* AB_Busca(AB *A, int dado){

    if(A == NULL){
        return NULL;
    }else if(A->dado == dado){
        return A;
    }else if(dado < A->dado){
        return AB_Busca(A->esq, dado);
    }else{
        return AB_Busca(A->dir, dado);
    }
}

void AB_inserir(AB **A, int dado){
    if((*A) == NULL){
        *A = AB_Criar(dado, NULL, NULL);
    }else{
        if(dado < (*A)->dado){
            AB_inserir(&(*A)->esq, dado);
        }else{
            AB_inserir(&(*A)->dir, dado);
        }
    }

}


void AB_Destruir(AB* A){
    if(A == NULL)
        return;
    AB_Destruir(A->esq);
    AB_Destruir(A->dir);
    free(A);
}

void AB_imprimir(AB* A){

    if(A == NULL){
        return;
    }else{
        printf("%d\n", A->dado);
        if(A->dir != NULL){
            printf("%d\n\\", A->dado);
            printf("(d)");
            AB_imprimir(A->dir);
        }if(A->esq != NULL){
            printf("%d\n/", A->dado);
            printf("(e)");
            AB_imprimir(A->esq);
        }
    }
}

void AB_remove(AB **A, int dado){

    AB* no = AB_Busca(*A, dado);

    if(no->esq == NULL && no->dir == NULL){
        no->dado = NULL;
        free(no);
        return;
    }else{
        if((no->esq != NULL) && (no->dir == NULL)){
            no->dado = no->esq->dado;
            no->esq = NULL;
            return;
        }else if((no->esq == NULL) && (no->dir != NULL)){
            no->dado = no->dir->dado;
            no->dir = NULL;
            return;
        }else if((no->esq != NULL) && (no->dir != NULL)){
            no->dado = no->esq->dado;
            no->esq->dado = NULL;
            return;
        }
        free(no);
    }

    return;

}

void ABB_Sort_R(AB* A, int* v, int* count){

    if(A == NULL){
        return;
    }

    if(A->esq != NULL){
        v[*count] = A->esq->dado;
        *count += 1;
        ABB_Sort_R(A->esq, v, count);
    }
    if(A->dir != NULL){
        v[*count] = A->dir->dado;
        *count += 1;
        ABB_Sort_R(A->dir, v, count);
    }

}


void ABB_Sort(int* v, int n){

    clock_t t;

    int* count = 0;

    AB* A = NULL;

    if(n == 0){
        return;
    }

    //print_vetor(v, n);

    for(int i = 0; i < n; i++){
        AB_inserir(&A, v[i]);
    }

    //zerar_vetor(v, n);
    //print_vetor(v, n);

    t = clock();

    ABB_Sort_R(A, v, &count);

    t = clock() - t;

    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/100)));

    //print_vetor(v, n);

    destrutor(A);

}