#include "labirinto.h"

int inicializador(int m[N][N], int posI, int posJ){
    int i = 0;
    int j = 0;

    if((posI == N) || (posJ == N)){
        finalizador();
    }else if(m[0][0 == 1]){
        return 1;
    }else if(m[i+posI][j] == 0){
        posJ = 0;
        posI++;
        printf("\n%dx%d\n", posI, posJ);
        inicializador(m, posI, posJ);
    }else if(m[i][j+posJ]){
        posJ++;
        printf("\n%dx%d\n", posI, posJ);
        inicializador(m, posI, posJ);
    }
    return 0;

}

void finalizador(){
    printf("\nSainda encontrada\n");
}