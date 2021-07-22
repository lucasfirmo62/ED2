#include "ab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

