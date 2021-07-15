#include <stdio.h>
#include "ab.h"

int main(int argc, char** argv){

    //char exp[] = "(2+1) - 2 * 3 * 6 / 2 + 5";
    //char exp[] = "((2+1) - 2 * 3)+5*4";
    // char exp[] = "(((2+1) +4)- 2 * 3)+5*4 - (2*4)";

    // char* rpn;

    // rpn = shunting_yard(exp);

    // printf("%s\n", rpn);

    //AB a = AB_Criar(5, AB_Criar(7, NULL, NULL), AB_Criar(8, NULL, AB_Criar(9, NULL, NULL)));

    //AB_Destruir(a);


    AB *ab = NULL;

    AB_inserir(&ab, 10);
    AB_inserir(&ab, 4);
    AB_inserir(&ab, 20);
    AB_inserir(&ab, 2);
    AB_inserir(&ab, 6);
    AB_inserir(&ab, 3);

    AB_imprimir(ab);

    AB_remove(ab, 2);

    AB_imprimir(ab);


}
