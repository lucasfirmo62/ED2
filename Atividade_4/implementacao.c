#include <stdio.h>
#include "implementacao.h"

void print(int* v, int n){
	for(int i = 0; i < n; i++){
        printf(" %d ", v[i]);
    }
    printf("\n");
}


void troca(int* v, int i, int j){
  int aux;
  aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

void embaralhar(int *v, int ini, int fim){
    int i, j;
    for(i = fim-1; i > ini; i--){
        j = (rand() % (i + 1));
        j = j <= ini? ini+1 : j;
        troca(v, i, j);
    }
}

int* random_vector_unique_elems(int n, int seed){
 	int* v = (int*) calloc(n, sizeof(int));


  	for(int i = 0; i < n; i++){
		v[i] = rand() % n;
	}

	embaralhar(v, 0, n);

	return v;
}