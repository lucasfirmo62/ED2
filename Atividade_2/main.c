#include <stdio.h>
#include "ab.h"

int main(int argc, char** argv){

    AB *ab = NULL;

    printf("\nCaso A)\n\n");

    AB_inserir(&ab, 70);
    AB_inserir(&ab, 39);
    AB_inserir(&ab, 88);

    AB_imprimir(ab);

    AB_remove(&ab, 70);

    printf("\nnext\n\n");

    AB_imprimir(ab);

    AB_Destruir(ab);

    AB *ab1 = NULL;

    printf("\nCaso B)\n\n");

    AB_inserir(&ab1, 10);
    AB_inserir(&ab1, 4);
    AB_inserir(&ab1, 20);
    AB_inserir(&ab1, 6);
    AB_inserir(&ab1, 2);
    AB_inserir(&ab1, 3);
    AB_inserir(&ab1, 5);
    AB_inserir(&ab1, 7);

    AB_imprimir(ab1);

    AB_remove(&ab1, 10);
    AB_remove(&ab1, 4);
    AB_remove(&ab1, 5);

    AB_imprimir(ab1);

    AB_Destruir(ab1);


    printf("\nnext\n\n");

    AB *ab2 = NULL;

    printf("\nCaso C)\n\n");

    AB_inserir(&ab2, 30);
    AB_inserir(&ab2, 50);
    AB_inserir(&ab2, 40);
    AB_inserir(&ab2, 47);
    AB_inserir(&ab2, 15);
    AB_inserir(&ab2, 20);
    AB_inserir(&ab2, 25);
    AB_inserir(&ab2, 17);
    AB_inserir(&ab2, 19);
    AB_inserir(&ab2, 4);
    AB_inserir(&ab2, 7);
    AB_inserir(&ab2, 0);

    AB_imprimir(ab2);

    AB_remove(&ab2, 0);
    AB_remove(&ab2, 30);
    AB_remove(&ab2, 15);
    AB_remove(&ab2, 20);


    printf("\nnext\n\n");

    AB_imprimir(ab2);

    AB_Destruir(ab2);


}
