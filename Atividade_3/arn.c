#include "arn.h"
#define CLOCKS_PER_SEC 1000000
#include <time.h>

static ARN* ARN_Criar(int dado, int valor){
    ARN* a;
    
    a = malloc(sizeof(ARN));
    a->dado = dado;
    a->valor = valor;
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
    (*A)->cor = NEGRO;
}

void ARN_imprimir(ARN *A){
    printf("%d\n", A->dado);
    if(A->dir != NULL){
        printf("\\\n");
        if((A->dir->cor) == RUBRO){
            printf("%d(v)\n", A->dado);
        }if((A->dir->cor) == NEGRO){
            printf("%d(p)\n", A->dado);
        }
        ARN_imprimir(A->dir);
    }if(A->esq != NULL){
        printf("/\n");
        if((A->esq->cor) == RUBRO){
            printf("%d(v)\n", A->dado);
        }if((A->esq->cor) == NEGRO){
            printf("%d(p)\n", A->dado);
        }
        ARN_imprimir(A->esq);
    }
    printf("\n");
}

void zerar_vetor(int* v, int n){
    for (int i = 0; i < n; i++){
        v[i] = 0;
    }
}

void print_vetor(int* v, int n){
    printf("v = [ ");
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("]\n");
}

void ARN_Sort_R(ARN* A, int* v, int* count){
    if(A == NULL){
        return;
    }
    ARN_Sort_R(A->esq ,v, count);
    v[*count] = A->dado;
    *count += 1;
    ARN_Sort_R(A->dir, v, count);
}

void destrutor(ARN* A){
    free(A);
}

void ARN_Sort(int* v, int n){

    clock_t t;

    int* count = 0;

    ARN *A = NULL;

    if(n == 0){
        return;
    }

    //print_vetor(v, n);

    for(int i = 0; i < n; i++){
        ARN_inserir(&A, v[i], 0);
    }
    
    //zerar_vetor(v, n);
    //print_vetor(v, n);

    t = clock();

    ARN_Sort_R(A, v, &count);

    t = clock() - t;

    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/100)));

    //print_vetor(v, n);

    destrutor(A);

}