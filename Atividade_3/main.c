#include <stdio.h>
#include "ab.h"
#include "arn.h"
#define N 8


int main(){

    printf("Teste ARN\n");

    int v[] = {8,12,6,14,4,30,2,10};

    ARN_Sort(v, N);

    printf("\nTeste ABB\n");

    int vv[] = {8,12,6,14,4,30,2,10};

    ABB_Sort(vv, N);

}
