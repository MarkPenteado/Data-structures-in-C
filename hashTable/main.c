#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char **argv) {
	/* inicializa os alunos */
	Aluno *aluno1 = inicializarAluno("Andre", 10.0f);
	Aluno *aluno2 = inicializarAluno("Bruno", 9.0f);
	Aluno *aluno3 = inicializarAluno("Carlos", 6.0f);
	Aluno *aluno4 = inicializarAluno("Denis", 8.0f);
	Aluno *aluno5 = inicializarAluno("Roberto", 4.5f);
	Aluno *aluno6 = inicializarAluno("Anderson", 7.0f);
	Aluno *aluno7 = inicializarAluno("Anwerzig", 9.9f);
	Aluno *aluno8 = inicializarAluno("Ankrutzonh", 5.9f);
	Aluno *aluno9 = inicializarAluno("Ankrutzonhxsdt", 3.9f);
	Aluno *aluno10 = inicializarAluno("Andri", 9.5f);
	Aluno *aluno11 = inicializarAluno("Andri", 9.2f);
	Aluno *aluno12 = inicializarAluno("Andri", 9.0f);
	Aluno *aluno13 = inicializarAluno("Joaozao", 2.0f);

	/* inicializa a tabela hash */
	int m = 256;
	Hash *hashTable = inicializarHash(m);

	/* insere valores na tabela hash */
	inserir(hashTable, aluno1, m);
	inserir(hashTable, aluno2, m);
	inserir(hashTable, aluno3, m);
	inserir(hashTable, aluno4, m);
	inserir(hashTable, aluno5, m);
	inserir(hashTable, aluno6, m);
	inserir(hashTable, aluno7, m);
	inserir(hashTable, aluno8, m);
	inserir(hashTable, aluno9, m);
	inserir(hashTable, aluno10, m);
	inserir(hashTable, aluno11, m);
	inserir(hashTable, aluno12, m);

	/* remove elementos da tabela hash */
	remover(hashTable, aluno10, m);
	//remover(hashTable, aluno11, m);
	//remover(hashTable, aluno12, m);

	/* percorre a tabela Hash */
	percorrerTabelaHash(hashTable, m);

	/* procura por um elemento */
	Aluno *enderecoBusca = buscar(hashTable, aluno3, m);
	if(enderecoBusca == NULL) {
		printf("Elemento nao encontrado!\n");
	} else {
		printf("Elemento %s com nota %.1f encontrado!\n", 
			enderecoBusca->nome, enderecoBusca->nota);
	}

	/* libera os alunos e a tabela hash da memoria */
	destruirAluno(&aluno1);
	destruirAluno(&aluno2);
	destruirAluno(&aluno3);
	destruirAluno(&aluno4);
	destruirAluno(&aluno5);
	destruirAluno(&aluno6);
	destruirAluno(&aluno7);
	destruirAluno(&aluno8);
	destruirAluno(&aluno9);
	destruirAluno(&aluno10);
	destruirAluno(&aluno11);
	destruirAluno(&aluno12);
	destruirHash(&hashTable);

	return 0;
}