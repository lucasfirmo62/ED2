#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "implementacao.h"

int main(){

	clock_t t;

	int n = 1000;
	int seed = 42;

    int* v;

    v = random_vector_unique_elems(n, 42);


    printf("SelectionMinK\n");


    embaralhar(v, 0, 9);

    //print(v, n);

    t = clock();

    int smk = SelectionMinK(v, 9, 5);

    t = clock() - t;

    //print(v, n);

    printf("A execução durou: %f\n segundos", (float)t/(CLOCKS_PER_SEC));

    printf("SelectionMinK: %d\n", smk);



	
	printf("QuickMinK\n");

    embaralhar(v, 0, 9);

    //print(v, n);

    t = clock();

    int qmk = QuickMinK(v, 0, 9, 5);

    t = clock() - t;

    //print(v, n);

    printf("A execução durou: %f\n segundos", (float)t/(CLOCKS_PER_SEC));

    printf("QuickMinK: %d\n", qmk);


}