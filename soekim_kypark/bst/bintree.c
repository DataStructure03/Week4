#include "bintree.h"

BinTree* createBinTree(BinTreeNode rootNode)
{
	BinTree* binTree = calloc(1, sizeof(BinTree));
	if (!binTree)
		return NULL;

	binTree->pRootNode = calloc(1, sizeof(BinTreeNode));
	if (!binTree->pRootNode)
		return NULL;
	binTree->pRootNode->data = rootNode.data;

	return binTree;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode* newLeft = createBinTreeNode(element.data);
	if (!newLeft) return NULL;

	newLeft->pLeftChild = pParentNode->pLeftChild;
	pParentNode->pLeftChild = newLeft;

	return newLeft;
}

BinTreeNode* createBinTreeNode(BinTreeNodeData data)
{
	BinTreeNode* node = calloc(1, sizeof(BinTreeNode));
	if (!node)
		return NULL;

	node->data = data;

	return node;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode* newRight = createBinTreeNode(element.data);
	if (!newRight) return NULL;

	newRight->pRightChild = pParentNode->pRightChild;
	pParentNode->pRightChild = newRight;

	return newRight;
}

void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree)
		return;

	clearBinTreeNodes(pBinTree->pRootNode);
	free(pBinTree);
}

void clearBinTreeNodes(BinTreeNode* rootNode)
{
	if (!rootNode)
		return;

	BinTreeNode* right = rootNode->pRightChild;
	BinTreeNode* left = rootNode->pLeftChild;
	free(rootNode);

	clearBinTreeNodes(left);
	clearBinTreeNodes(right);

}

void printPreorder(BinTreeNode* root, int* n)
{
	if (!root)
		return;

	++(*n);
	printf("%d.	%d\n", *n, root->data);

	printPreorder(root->pLeftChild, n);
	printPreorder(root->pRightChild, n);
}

void preorder(BinTreeNode* root)
{
	if (!root)
		return;

	int n = 0;
	printPreorder(root, &n);
}

void printInorder(BinTreeNode* root, int* n)
{
	if (!root)
		return;

	printInorder(root->pLeftChild, n);

	++(*n);
	printf("%d.	%d\n", *n, root->data);

	printInorder(root->pRightChild, n);
}

void inorder(BinTreeNode* root)
{
	if (!root)
		return;

	int n = 0;
	printInorder(root, &n);
}