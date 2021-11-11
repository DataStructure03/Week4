#ifndef BST_H
#define BST_H

#include "bintree.h"

typedef BinTreeNodeData BSTNodeData;
typedef BinTreeNode BSTNode;
typedef BinTree BinSearchTree;

int pushToBST(BinSearchTree *bst, BSTNode toPush);
int removeFromBST(BinSearchTree* bst, BSTNodeData key);

BSTNode* searchBST(BinSearchTree* bst, BSTNodeData key);

#endif