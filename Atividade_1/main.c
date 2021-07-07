#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "radomizado.h"
#include "mediana.h"
#include "video.h"

void print(int* v, int n){

    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
    }
    printf("\n");
    
}

void deallocate(int* v, int n){
    for(int i = 0; i < n; i++){
        free(&v[i]);
    }
}

int* random_vector(int n, int max, int seed){

    int* v = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        v[i] = seed + (rand()%max+1);
    }

    return v;
}

int main(){

    int seed = 0;
    int max = 10;
    int n = 100;

    int* v;

    printf("\nQuickSort video\n");
    v = random_vector(n, max, seed);
    printf("\nDesordenado\n");
    print(v, n);
    clock_t t;
    quicksort(v, seed, n);
    t = clock() - t;
    printf("\n%lu", t);
    printf("\nOrdenado\n");
    print(v, n);
    
    int* v1;

    printf("\nQuickSort radomizado\n");
    v1 = random_vector(n, max, seed);
    printf("\nDesordenado\n");
    print(v1, n);
    clock_t t1;
    quicksortRandon(v1, seed, n);
    t1 = clock() - t1;
    printf("\n%lu", t1);
    printf("\nOrdenado\n");
    print(v1, n);

    int* v2;

    printf("\nQuickSort mediana de 3\n");
    v2 = random_vector(n, max, seed);
    printf("\nDesordenado\n");
    print(v2, n);
    clock_t t2;
    quicksortMedianThree(v2, seed, n);
    t2 = clock() - t2;
    printf("\n%lu", t2);
    printf("\nOrdenado\n");
    print(v2, n);

}