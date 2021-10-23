#include "tree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
  BinTree *tree;
  BinTreeNode *root;
  
  tree = (BinTree *)malloc(sizeof(BinTree));
  root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
  root->data = rootNode.data;
  root->pRightChild = NULL;
  root->pLeftChild = NULL;
  root->visited = 0;
  tree->pRootNode = root;
  return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return pBinTree->pRootNode;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = malloc(sizeof(BinTreeNode));
	node->data = element.data;
	node->pLeftChild = NULL;
	node->pRightChild = NULL;
	if (!pParentNode)
		return NULL;
	pParentNode->pLeftChild = node;
	return node;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = malloc(sizeof(BinTreeNode));
	node->data = element.data;
	node->pLeftChild = NULL;
	node->pRightChild = NULL;
	if (!pParentNode)
		return NULL;
	pParentNode->pRightChild = node;
	return node;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
  	return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
  	return pNode->pRightChild;
}

void postOrder(BinTreeNode *pParentNode)
{
  if (pParentNode) {
    postOrder(pParentNode->pLeftChild);
    postOrder(pParentNode->pRightChild);
    printf("[%c] ", pParentNode->data);
  }
}

void preOrder(BinTreeNode *pParentNode)
{
	if (pParentNode)
	{
		printf("[%c] ",pParentNode->data);
		preOrder(pParentNode->pLeftChild);
		preOrder(pParentNode->pRightChild);
	}
}

void inOrder(BinTreeNode *pParentNode)
{
	if (pParentNode)
	{
		inOrder(pParentNode->pLeftChild);
		printf("[%c] ",pParentNode->data);
		inOrder(pParentNode->pRightChild);
	}
}

void postFree(BinTreeNode *pNode)
{
	if (pNode) {
    postFree(pNode->pLeftChild);
    postFree(pNode->pRightChild);
    deleteBinTreeNode(pNode);
  }
}

void deleteBinTree(BinTree* pBinTree)
{
	BinTreeNode *tmp;

	tmp = pBinTree->pRootNode;
	postFree(tmp);
	free(pBinTree);
	pBinTree = NULL;
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode)
	{
  		free(pNode);
		pNode = NULL;
	}
}