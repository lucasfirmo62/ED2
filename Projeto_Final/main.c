#include <stdio.h>
#include <stdlib.h>
#include "arn.h"
#define L 300000
#define C 50

int main(){

    ARN *A = NULL;

    char vet_string[L][C];

    printf("Inserindo...\n");
    arquivo(vet_string);
    printf("Inserção completa.\n");

    A = ARN_Sort(A, vet_string, L);

    recebe_palavra(A);

    destrutor(A);

}