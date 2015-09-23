/*
  recursiveSorting.h
  sortingAlgorithms

  Created by MarkPenteado on 09/22/15.
  Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#ifndef RECURSIVE_SORTING
#define RECURSIVE_SORTING

int quick(int *vector, int first, int last);
void quickSort(int *vector, int first, int last);
void merge(int *vector, int first, int middle, int last);
void mergeSort(int *vector, int first, int last);

#endif /* RECURSIVE_SORTING */