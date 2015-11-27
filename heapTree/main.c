#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char **argv) {
	Heap *heap = NULL;

	/* insere valores no max-heap */
	inicializarHeap(&heap);
	inserirHeap(&heap, 100); // 1
	inserirHeap(&heap, 19);  // 4
	inserirHeap(&heap, 36);  // 2
	inserirHeap(&heap, 17);  // 3
	inserirHeap(&heap, 3);   // 9
	inserirHeap(&heap, 25);  // 5
	inserirHeap(&heap, 1);   // 6
	inserirHeap(&heap, 2);   // 7
	inserirHeap(&heap, 7);   // 8
	inserirHeap(&heap, 101); // 0 <- raiz

	/* mostra o max-heap */
	printf("Max-Heap antes da remocao:\n");
	percorrerVetor(heap->h, heap->size); printf("\n");

	/* mostra informacoes sobre um determinado noh */
	int indice = 3;
	mostrarInformacoes(heap, indice); printf("\n");

	/* remove o elemento de maior prioridade da arvore */
	removerHeap(&heap);

	/* mostra o max-heap apos a remocao */
	printf("Max-Heap apos a remocao do elemento de maior prioridade:\n");
	percorrerVetor(heap->h, heap->size); printf("\n");

	/* mostra o max-heap apos o algoritmo de ordenacao HeapSort */
	printf("Max-Heap apos o algoritmo de ordenacao HeapSort:\n");
	heapSort(&heap);
	percorrerVetor(heap->h, heap->size);
	printf("\n");

	/* destroi o max-heap */
	destruirHeap(&heap);
	return 0;
}