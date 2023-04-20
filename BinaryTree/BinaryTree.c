#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

void insertTreeNode(treeNodePtr *treePtr, int value) {
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(treeNode));

        if (*treePtr != NULL) {
            (*treePtr)->value = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("No memory available");
        }
    } else {
        if (value < (*treePtr)->value){
            insertTreeNode(&((*treePtr)->leftPtr),value);
        }
        if (value > (*treePtr)->value){
            insertTreeNode(&((*treePtr)->rightPtr),value);
        }
        if (value == (*treePtr)->value){
            printf("Found existing value");
        }
    }
}

void inOrder(treeNodePtr treePtr){
    if (treePtr != NULL){
        inOrder(treePtr->leftPtr);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(treeNodePtr treePtr){
    if (treePtr != NULL){
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(treeNodePtr treePtr){
    if (treePtr != NULL){
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
    }
}