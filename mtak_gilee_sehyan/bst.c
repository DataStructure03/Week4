#include "bst.h"

// typedef struct BinarySearchTreeType {
// 	BinTree *bTree;
// }BinSearchTree;

// 이진 탐색 트리 생성 
BinSearchTree *createBinSearchTree(BinTreeNode root)
{
	BinSearchTree *bst;

	bst = (BinSearchTree *)calloc(1, sizeof(BinSearchTree));
	bst->bTree = makeBinTree(root);
	return bst;
}

// 이진 탐색 트리 삭제 
void deleteBinSearchTree(BinSearchTree *bsTree)
{
	deleteBinTree(bsTree->bTree);
	free(bsTree);
}

// 자료 추가 
int insertBST(BinSearchTree *bsTree, BinTreeNode *tNode)
{
	BinTreeNode *tmp;

	if (searchBST(bsTree, tNode->data))
		return FALSE;
	tmp = getRootNodeBT(bsTree->bTree);
	while (1) {
		if (tmp->data > tNode->data) {
			if (getLeftChildNodeBT(tmp) == NULL) {
				insertLeftChildNodeBT(tmp, *tNode);
				return TRUE;
			} else {
				tmp = getLeftChildNodeBT(tmp);
			}
		} else if (tmp->data < tNode->data) {
			if (getRightChildNodeBT(tmp) == NULL) {
				insertRightChildNodeBT(tmp, *tNode);
				return TRUE;
			} else {
				tmp = getRightChildNodeBT(tmp);
			}
		} else {
			return FALSE;
		}
	}
	return TRUE;	
}

BinTreeNode *minValueNode(BinTreeNode *node)
{
	BinTreeNode *cur = node;
	while (!cur->pLeftChild)
		cur = cur->pLeftChild;
	return cur;
}

BinTreeNode *deleteNode(BinTreeNode *root, int key)
{
	if (!root)
		return NULL;
	if (key < root->data)
		root->pLeftChild = deleteNode(root->pLeftChild, key);
	else if (key > root->data)
	{
		root->pRightChild = deleteNode(root->pRightChild, key);
	}
	else
	{
		if (!root->pLeftChild)
		{
			BinTreeNode *tmp = root->pRightChild;
			free(root);
			return tmp;
		}
		else if (!root->pRightChild)
		{
			BinTreeNode *tmp = root->pLeftChild;
			free(root);
			return tmp;
		}
		BinTreeNode *tmp = minValueNode(root->pRightChild);
		root->data = tmp->data;
		root->pRightChild = deleteNode(root->pRightChild, tmp->data);
	}
	return root;
}
// 자료 제거 
BinTreeNode *removeBST(BinSearchTree *bsTree, BinTreeNode *tNode)
{
	BinTreeNode *root;

	root = bsTree->bTree->pRootNode;
	if (!bsTree)
		return NULL;
	return deleteNode(root, tNode->data);
}

void inOrderBST(BinTreeNode *pParentNode, BinTreeNode **target, Data data)
{
	if (pParentNode)
	{
		inOrderBST(pParentNode->pLeftChild, target, data);
		if (pParentNode->data == data)
			*target = pParentNode;
		inOrderBST(pParentNode->pRightChild, target, data);
	}
}

	// 검색
BinTreeNode *searchBST(BinSearchTree *bsTree, Data data)
{
	BinTreeNode *ret = NULL;
	if (bsTree)
	{
		inOrderBST(bsTree->bTree->pRootNode, &ret, data);
	}
	return ret;
}