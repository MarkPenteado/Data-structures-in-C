#ifndef HEAP_H
#define HEAP_H

struct heap {
	int *h;
	int size;
};

typedef struct heap Heap;

void inicializarHeap(Heap **heap);
int *inicializarVetor(int n);
int *realocarVetor(int *v, int n);
void percorrerVetor(int *v, int n);
void destruirHeap(Heap **heap);
void subir(Heap **heap, int i);
void descer(Heap **heap, int i);
void corrigirMaxHeap(Heap **heap);
void corrigirMinHeap(Heap **heap);
void inserirHeap(Heap **heap, int k);
void removerHeap(Heap **heap);
int mostrarPai(Heap *heap, int i);
int mostrarFilhoEsquerdo(Heap *heap, int i);
int mostrarFilhoDireito(Heap *heap, int i);
void mostrarInformacoes(Heap *heap, int i);
void heapSort(Heap **heap);

#endif