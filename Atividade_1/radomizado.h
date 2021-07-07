#include <stdio.h>
#include <stdlib.h>

void print(int* v, int n);
void changeRandom(int* v, int i, int j);
int* random_vector(int n, int max, int seed);
int partitionRandon(int* v, int p, int r);
void quicksortRandon(int* v, int l, int r);