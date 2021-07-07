#include <stdio.h>

void start(int* v){

        v[0] = 6;
        v[1] = 0;
        v[2] = 4;
        v[3] = 2;
        v[4] = 5;
        v[5] = 3;
    
}

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

int main(){
    
    int* v;

    v = (int*) malloc(6 * sizeof(int));

    start(v);

    for(int i = 0; i < 6; i++){
        printf("%d", v[i]);
    }
    printf("\n");
    
    quicksort(v, 0, 6);
    
    for(int i = 0; i < 6; i++){
        printf("%d", v[i]);
    }
    printf("\n");

}