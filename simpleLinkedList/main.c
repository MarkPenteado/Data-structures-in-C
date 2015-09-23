/*
  main.c
  simpleLinkedList

  Created by MarkPenteado on 09/22/15.
  Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include "simpleLinkedList.h"

int main(int argc, char **argv) {
	LinkedList *list;
	
	list = newLinkedList(15); /* create the LinkedList */
	addBegining(&list, 10);
	addEnd(&list, 20);
	addEnd(&list, 25);
	addEnd(&list, 30);
	addEnd(&list, 35);
	addEnd(&list, 40);
	addEnd(&list, 45);
	addEnd(&list, 50);
	addBegining(&list, 5);

	printf("Before removing elements\n");
	showLinkedList(list);

	removeBeginning(&list);
	removeSearch(&list, 20);
	removeEnd(&list);

	printf("\nafter removing elements 5, 20 and 50\n");
	showLinkedList(list);

	freeLinkedList(&list); /* remove the LinkedList from memory */

	return 0;
}