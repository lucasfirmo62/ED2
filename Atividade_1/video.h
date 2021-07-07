#include <stdio.h>
#include <stdlib.h>

void print(int* v, int n);
void change(int* v, int i, int j);
int* random_vector(int n, int max, int seed);
int partition(int* v, int p, int r);
void quicksort(int* v, int l, int r);