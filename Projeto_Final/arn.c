#include "arn.h"

static ARN* ARN_Criar(char chave[50], char valor[50]){
    ARN* a;

    a = (ARN*) malloc(sizeof(ARN));
    strcpy(a->chave, chave);

    a->lista = criar();
    inserir(a->lista, valor);

    a->cor = RUBRO;
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

static inline int vermelho(ARN *A){
    if(A == NULL){
        return 0;
    }

    return A->cor == RUBRO ? 1 : 0;
}

static void inverter(ARN* A){
    A->cor = RUBRO;
    A->esq->cor = NEGRO;
    A->dir->cor = NEGRO;
}

static void rot_esq(ARN **A){
    ARN *h, *x;
    h = *A;
    x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = RUBRO;
    *A = x;
}

static void rot_dir(ARN **A){
    ARN *h, *x;
    h = *A;
    x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = RUBRO;
    *A = x;
}

static void ARN_inserir_R(ARN **A, char chave[50], char valor[50]){

    if((*A) == NULL){
        *A = ARN_Criar(chave, valor);
        return;
    }

    if(strcmp(chave, (*A)->chave) == 0){
        inserir((*A)->lista, valor);
    }else{

        if(strcmp(chave, (*A)->chave) < 0){
            ARN_inserir_R(&(*A)->esq, chave, valor);
        }

        if(strcmp(chave, (*A)->chave) > 0){
            ARN_inserir_R(&(*A)->dir, chave, valor);
        }

        if(vermelho((*A)->dir) && !vermelho((*A)->esq)){
            rot_esq(A);
        }

        if(vermelho((*A)->esq) && vermelho((*A)->esq->esq)){
            rot_dir(A);
        }

        if(vermelho((*A)->esq) && vermelho((*A)->dir)){
            inverter(*A);
        }
    }

}

void ARN_inserir(ARN **A, char valor[50]){

    int count = strlen(valor);
    char chave[count];

    strcpy(chave, valor);

    bubble_sort(chave);

        ARN_inserir_R(A, chave, valor);
        (*A)->cor = NEGRO;

}

void buscar(ARN *A, char chave[50]){

    if(A == NULL){
        return;
    }

    if(strcmp(chave, A->chave) == 0){
        lista_imprimir(A->lista);
    }

    if(strcmp(chave, A->chave) < 0){
        buscar(A->esq, chave);
    }

    if(strcmp(chave, A->chave) > 0){
        buscar(A->dir, chave);
    }

}

void destrutor(ARN* A){
    free(A);
}