#include <stdio.h>
#include <stdlib.h>
#include "arn.h"

int main(){

    ARN *A = NULL;

    printf("Inserindo...\n");
    A = arquivo(A);
    printf("Inserção completa.\n");
    recebe_palavra(A);

    destrutor(A);
}