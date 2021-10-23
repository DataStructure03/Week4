#include "tree.h"

/*
typedef struct BINTREENodeType
{
  char  data;
  int   visited;
  
  struct  BINTREENodeType* pLeftChild;
  struct  BINTREENodeType* pRightChild;
} BinTreeNode;

typedef struct  BINTREEType
{
  BinTreeNode* pRootNode;
} BinTree;
*/

BinTree*        makeBinTree(BinTreeNode rootNode)
{
    BinTree *res;
	BinTreeNode *node;

    if (!(res = malloc(sizeof(BinTree))))
        return (NULL);
	if (!(node = malloc(sizeof(BinTreeNode))))
    {
        free(res);
		return (NULL);
    }
    node->data = rootNode.data;
	node->visited = rootNode.visited;
	node->pLeftChild = NULL;
    node->pRightChild = NULL;
    res->pRootNode = node;
    return (res);
}

BinTreeNode*    getRootNodeBT(BinTree* pBinTree)
{
    if (!pBinTree)
        return (NULL);
	return(pBinTree->pRootNode);
}

BinTreeNode*    insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *node;

    if (!pParentNode)
        return (NULL);
    else if (pParentNode->pLeftChild) // 이미 존재한다면 부모노드 반환
        return (pParentNode);
    if (!(node = malloc(sizeof(BinTreeNode))))
        return (NULL);
    node->data = element.data;
    node->visited = element.visited;
	node->pLeftChild = NULL;
    node->pRightChild = NULL;
    pParentNode->pLeftChild = node;
	return (pParentNode);
}

BinTreeNode*    insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *node;

    if (!pParentNode)
        return (NULL);
	else if (pParentNode->pRightChild) // 이미 존재한다면 부모노드 반환
        return (pParentNode);
    if (!(node = malloc(sizeof(BinTreeNode))))
        return (NULL);
    node->data = element.data;
    node->visited = element.visited;
	node->pLeftChild = NULL;
    node->pRightChild = NULL;
    pParentNode->pRightChild = node;
	return (pParentNode);
}

BinTreeNode*    getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (!pNode)
        return (NULL);
    return (pNode->pLeftChild);
}

BinTreeNode*    getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
        return (NULL);
    return (pNode->pRightChild);
}

void            deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
    deleteBinTreeNode(pNode->pRightChild);
    free(pNode);
}

void            deleteBinTree(BinTree* pBinTree)
{
    if (!pBinTree)
        return ;
    deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void		printfTree(BinTreeNode *pBinTreeNode, int i)
{
	if (!pBinTreeNode)
		return ;
	printf("height : %d | %c\n", i, pBinTreeNode->data);
	printfTree(pBinTreeNode->pLeftChild, i++);
	printfTree(pBinTreeNode->pRightChild, i++);
}

BinTreeNode *save_tree(BinTreeNode *node, int data, int max)
{
    BinTreeNode *Lnode;
    BinTreeNode *Rnode;
    BinTreeNode element;

    if (max <= data)
        return (NULL);
    element.data = 'a' + data;
    element.visited = 0;
    Lnode = insertLeftChildNodeBT(node, element);
    
    element.data = 'a' + data + 1;
    element.visited = 0;
    Rnode = insertRightChildNodeBT(node, element);
    save_tree(Lnode, data * 2, max);
    save_tree(Rnode, data * 2 + 1, max);
    return (node);
}

int main(void)
{
    BinTree     *pBinTree;
    BinTreeNode rootNode;

	rootNode.data = 'a';
	rootNode.visited = 0;
	rootNode.pLeftChild = NULL;
	rootNode.pRightChild = NULL;
	pBinTree = makeBinTree(rootNode);
	save_tree(pBinTree->pRootNode, 1, 30);
	printfTree(pBinTree->pRootNode, 0);
	deleteBinTree(pBinTree);
    return(0);
}

/*

int main()
{
	makeBinTree
}
void	makeTree(BinTreeNode *node)
{
	if (node->data - 'a' > 4)
		return ;
	BinTreeNode element;
	
	element.data = 2 * node->data;
	element.visited = 0;
	element.pLeftChild = 0;
	element.pRightChild = 0;
	insertLeftChildNodeBT(node, element);
	element.data = 2 * node->data + 1;
	insertRightChildNodeBT(node, element);
	makeTree(node->pLeftChild);
	makeTree(node->pRightChild);
}

*/