#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

struct TreeNode {
    int value;
    struct TreeNode *leftPtr;
    struct TreeNode *rightPtr;
};

typedef struct TreeNode treeNode;
typedef treeNode *treeNodePtr;

void insertTreeNode(treeNodePtr *treePtr, int value);
void inOrder(treeNodePtr treePtr);
void preOrder(treeNodePtr treePtr);
void postOrder(treeNodePtr treePtr);

#endif //BINARYTREE_BINARYTREE_H
