#include <stdio.h>
#include <stdlib.h>
#include "arn.h"

int main(int argc, char *argv[]){

    ARN *A = NULL;

    printf("Inserindo...\n");
    A = arquivo(A);
    printf("Inserção completa.\n");
    
    recebe_palavra(A, argv[1]);

    destrutor(A);
}