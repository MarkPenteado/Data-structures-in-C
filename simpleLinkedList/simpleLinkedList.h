/*
  simpleLinkedList.h
  simpleLinkedList

  Created by MarkPenteado on 09/22/15.
  Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int sizeInt_t;
typedef void sizeVoid_t;

struct __List {
	sizeInt_t element;
	struct __List *next;
};

typedef struct __List LinkedList;

LinkedList *newLinkedList(sizeInt_t firstValue);
sizeVoid_t addBegining(LinkedList **list, sizeInt_t value);
sizeVoid_t addEnd(LinkedList **list, sizeInt_t value);
sizeVoid_t freeLinkedList(LinkedList **list);
sizeVoid_t showLinkedList(LinkedList *list);
LinkedList *linearSearch(LinkedList *list, sizeInt_t element);
sizeVoid_t removeBeginning(LinkedList **list);
sizeVoid_t removeEnd(LinkedList **list);
sizeVoid_t removeSearch(LinkedList **list, sizeInt_t element);

#endif /* LINKED_LIST_H */