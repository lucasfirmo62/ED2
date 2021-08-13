#include "lista.h"


Lista* criar(){

	Lista* nova_Lista = (Lista*) malloc(sizeof(Lista));
	nova_Lista->quantidade = 0;
	nova_Lista->fim = NULL;
	nova_Lista->inicio = NULL;

	return nova_Lista;

}

No* criar_no(char palavra[50]){
	No* novoNo = (No*) malloc(sizeof(No));
	strcpy (novoNo->palavra, palavra);
	novoNo->ant = NULL;
	novoNo->prox = NULL;

	return novoNo;
}

void inserir(Lista* l, char str[50]){


  if(l->quantidade < 0){
		return;
	} 

  No* novo_no = criar_no(str);

  if(l->quantidade == 0){
    l->inicio = novo_no;
    l->fim = novo_no;

  }else if(l->quantidade > 0){ 
    No* aux = l->inicio;
    novo_no->prox = l->inicio;
    l->inicio = novo_no;
    aux = aux->prox;
	}

  l->quantidade++;
}

void lista_imprimir(Lista* l){
	No* imprima = l->inicio;
	printf("[");
	for(int i = 0; i < l->quantidade; i++){
		printf(" %s ", imprima->palavra);
    imprima = imprima->prox;
	}
	printf("]\n");
}