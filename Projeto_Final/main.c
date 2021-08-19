#include <stdio.h>
#include <stdlib.h>
#include "arn.h"

int main(int argc, char *argv[]){

    ARN *A = NULL;

    printf("Inserindo...\n");
    A = arquivo(A);
    printf("Inserção completa.\n");

    for(int i = 1; i < argc; i++){
        recebe_palavra(A, argv[i]);
    }

    destrutor(A);

}