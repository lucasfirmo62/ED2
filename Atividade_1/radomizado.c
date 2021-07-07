#include "radomizado.h"

void changeRandom(int* v, int i, int j){

    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

}

int partitionRandon(int* v, int p, int r){
    int x;
    int i, j;

    int random;

    random = p + rand()%r;

    x = v[random];
    i = p-1;

    for(j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            changeRandom(v ,i, j);
        }
    }

    changeRandom(v, i+1, r);

    return i+1;

}

void quicksortRandon(int* v, int l, int r){
    int qs;

    if(l < r){
        qs = partitionRandon(v, l, r);
        quicksortRandon(v, l, qs-1);
        quicksortRandon(v, qs+1, r);
    }
}