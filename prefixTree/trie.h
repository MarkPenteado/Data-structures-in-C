#ifndef TRIE_H
#define TRIE_H

struct no {
	int chave;
	int aresta;
	struct no *f0;
	struct no *f1;
};

typedef struct no No;

No *criarNo(int aresta);
void inserirNo(No **arvore, const char *chave);
void destruirArvore(No **arvore);
void preOrdem(No *arvore);
void emOrdem(No *arvore);
void posOrdem(No *arvore);
int temFilhos(No *arvore);
void mostrarQuantidade(No *arvore);
int buscarNo(No *arvore, const char *chave);
void removerNo(No **arvore, const char *chave);

#endif