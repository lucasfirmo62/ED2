#include "labirinto.h"

int inicializador(int m[N][N], int posI, int posJ){

    if((posI == N) || (posJ == N)){
        finalizador();
    }else if(m[posI == 1][posJ]){
        posJ++;
        posI = 0;
        inicializador(m, posI, posJ);
    }else{
        imprimir(posI, posJ);
        posI++;
        inicializador(m, posI, posJ);
    }
    return 0;
}

void finalizador(){
    printf("\nSainda encontrada\n");
}

void imprimir(int posI, int posJ){
    printf("\n%dx%d", posI, posJ);
}