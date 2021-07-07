#include "video.h"

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

void quicksort(int* v, int l, int r){
    int qs;

    if(l < r){
        qs = partition(v, l, r);
        quicksort(v, l, qs-1);
        quicksort(v, qs+1, r);
    }
}