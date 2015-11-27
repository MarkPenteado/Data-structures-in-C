#ifndef HASH_H
#define HASH_H

struct aluno {
	char *nome;
	float nota;
};
typedef struct aluno Aluno;

struct lista {
	Aluno *aluno;
	struct lista *prox;
};
typedef struct lista Lista;

struct hash_ {
	Lista *lista;
};
typedef struct hash_ Hash;

Aluno *inicializarAluno(char *nome, float nota);
void destruirAluno(Aluno **aluno);
void visualizarAluno(Aluno *aluno);
Hash *inicializarHash(int m);
int hash(char *nome, int m);
void inserir(Hash *hash_, Aluno *aluno, int m);
Lista *addLista(Lista *lista, Aluno *aluno);
void percorrerLista(Lista *lista);
void percorrerTabelaHash(Hash *hash_, int m);
Aluno *buscar(Hash *hash_, Aluno *aluno, int m);
void destruirHash(Hash **hash_);
void remover(Hash *hash_, Aluno *aluno, int m);

#endif