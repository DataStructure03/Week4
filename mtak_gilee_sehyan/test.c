#include "tree.h"

int main ()
{
	BinTree *testTree;
	BinTreeNode rootNode;
	//   A
	//  B C
	// D   E
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
	insertLeftChildNodeBT(getRootNodeBT(testTree)->pLeftChild, element);
	element.data = 'E';
	insertRightChildNodeBT(getRootNodeBT(testTree)->pRightChild, element);	
	
	// deleteBinTree(testTree);
	deleteBinTreeNode(&(getRootNodeBT(testTree)->pRightChild->pRightChild));

	printf("\033[33mpreOrder\n");
	preOrder(testTree->pRootNode);
	printf("\n");
	printf("\033[34minOrder\n");
	inOrder(testTree->pRootNode);
	printf("\n");
	printf("\033[35mpostOrder\n");
	postOrder(testTree->pRootNode);
	printf("\033[37m\n");

  return 0;
}