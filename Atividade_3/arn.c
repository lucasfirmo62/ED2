#include "arn.h"

static ARN* ARN_Criar(int dado, int valor){
    ARN* a;
    
    a = malloc(sizeof(ARN));
    a->dado = dado;
    a->valor = valor;
    a->cor = VERMELHA;
    a->esq = NULL;
    a->dir = NULL;

    return a;
}

static inline int vermelho(ARN *A){
    if(A == NULL){
        return 0;
    }

    return A->cor == VERMELHA ? 1 : 0;
}

static void inverter(ARN* A){
    A->cor = VERMELHA;
    A->esq->cor = PRETA;
    A->dir->cor = PRETA;
}

static void rot_esq(ARN **A){
    ARN *h, *x;
    h = *A;
    x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = VERMELHA;
    *A = x;
}

static void rot_dir(ARN **A){
    ARN *h, *x;
    h = *A;
    x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = VERMELHA;
    *A = x;
}


void ARN_inserir_R(ARN **A, int dado, int valor){
    if((*A) == NULL){
        *A = ARN_Criar(dado, valor);
        return;
    }
    
    if(dado < (*A)->dado){
        ARN_inserir_R(&(*A)->esq, dado, valor);
    }

    if(dado > (*A)->dado){
        ARN_inserir_R(&(*A)->dir, dado, valor);
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

void ARN_inserir(ARN **A, int dado, int valor){
    ARN_inserir_R(A, dado, valor);
    (*A)->cor = PRETA;
}

void ARN_imprimir(ARN *A){
    printf("%d\n", A->dado);
    if(A->dir != NULL){
        printf("\\\n");
        if((A->dir->cor) == VERMELHA){
            printf("%d(v)\n", A->dado);
        }if((A->dir->cor) == PRETA){
            printf("%d(p)\n", A->dado);
        }
        ARN_imprimir(A->dir);
    }if(A->esq != NULL){
        printf("/\n");
        if((A->esq->cor) == VERMELHA){
            printf("%d(v)\n", A->dado);
        }if((A->esq->cor) == PRETA){
            printf("%d(p)\n", A->dado);
        }
        ARN_imprimir(A->esq);
    }
    printf("\n");
}

void ARN_Sort(ARN* A, int* v, int n, int count){

    if(n == 0){
        return;
    }
        int dado;
        dado = v[count];
        printf("valor de dado: %d\n", dado);

        ARN_inserir(&A, dado, 0);
        ARN_imprimir(A);
        printf("valor de n: %d\n", n);
        printf("valor de count: %d\n", count);

        n--;
        count++;
        ARN_Sort(A, v, n, count);

}



