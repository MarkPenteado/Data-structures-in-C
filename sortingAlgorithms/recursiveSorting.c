/*
  recursiveSorting.c
  sortingAlgorithms

  Created by MarkPenteado on 09/22/15.
  Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include "recursiveSorting.h"

int quick(int *vector, int first, int last) {
	int pivot, i, j, temp;

	pivot = *(vector + first);
	i = first;
	j = last;

	while(i <= j) {
		if(pivot >= *(vector + i)) {
			i++;
		} else if(pivot < *(vector + j)) {
			j--;
		} else {
			temp = *(vector + i);
			*(vector + i) = *(vector + j);
			*(vector + j) = temp;
			i++;
			j--;
		}
	}

	*(vector + first) = *(vector + j);
	*(vector + j) = pivot;

	return j;
}

void quickSort(int *vector, int first, int last) {
	int pivot;
	if(first < last) {
		pivot = quick(vector, first, last);
		quickSort(vector, first, pivot - 1);
		quickSort(vector, pivot + 1, last);
	}
}

void merge(int *vector, int first, int middle, int last) {
	int i, j, k, *w;

	w = (int*)malloc(sizeof(int) * (last - first));
	if(w == NULL) {
		return;
	}

	i = first;
	j = middle;
	k = 0;

	while(i < middle && j < last) {
		if(*(vector + i) <= *(vector + j)) {
			*(w + (k++)) = *(vector + (i++));
		} else {
			*(w + (k++)) = *(vector + (j++));
		}
	}

	while(i < middle) {
		*(w + (k++)) = *(vector + (i++));
	}
	while(j < last) {
		*(w + (k++)) = *(vector + (j++));
	}

	for(i = first; i < last; i++) {
		*(vector + i) = *(w + (i - first));
	}

	free(w);
}

void mergeSort(int *vector, int first, int last) {
	int middle;
	if(first < last - 1) {
		middle = (first + last) / 2;
		mergeSort(vector, first, middle);
		mergeSort(vector, middle, last);
		merge(vector, first, middle, last);
	}
}