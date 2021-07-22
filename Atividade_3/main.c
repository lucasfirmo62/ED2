#include <stdio.h>
#include "ab.h"
#include "arn.h"
#define N 8


int main(){

    ARN* a;
    int count = 0;
    //int* v[] = {(int)'U',(int)'T',(int)'F',(int)'P',(int)'R'};
    int v[] = {8,12,6,14,4,30,2,10};

/*
    ARN_inserir(&a, v[0], 0);
    ARN_inserir(&a, v[1], 0);
    ARN_inserir(&a, v[2], 0);
    ARN_inserir(&a, v[3], 0);
    ARN_inserir(&a, v[4], 0);
    ARN_imprimir(a);*/

    //int v[] = {(int)'U',(int)'T',(int)'F',(int)'P',(int)'R'};


    ARN_Sort(a, v, N, count);
    //ARN_imprimir(v);


   /* AB *ab = NULL;

    printf("\nCaso A)\n\n");

    AB_inserir(&ab, 70);
    AB_inserir(&ab, 39);
    AB_inserir(&ab, 88);
    AB_inserir(&ab, 25);
    AB_inserir(&ab, 90);
    AB_inserir(&ab, 31);
    AB_inserir(&ab, 4);
    AB_inserir(&ab, 10);
    AB_inserir(&ab, 12);
    AB_inserir(&ab, 21);
    AB_inserir(&ab, 20);

    AB_imprimir(ab);

    AB_Destruir(ab);*/


}
