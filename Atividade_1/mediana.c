#include "mediana.h"
#include "radomizado.h"

void changeMedianThree(int* v, int i, int j){

    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;

}

int partitionMedianThree(int* v, int p, int r){

    int first, half, last, aux;
    first = v[p];
    half = (p+r)/2;
    last = v[r];

    if(first < half){
        if(half < last){
            aux = half;
        }else{
            if(first < last){
                aux = last;
            }else{
                aux = first;
            }
        }
    }else{
        if(last < half){
            aux = half;
        }else{
            if(last < first){
                aux = last;
            }else{
                aux = first;
            }
        }
    }

    changeMedianThree(v, aux, r);

    int x;
    int i, j;

    x = v[r];
    i = p-1;

    for(j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            changeMedianThree(v ,i, j);
        }
    }

    changeMedianThree(v, i+1, r);

    return i+1;

}

void quicksortMedianThree(int* v, int l, int r){
    int qs;

    if(l < r){
        qs = partitionMedianThree(v, l, r);
        quicksortMedianThree(v, l, qs-1);
        quicksortMedianThree(v, qs+1, r);
    }
}