#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arn.h"

ARN* arquivo(ARN *A){

    FILE* arquivo;

    arquivo = fopen("br.txt","r");
      if (arquivo == NULL){
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }

    int count = 0;
    char* v = (char*) malloc(sizeof(char));
    char c;

    do{
        c = fgetc(arquivo);

        if((c > 64) && (c < 91)){
            c += 32;
        }

        if((c == '\n') || (c == EOF)){
            ARN_inserir(&A, v);

            count = 0;
            free(v);
            v = (char*) malloc(sizeof(char));
        }else{
            v[count] = c;
            count++;
        }

    }while (c != EOF);

    return A;

    fclose(arquivo);

}

void bubble_sort(char palavra[50]){

    char aux;
    for(int i = 0; i < strlen(palavra); i++){
        for(int j = 0; j < strlen(palavra); j++){
            if(palavra[i] < palavra[j]){
                aux = palavra[i];
                palavra[i] = palavra[j];
                palavra[j] = aux;
            }
        }
    }
}

void recebe_palavra(ARN* A, char palavra[50]){

    int count = strlen(palavra);

    for(int i = 0; i < count; i++){
        if((palavra[i] > 64) && (palavra[i] < 91)){
            palavra[i] += 32;
        }
    }

    bubble_sort(palavra);

    printf("Chave a ser procurada é %s", palavra);

    printf("\n");

    buscar(A, palavra);
}