/*
 binarySearchTree.c
 binarySearchTree
 
 Created by MarkPenteado on 10/17/15.
 Copyright (c) 2015 MarkPenteado. All rights reserved. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"

int _print_t(Node *tree, int is_left, int offset, int depth, char s[255][255]) {
    char b[255];
    int width = 5;
    
    if (!tree) {
        return 0;
    }
    
    sprintf(b, "(%03d)", tree->key);
    int left = _print_t(tree->left, 1, offset, depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);
    
    for(int i = 0; i < width; i++) {
        s[2 * depth][offset + left + i] = b[i];
    }
    
    if(depth && is_left) {
        for(int i = 0; i < width + right; i++) {
            s[2 * depth - 1][offset + left + width/2 + i] = '-';
        }
        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';
        
    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++) {
            s[2 * depth - 1][offset - width/2 + i] = '-';
        }
        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
    
    return left + width + right;
}

sizeVoid_t showTreeGraphically(Node *tree) {
    char s[(heightOfTree(tree) * 2) + 1][255];
    
    for (int i = 0; i < (heightOfTree(tree) * 2) + 1; i++) {
        sprintf(s[i], "%80s", " ");
    }
    
    _print_t(tree, 0, 0, 0, s);
    printf("\n");
    
    for (int i = 0; i < (heightOfTree(tree) * 2) + 1; i++){
        printf("%s\n", s[i]);
    }
    
    printf("\n");
}

sizeInt_t getHeight(Node *root) {
    if (root == NULL) {
        return 0;
    }
    
    return root->height;
}

sizeInt_t getBalance(Node *root) {
    if (root == NULL) {
        return 0;
    }
    
    return getHeight(root->left) - getHeight(root->right);
}

Node *updateHeight(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    return root;
}

Node *leftRotate(Node *root) {
    Node *x = root->right;
    Node *y = x->left;
    
    x->left = root;
    root->right = y;
    
    root = updateHeight(root);
    x = updateHeight(x);
    
    return x;
}

Node *rightRotate(Node *root) {
    Node *x = root->left;
    Node *y = x->right;
    
    x->right = root;
    root->left = y;
    
    root = updateHeight(root);
    x = updateHeight(x);
    
    return x;
}

Node *balanceTree(Node *root, sizeInt_t key) {
    sizeInt_t balance = 0;
    root = updateHeight(root);
    balance = getBalance(root);
    
    if (balance > 1 && root->left->key > key) {
        return rightRotate(root);
    } else if (balance < -1 && root->right->key < key) {
        return leftRotate(root);
    }
    
    if (balance > 1 && root->left->key < key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    } else if (balance < -1 && root->right->key > key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

sizeInt_t hasLeft(Node *root) {
    return (root->left != NULL) ? 1 : 0;
}

sizeInt_t hasRight(Node *root) {
    return (root->right != NULL) ? 1 : 0;
}

sizeInt_t hasLeftAndRight(Node *root) {
    return (hasLeft(root) && hasRight(root)) ? 1: 0;
}

sizeInt_t depthOfNode(Node *root, sizeInt_t key) {
    sizeInt_t depth = 0;
    
    if (root != NULL) {
        Node *help = root;
        while (help != NULL) {
            if (help->key == key) {
                return depth;
            } else if(help->key > key) {
                help = help->left;
                depth++;
            } else {
                help = help->right;
                depth++;
            }
        }
    }
    
    return 0; /* node not found or the tree is empty */
}

sizeInt_t heightOfTree(Node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

sizeInt_t max(sizeInt_t a, sizeInt_t b) {
    return (a > b) ? a : b;
}

sizeInt_t numberOfNodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    
    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}

sizeInt_t numberOfLeafs(Node *root) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    return numberOfLeafs(root->left) + numberOfLeafs(root->right);
}

Node *searchNode(Node *root, sizeInt_t key) {
    if (root != NULL) {
        Node *help = root;
        while (help != NULL) {
            if (help->key == key) {
                return help;
            } else if (help->key > key) {
                help = help->left;
            } else {
                help = help->right;
            }
        }
    }
    
    return NULL; /* node not found */
}

sizeVoid_t removeNode(Node **root, sizeInt_t key) {
    if (*root != NULL) {
        Node *father = NULL, *son = *root;
        
        while (son != NULL) {
            if (son->key == key) {
                if (*root == son) {
                    *root = removeRoot(son);
                } else if(father->left == son) {
                    father->left = removeRoot(son);
                } else {
                    father->right = removeRoot(son);
                }
            }
            
            father = son;
            if (son->key > key) {
                son = son->left;
            } else {
                son = son->right;
            }
        }
    }
}

Node *removeRoot(Node *root) {
    Node *father, *son;
    if (root->left == NULL) {
        son = root->right;
        free(root);
        root = NULL;
        
        return son;
    }
    
    father = root; son = root->left;
    while (son->right != NULL) {
        father = son;
        son = son->right;
    }
    
    if (father != root) {
        father->right = son->left;
        son->left = root->left;
    }
    son->right = root->right;
    free(root);
    root = NULL;
    
    return son;
}

sizeVoid_t showTreeText(Node *root, sizeInt_t p, sizeInt_t i, sizeInt_t po) {
    if (p) {
        printf("pre order: ");
        preOrder(root);
        printf("\n");
    }
    if (i) {
        printf("in order: ");
        inOrder(root);
        printf("\n");
    }
    if (po) {
        printf("post order: ");
        postOrder(root);
        printf("\n");
    }
}

sizeVoid_t preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

sizeVoid_t inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

sizeVoid_t postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

sizeVoid_t insertNode(Node **root, sizeInt_t key) {
    if (*root == NULL) {
        *root = newNode(key);
    } else {
        if ((*root)->key > key) {
            insertNode(&((*root)->left), key);
        } else {
            insertNode(&((*root)->right), key);
        }
        
        *root = balanceTree(*root, key);
    }
}

Node *newNode(sizeInt_t key) {
    Node *nNode;
    
    nNode = (Node*)malloc(sizeof(Node));
    if (nNode == NULL) {
        return NULL;
    }
    nNode->key = key;
    nNode->height = 1; /* (=leaf) */
    nNode->left = NULL;
    nNode->right = NULL;
    
    return nNode;
}

Node *createTree(sizeInt_t key) {
    Node *newTree;
    newTree = newNode(key);
    
    return newTree;
}

sizeVoid_t destroyTree(Node **root) {
    if (*root != NULL) {
        destroyTree(&((*root)->left));
        destroyTree(&((*root)->right));
        free(*root);
        *root = NULL;
    }
}