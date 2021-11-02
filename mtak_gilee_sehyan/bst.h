#ifndef  BTS_H
#  define BTS_H

#include "./tree.h"

// typedef int Data;

typedef struct BinarySearchTreeType {
	BinTree *bTree;
}BinSearchTree;

// 이진 탐색 트리 생성 
BinSearchTree *createBinSearchTree(BinTreeNode root);

// 이진 탐색 트리 삭제 
void deleteBinSearchTree(BinSearchTree *bsTree);

// 자료 추가 
int insertBST(BinSearchTree *bsTree, BinTreeNode *tNode);

// 자료 제거 
BinTreeNode *removeBST(BinSearchTree *bsTree, BinTreeNode *tNode);

// 검색
BinTreeNode *searchBST(BinSearchTree *bsTree, Data data);

#endif