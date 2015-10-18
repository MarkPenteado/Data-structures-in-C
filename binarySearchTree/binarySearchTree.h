/*
 binarySearchTree.h
 binarySearchTree
 
 Created by MarkPenteado on 10/17/15.
 Copyright (c) 2015 MarkPenteado. All rights reserved.
*/

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

struct node {
    int key;
    int height;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

typedef int sizeInt_t;
typedef void sizeVoid_t;

Node *newNode(sizeInt_t key);
Node *createTree(sizeInt_t key);
sizeVoid_t destroyTree(Node **root);
sizeVoid_t insertNode(Node **root, sizeInt_t key);
sizeVoid_t preOrder(Node *root);
sizeVoid_t inOrder(Node *root);
sizeVoid_t postOrder(Node *root);
sizeVoid_t showTreeText(Node *root, sizeInt_t p, sizeInt_t i, sizeInt_t po);
sizeVoid_t showTreeGraphically(Node *tree);
Node *removeRoot(Node *root);
sizeVoid_t removeNode(Node **root, sizeInt_t key);
Node *searchNode(Node *root, sizeInt_t key);
sizeInt_t numberOfNodes(Node *root);
sizeInt_t numberOfLeafs(Node *root);
sizeInt_t heightOfTree(Node *root);
sizeInt_t max(sizeInt_t a, sizeInt_t b);
sizeInt_t depthOfNode(Node *root, sizeInt_t key);
sizeInt_t hasLeft(Node *root);
sizeInt_t hasRight(Node *root);
sizeInt_t hasLeftAndRight(Node *root);
sizeInt_t getHeight(Node *root);
sizeInt_t getBalance(Node *root);
Node *updateHeight(Node *root);
Node *leftRotate(Node *root);
Node *rightRotate(Node *root);
Node *balanceTree(Node *root, sizeInt_t key);

#endif /* BINARY_SEARCH_TREE */