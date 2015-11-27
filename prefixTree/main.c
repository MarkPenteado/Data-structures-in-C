#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(int argc, char **argv) {
	No *arvore = NULL;
	char *chave = "10101011";
	char *chave2 = "10101";
	char *chave3 = "101010110";

	inserirNo(&arvore, chave);
	inserirNo(&arvore, chave);
	inserirNo(&arvore, chave);
	inserirNo(&arvore, chave);
	inserirNo(&arvore, chave2);
	inserirNo(&arvore, chave);
	inserirNo(&arvore, chave2);
	inserirNo(&arvore, chave3);

	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave3);
	removerNo(&arvore, chave2);
	removerNo(&arvore, chave2);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);
	removerNo(&arvore, chave);

	printf("pre ordem:\n"); preOrdem(arvore); printf("\n");
	printf("quantidade de elementos:\n"); mostrarQuantidade(arvore); printf("\n");

	char *chaveBusca = chave;
	int resultadoBusca = buscarNo(arvore, chaveBusca);
	if(resultadoBusca > 0)
		printf("O no foi encontrado com %d elementos!\n", resultadoBusca);
	else
		printf("O no nao foi encontrado!\n");

	destruirArvore(&arvore);
	return 0;
}