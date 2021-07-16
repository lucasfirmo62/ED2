#include <stdio.h>
#include "ab.h"

int main(int argc, char** argv){

    AB *ab = NULL;

    AB_inserir(&ab, 10);
    AB_inserir(&ab, 4);
    AB_inserir(&ab, 20);
    AB_inserir(&ab, 2);
    AB_inserir(&ab, 6);
    AB_inserir(&ab, 3);

    AB_imprimir(ab);

    AB_remove(&ab, 2);

    AB_imprimir(ab);

    //escritaTXT();


}
