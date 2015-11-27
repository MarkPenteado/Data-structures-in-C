#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void heapSort(Heap **heap) {
	int i, n = (*heap)->size, tmp;

	for(i = (n - 2) / 2; i >= 0; i--) {
		descer(heap, i);
	}
	for(i = n - 1; i > 0; i--) {
		tmp = (*heap)->h[0];
		(*heap)->h[0] = (*heap)->h[i];
		(*heap)->h[i] = tmp;
		(*heap)->size -= 1;
		descer(heap, 0);
	}
	(*heap)->size = n;
}

void removerHeap(Heap **heap) {
	(*heap)->h[0] = (*heap)->h[(*heap)->size - 1];
	(*heap)->size -= 1;
	(*heap)->h = realocarVetor((*heap)->h, (*heap)->size);
	descer(heap, 0);
}

void mostrarInformacoes(Heap *heap, int i) {
	if(heap == NULL || i < 0) {
		printf("O no %d nao existe!\n", i);
		return;
	}

	printf("Indice %d\n", i);
	printf("Pai do no %d: %d\n", heap->h[i], mostrarPai(heap, i));
	printf("Filho esquerdo %d: %d\n", heap->h[i], mostrarFilhoEsquerdo(heap, i));
	printf("Filho direito %d: %d\n", heap->h[i], mostrarFilhoDireito(heap, i));
}

int mostrarPai(Heap *heap, int i) {
	if(heap == NULL || i < 0 || i > heap->size) {
		return -1;
	}

	return heap->h[(i - 1) / 2];
}

int mostrarFilhoEsquerdo(Heap *heap, int i) {
	if(heap == NULL || i < 0 || i > heap->size) {
		return -1;
	}

	return heap->h[(2 * i + 1)];
}

int mostrarFilhoDireito(Heap *heap, int i) {
	if(heap == NULL || i < 0 || i > heap->size) {
		return -1;
	}

	return heap->h[(2 * i + 2)];
}

void inserirHeap(Heap **heap, int k) {
	if(*heap == NULL) {
		inicializarHeap(heap);
	}

	if((*heap)->size == 0) {
		(*heap)->size = 1;
		(*heap)->h = inicializarVetor(1);
		(*heap)->h[0] = k;
	} else {
		(*heap)->size += 1;
		(*heap)->h = realocarVetor((*heap)->h, (*heap)->size);
		(*heap)->h[(*heap)->size - 1] = k;
		subir(heap, (*heap)->size - 1);
	}
}

/* recebe um vetor e corrige ele de forma a transforma-lo em um max-heap */
void corrigirMaxHeap(Heap **heap) {
	if(*heap == NULL) {
		return;
	}

	int i;
	for(i = 0; i < (*heap)->size; i++) {
		subir(heap, i);
	}
}

/* recebe um vetor e corrige ele de forma a transforma-lo em um min-heap */
void corrigirMinHeap(Heap **heap) {
	if(*heap == NULL) {
		return;
	}

	int i;
	for(i = ((*heap)->size - 2) / 2; i >= 0; i--) {
		descer(heap, i);
	}
}

void descer(Heap **heap, int i) {
	if(i < 0 || i > (*heap)->size || *heap == NULL) {
		return;
	}

	int k = 2 * i + 1;
	int x = (*heap)->h[i];

	while(k < (*heap)->size) {
		if((k < ((*heap)->size - 1)) && ((*heap)->h[k] < (*heap)->h[k + 1])) {
			k++;
		}
		if(x < (*heap)->h[k]) {
			(*heap)->h[i] = (*heap)->h[k];
			i = k;
			k = 2 * k + 1;
		} else {
			break;
		}
	}
	(*heap)->h[i] = x;

}

void subir(Heap **heap, int i) {
	if(i < 0 || i > (*heap)->size || *heap == NULL) {
		return;
	}

	int j = (i - 1) / 2;
	int x = (*heap)->h[i];

	while(i > 0 && (*heap)->h[j] < x) {
		(*heap)->h[i] = (*heap)->h[j];
		i = j;
		j = (j - 1) / 2;
	}
	(*heap)->h[i] = x;
}

void destruirHeap(Heap **heap) {
	if(*heap != NULL) {
		free(*heap);
		*heap = NULL;
	}
}

int *realocarVetor(int *v, int n) {
	if(v == NULL || n < 0) {
		return v;
	}

	int *tmp;
	tmp = (int*)realloc(v, n * sizeof(int));
	if(tmp == NULL) {
		return v;
	}

	return tmp;
}

int *inicializarVetor(int n) {
	int *novoVetor, i;
	
	novoVetor = (int*)malloc(n * sizeof(int));
	if(novoVetor == NULL) {
		return NULL;
	}

	return novoVetor;
}

void percorrerVetor(int *v, int n) {
	if(v == NULL || n < 0) {
		return;
	}

	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", *(v + i));
	}
	printf("\n");
}

void inicializarHeap(Heap **heap) {
	Heap *novoHeap;

	novoHeap = (Heap*)malloc(sizeof(Heap));
	if(novoHeap == NULL) {
		*heap = NULL;
	}
	novoHeap->h = NULL;
	novoHeap->size = 0;

	*heap = novoHeap;
}