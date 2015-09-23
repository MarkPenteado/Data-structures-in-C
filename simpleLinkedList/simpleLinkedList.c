/*
  simpleLinkedList.c
  simpleLinkedList

  Created by MarkPenteado on 09/22/15.
  Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include "showLinkedList.h"

sizeVoid_t removeSearch(LinkedList **list, sizeInt_t element) {
	if(*list == NULL) {
		return;
	}

	LinkedList *search, *aux, *prev;
	
	search = linearSearch(*list, element);
	if(search == NULL) {
		return;
	}

	/* checks if the element is at the beginning */
	if(search == *list) {
		removeBeginning(list);
		return;
	}

	/* checks if the element is in the middle */
	aux = *list;
	prev = *list;
	while(aux->next != NULL) {
		prev = aux;
		aux = aux->next;
		if(aux == search) {
			if(aux->next != NULL) {
				prev->next = aux->next;
				free(aux);
				aux = NULL;
				return;
			}
		}
	}

	/* checks if the element is at the end */
	removeEnd(list);
}

sizeVoid_t removeEnd(LinkedList **list) {
	if(*list == NULL) {
		return;
	}

	LinkedList *aux, *prev;
	aux = *list;
	prev = *list;

	while(aux->next != NULL) {
		prev = aux;
		aux = aux->next;
	}

	if(prev == aux) {
		removeBeginning(list);
		return;
	}

	prev->next = NULL;
	free(aux);
	aux = NULL;
}

LinkedList *linearSearch(LinkedList *list, sizeInt_t element) {
	if(list == NULL) {
		return NULL;
	}

	LinkedList *aux;
	for(aux = list; aux != NULL; aux = aux->next) {
		if(aux->element == element) {
			return aux; /* element found */
		}
	}

	return NULL;
}

sizeVoid_t removeBeginning(LinkedList **list) {
	if(*list == NULL) {
		return;
	}

	LinkedList *aux;

	aux = *list;
	*list = (*list)->next;
}

sizeVoid_t freeLinkedList(LinkedList **list) {
	if(*list == NULL) {
		return;
	}

	while(*list != NULL) {
		removeBeginning(list);
	}
}

sizeVoid_t addEnd(LinkedList **list, sizeInt_t value) {
	if(*list == NULL) {
		return;
	}
	LinkedList *aux, *newNode;

	aux = *list;
	while(aux->next != NULL) {
		aux = aux->next;
	}
	newNode = newLinkedList(value);
	aux->next = newNode;
}

sizeVoid_t addBegining(LinkedList **list, sizeInt_t value) {
	if(*list == NULL) {
		return;
	}

	LinkedList *newNode;

	newNode = newLinkedList(value);
	newNode->next = *list;
	*list = newNode;
}

sizeVoid_t showLinkedList(LinkedList *list) {
	if(list == NULL) {
		return;
	}

	LinkedList *aux;

	for(aux = list; aux != NULL; aux = aux->next) {
		printf("%d ", aux->element);
	}
	printf("\n");
}

LinkedList *newLinkedList(sizeInt_t firstValue) {
	LinkedList *newList;

	newList = (LinkedList*)malloc(sizeof(LinkedList));
	if(newList == NULL) {
		return NULL;
	}

	newList->element = firstValue;
	newList->next = NULL;

	return newList;
}