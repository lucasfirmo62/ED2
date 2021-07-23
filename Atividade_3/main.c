
#include <stdio.h>
#include "ab.h"
#include "arn.h"
#define N 500000

void aleatorio(int* v, int n){
    for(int i = 0; i < n; i++){
        v[i] = rand() % N;
    }
}


int main(){

    int vv[N];

    printf("\nTeste ABB\n");

    ABB_Sort(vv, N);

    int v[N];

    printf("Teste ARN\n");

    aleatorio(v, N);

    ARN_Sort(v, N);

}