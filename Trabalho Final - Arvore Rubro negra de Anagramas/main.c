#include <stdio.h>
#include <stdlib.h>


int main(){

	FILE* arquivo;

    arquivo = fopen("br.txt","r");
      if (arquivo == NULL){
        printf("Não foi possivel abrir o arquivo!");
        exit(1);
    }

    int count = 0;
    int v[100];
    char vet_string[300000][50];

    int n_strings = 0;
    int n_coluna = 0;
    char c;

    do{
        c = fgetc(arquivo);

        if(c == 'A'){
            c = 'a';
        }if(c == 'B'){
            c = 'b';
        }if(c == 'C'){
            c = 'c';
        }if(c == 'D'){
            c = 'd';
        }if(c == 'E'){
            c = 'e';
        }if(c == 'F'){
            c = 'f';
        }if(c == 'G'){
            c = 'g';
        }if(c == 'H'){
            c = 'h';
        }if(c == 'I'){
            c = 'i';
        }if(c == 'J'){
            c = 'j';
        }if(c == 'K'){
            c = 'k';
        }if(c == 'L'){
            c = 'l';
        }if(c == 'M'){
            c = 'm';
        }if(c == 'N'){
            c = 'n';
        }if(c == 'O'){
            c = 'o';
        }if(c == 'P'){
            c = 'p';
        }if(c == 'Q'){
            c = 'q';
        }if(c == 'R'){
            c = 'r';
        }if(c == 'S'){
            c = 's';
        }if(c == 'T'){
            c = 't';
        }if(c == 'U'){
            c = 'u';
        }if(c == 'V'){
            c = 'v';
        }if(c == 'X'){
            c = 'x';
        }if(c == 'Y'){
            c = 'y';
        }if(c == 'W'){
            c = 'w';
        }if(c == 'Z'){
            c = 'z';
        }

        if(c == '\n'){
            for(int i = 0; i < count; i++){
                vet_string[n_strings][i] = v[i];
            }

            n_strings++;

            count = 0;
            n_coluna = 0;
        }else{
            v[count] = c;
            count++;
        }

    }while (c != EOF);

    fclose(arquivo);

    ARN_Sort(vet_string, n_strings);

}