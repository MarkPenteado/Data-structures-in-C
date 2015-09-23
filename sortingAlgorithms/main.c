/*
  main.c
  sortingAlgorithms

  Created by MarkPenteado on 09/22/15.
  Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include "naturalSorting.h"
#include "recursiveSorting.h"

void showVector(int *vector, int size);

int main(int argc, char **argv) {
	int vector[5] = {6, 5, 2, 1, 7};

	// natural sorting
	//bubbleSort(vector, 5);
	//selectionSort(vector, 5);
	//insertionSort(vector, 5);
	//shellSort(vector, 5);

	// recursive sorting
	mergeSort(vector, 0, 5);
	//quickSort(vector, 0, 4);
	showVector(vector, 5);

	return 0;
}

void showVector(int *vector, int size) {
	if(vector == NULL) {
		return;
	}

	int i;

	for(i = 0; i < size; i++) {
		printf("%d ", *(vector + i));
	}
	printf("\n");
}