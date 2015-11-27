#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void remover(Hash *hash_, Aluno *aluno, int m) {
	if(hash_ == NULL) {
		return;
	}

	int h = hash(aluno->nome, m);
	if(hash_[h].lista != NULL) {
		Lista *ant = NULL, *aux = hash_[h].lista;
		while(aux != NULL) {
			/* remove do inicio */
			if(strcmp(hash_[h].lista->aluno->nome, aluno->nome) == 0 
				&& hash_[h].lista->aluno->nota == aluno->nota) {
				aux = hash_[h].lista;
				hash_[h].lista = hash_[h].lista->prox;
				free(aux);
				aux = NULL;
				return;
			}

			/* remove do meio */
			if(strcmp(aux->aluno->nome, aluno->nome) == 0 
				&& aux->aluno->nota == aluno->nota) {
				if(aux->prox != NULL) {
					ant->prox = aux->prox;
					free(aux);
					aux = NULL;
					return;
				}
			}

			/* remove do final */
			if(strcmp(aux->aluno->nome, aluno->nome) == 0 
				&& aux->aluno->nota == aluno->nota) {
				if(aux->prox == NULL) {
					ant->prox = NULL;
					free(aux);
					aux = NULL;
					return;
				}
			}
			ant = aux;
			aux = aux->prox;		
		}
	}	
}

void destruirHash(Hash **hash_) {
	if(*hash_ != NULL) {
		free(*hash_);
		*hash_ = NULL;
	}
}

Aluno *buscar(Hash *hash_, Aluno *aluno, int m) {
	if(hash_ == NULL) {
		return NULL;
	}

	int h = hash(aluno->nome, m);
	if(hash_[h].lista != NULL) {
		Lista *aux = hash_[h].lista;
		while(aux != NULL) {
			if(strcmp(aux->aluno->nome, aluno->nome) == 0 
				&& aux->aluno->nota == aluno->nota) {
				return aux->aluno;
			}
			aux = aux->prox;
		}
	}

	return NULL;
}

void percorrerTabelaHash(Hash *hash_, int m) {
	int i;

	printf("Tabela HASH:\n");
	for(i = 0; i < m; i++) {
		printf("[%d] ", i);
		if(hash_[i].lista != NULL) {
			percorrerLista(hash_[i].lista);
		} else {
			printf("NULL\n");
		}
	}
}

void percorrerLista(Lista *lista) {
	Lista *aux;

	for(aux = lista; aux != NULL; aux = aux->prox) {
		visualizarAluno(aux->aluno);
	}
	printf("\n");
}

/* insere o elemento no inicio da lista */
Lista *addLista(Lista *lista, Aluno *aluno) {
	if(lista == NULL) {
		Lista *novaLista;

		novaLista = (Lista*)malloc(sizeof(Lista));
		if(novaLista == NULL) {
			return NULL;
		}
		novaLista->aluno = aluno;
		novaLista->prox = NULL;

		return novaLista;
	}
	
	Lista *novaLista, *aux;

	novaLista = (Lista*)malloc(sizeof(Lista));
	if(novaLista == NULL) {
		return NULL;
	}
	aux = lista;
	novaLista->aluno = aluno;
	novaLista->prox = aux;

	return novaLista;
}

void inserir(Hash *hash_, Aluno *aluno, int m) {
	if(hash_ == NULL || aluno == NULL) {
		return;
	}

	int h = hash(aluno->nome, m);

	//printf("Nome: %s, Hash: %d\n", aluno->nome, h);
	hash_[h].lista = addLista(hash_[h].lista, aluno);
}

/* Eh recomendavel que M seja um numero primo. */
int hash(char *nome, int m) {
	int i, j = nome[0];

	for(i = 1; nome[i] != '\0'; i++) {
		j = (j * 251 + nome[i]) % m;
	}

	return j % m;
}

Hash *inicializarHash(int m) {
	Hash *novoHash;
	int i;

	novoHash = (Hash*)malloc(m * sizeof(Hash));
	if(novoHash == NULL) {
		return NULL;
	}

	for(i = 0; i < m; i++) {
		novoHash[i].lista = NULL;
	}
	
	return novoHash;
}

void visualizarAluno(Aluno *aluno) {
	if(aluno != NULL) {
		printf("{Nome: %s, Nota: %.1f} ", aluno->nome, aluno->nota);
	}
}

void destruirAluno(Aluno **aluno) {
	if(*aluno != NULL) {
		free(*aluno);
		*aluno = NULL;
	}
}

Aluno *inicializarAluno(char *nome, float nota) {
	Aluno *novoAluno;

	novoAluno = (Aluno*)malloc(sizeof(Aluno));
	if(novoAluno == NULL) {
		return NULL;
	}
	novoAluno->nome = nome;
	novoAluno->nota = nota;

	return novoAluno;
}