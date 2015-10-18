/*
 main.c
 binarySearchTree
 
 Created by MarkPenteado on 10/17/15.
 Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#include <stdio.h>
#include "binarySearchTree.h"

int main(int argc, char **argv) {
    Node *tree = NULL;
    
    tree = createTree(1); /* root key */
    insertNode(&tree, 2);
    insertNode(&tree, 3);
    insertNode(&tree, 4);
    insertNode(&tree, 5);
    insertNode(&tree, 6);
    insertNode(&tree, 7);
    insertNode(&tree, 8);
    insertNode(&tree, 9);
    insertNode(&tree, 10);
    insertNode(&tree, 11);
    insertNode(&tree, 12);
    
    removeNode(&tree, 12);
    removeNode(&tree, 11);
    
    /* show tree in: preOrder, inOrder, postOrder */
    showTreeText(tree, 1, 1, 1);

    printf("------------------------------\n");
    sizeInt_t searchKey = 3;
    Node *search = searchNode(tree, searchKey);
    if (search != NULL) {
        printf("Node %d\n\tFound at the address: %p\n", searchKey, search);
        printf("\tDepth of node: %d\n", depthOfNode(tree, searchKey));
        printf("\tHas left child? %s\n", (hasLeft(tree)) ? "yes" : "no");
        printf("\tHas right child? %s\n", (hasRight(tree)) ? "yes" : "no");
        printf("\tHas two children? %s\n", (hasLeftAndRight(tree)) ? "yes" : "no");
    }
    printf("------------------------------\n");
    
    printf("Number of nodes: %d\n", numberOfNodes(tree));
    printf("Number of leafs: %d\n", numberOfLeafs(tree));
    printf("Height of the tree: %d\n", heightOfTree(tree));
    
    /* shows the tree graphically :D */
    printf("Final tree:\n");
    showTreeGraphically(tree);
    
    destroyTree(&tree);
    
    return 0;
}