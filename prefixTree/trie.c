#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

void removerNo(No **arvore, const char *chave) {
	if(*arvore != NULL) {
		No *pai = NULL, *filho = *arvore;
		int posicao = 0;

		while(posicao < strlen(chave)) {
			if(chave[posicao] == '0' && filho->f0 != NULL) {
				pai = filho;
				filho = filho->f0;
			} else if(chave[posicao] == '0' && filho->f0 == NULL) {
				return;
			}

			if(chave[posicao] == '1' && filho->f1 != NULL) {
				pai = filho;
				filho = filho->f1;
			} else if(chave[posicao] == '1' && filho->f1 == NULL) {
				return;
			}

			posicao++;
		}

		if(filho->chave == 1 && !temFilhos(filho) && pai->f0 == filho) {
			pai->f0 = NULL;
			free(filho);
			filho = NULL;
			return;
		} else if(filho->chave == 1 && !temFilhos(filho) && pai->f1 == filho) {
			pai->f1 = NULL;
			free(filho);
			filho = NULL;
			return;
		}

		if(filho->chave > 0) {
			filho->chave--;
		}
	}
}

int buscarNo(No *arvore, const char *chave) {
	if(arvore != NULL) {
		No *aux = arvore;
		int posicao = 0;

		while(posicao < strlen(chave)) {
			if(chave[posicao] == '0' && aux->f0 != NULL) {
				aux = aux->f0;
			} else if(chave[posicao] == '0' && aux->f0 == NULL) {
				return -1;
			}

			if(chave[posicao] == '1' && aux->f1 != NULL) {
				aux = aux->f1;
			} else if(chave[posicao] == '1' && aux->f1 == NULL) {
				return -1;
			}

			posicao++;
		}

		if(aux->chave > 0) {
			return aux->chave;
		}
	}

	return -1;
}

void mostrarQuantidade(No *arvore) {
	if(arvore != NULL) {
		if(arvore->aresta != 2) {
			printf("%d ", arvore->chave);
		}
		mostrarQuantidade(arvore->f0);
		mostrarQuantidade(arvore->f1);
	}
}

int temFilhos(No *arvore) {
	return (arvore->f0 != NULL || arvore->f1 != NULL) ? 1 : 0;
}

void preOrdem(No *arvore) {
	if(arvore != NULL) {
		if(arvore->aresta != 2) {
			printf("%d ", arvore->aresta);
		}
		preOrdem(arvore->f0);
		preOrdem(arvore->f1);
	}
}

void emOrdem(No *arvore) {
	if(arvore != NULL) {
		emOrdem(arvore->f0);
		if(arvore->aresta != 2) {
			printf("%d ", arvore->aresta);
		}
		emOrdem(arvore->f1);
	}
}

void posOrdem(No *arvore) {
	if(arvore != NULL) {
		posOrdem(arvore->f0);
		posOrdem(arvore->f1);
		if(arvore->aresta != 2) {
			printf("%d ", arvore->aresta);
		}
	}
}

void destruirArvore(No **arvore) {
	if(*arvore != NULL) {
		destruirArvore(&((*arvore)->f0));
		destruirArvore(&((*arvore)->f1));
		free(*arvore);
		*arvore = NULL;
	}
}

void inserirNo(No **arvore, const char *chave) {
	No *aux = NULL;
	int posicao = 0;

	if(*arvore == NULL) {
		*arvore = criarNo(2);
	}

	aux = *arvore;

	while(posicao < strlen(chave)) {
		if(chave[posicao] == '0' && aux->f0 == NULL) {
			aux->f0 = criarNo(0);
			aux = aux->f0;
		} else if(chave[posicao] == '0' && aux->f0 != NULL) {
			aux = aux->f0;
		}

		if(chave[posicao] == '1' && aux->f1 == NULL) {
			aux->f1 = criarNo(1);
			aux = aux->f1;
		} else if(chave[posicao] == '1' && aux->f1 != NULL) {
			aux = aux->f1;
		}

		posicao++;
	}

	aux->chave++;
}

No *criarNo(int aresta) {
	No *novoNo;
	
	novoNo = (No*)malloc(sizeof(No));
	if(novoNo == NULL) {
		return novoNo;
	}
	novoNo->chave = 0;
	novoNo->aresta = aresta;
	novoNo->f0 = NULL;
	novoNo->f1 = NULL;

	return novoNo;
}