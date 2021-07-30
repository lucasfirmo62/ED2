#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void change(int* v, int i, int j){

    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

}

int partition(int* v, int p, int r){
    int x;
    int i, j;

    x = v[r];
    i = p-1;

    for(j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            change(v ,i, j);
        }
    }

    change(v, i+1, r);

    return i+1;

}

int QuickMinK(int *v, int e, int d, int k){
    int qs;

    if(e < d){
        qs = partition(v, e, d);
        QuickMinK(v, e, qs-1, k);
        QuickMinK(v, qs+1, d, k);
    }

    int qmk = v[k-1];

    return qmk;
}

int SelectionMinK(int* v,int n, int k){
    
    int i, j, aux, min;
  
    for(i = 0; i < (n - 1); i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        if(i != min){
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
  
    return v[k-1];

}


