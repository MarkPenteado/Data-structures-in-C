/*
  naturalSorting.c
  sortingAlgorithms

  Created by MarkPenteado on 09/22/15.
  Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include "naturalSorting.h"

void swap(int *a, int *b) {
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void bubbleSort(int *vector, int size) {
	if(vector == NULL) {
		return;
	}

	int i, j;

	for(i = size - 1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(*(vector + j) > *(vector + (j + 1))) {
				swap((vector + j), (vector + (j + 1)));
			}
		}
	}
}

void selectionSort(int *vector, int size) {
	if(vector == NULL) {
		return;
	}

	int i, j, less;

	for(i = 0; i < size - 1; i++) {
		less = i;
		for(j = i + 1; j < size; j++) {
			if(*(vector + j) < *(vector + less)) {
				less = j;
			}
		}

		if(i != less) {
			swap((vector + i), (vector + less));
		}
	}
}

void insertionSort(int *vector, int size) {
	if(vector == NULL) {
		return;
	}

	int i, j, element;

	for(i = 1; i < size; i++) {
		element = *(vector + i);
		for(j = i - 1; j >= 0 && *(vector + j) > element; j--) {
			*(vector + (j + 1)) = *(vector + j); 
		}
		*(vector + (j + 1)) = element;
	}
}

void shellSort(int *vector, int size) {
	if(vector == NULL) {
		return;
	}

	int i, j, element, gap;

	for(gap = size - 1; gap > 0; gap /= 2) {
		for(i = gap; i < size; i++) {
			element = *(vector + i);
			for(j = i - gap; j >= 0 && *(vector + j) > element; j -= gap) {
				*(vector + (j + gap)) = *(vector + j); 
			}
			*(vector + (j + gap)) = element;
		}
	}
}