#include "./bst.h"

int main()
{
	BinSearchTree *BST;
	BinTreeNode insert;

	insert.data = '5';
	BST = createBinSearchTree(insert);
	for (int i = 0; i < 10; i++)
	{
		insert.data = i + '0';
		if (insertBST(BST, &insert) == FALSE)
			printf("err : duplicated value\n");
	}
	inOrder(getRootNodeBT(BST->bTree));
	printf("\n");
	insert.data = '3';
	removeBST(BST, &insert);
	inOrder(getRootNodeBT(BST->bTree));
	printf("\n");
	deleteBinSearchTree(BST);
	return 0;
}