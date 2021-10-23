#include "tree.h"

int main ()
{
	BinTree *testTree;
	BinTreeNode rootNode;

	rootNode.data = 'A';
	testTree = makeBinTree(rootNode);
	
	BinTreeNode element;
	element.data = 'B';
	insertLeftChildNodeBT(getRootNodeBT(testTree), element);
	printf("left Node : %c\n", getLeftChildNodeBT(testTree->pRootNode)->data);
	element.data = 'C';
	insertRightChildNodeBT(getRootNodeBT(testTree), element);	
	printf("right Node : %c\n", getRightChildNodeBT(testTree->pRootNode)->data);
	element.data = 'D';
	insertRightChildNodeBT(getRootNodeBT(testTree)->pRightChild, element);	
	
	deleteBinTree(testTree);
	printf(">>> %p", testTree);

	printf("\033[34minOrder\n");
	inOrder(testTree->pRootNode);
	printf("\n");
	printf("\033[33mpreOrder\n");
	preOrder(testTree->pRootNode);
	printf("\n");
	printf("\033[35mpostOrder\n");
	postOrder(testTree->pRootNode);
	printf("\033[37m\n");

  return 0;
}