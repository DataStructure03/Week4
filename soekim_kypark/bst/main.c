#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "bst.h"

void testRemove(BinSearchTree* bst, BSTNodeData data)
{
	if (removeFromBST(bst, data))
		printf("after remove %d\n", data);
	else
		printf("%d not Found\n", data);
	inorder(bst->pRootNode);
	printf("\n");
}

void testSearch(BinSearchTree* bst, BSTNodeData data)
{
	BSTNode* result = searchBST(bst, data);
	if (result)
		printf("%d finded\n", result->data);
	else
		printf("%d not found\n", data);
}

int main()
{
	srand(time(NULL));
	BSTNode data;
	data.data = 13;

	BinSearchTree* bst = createBinTree(data);

	data.data = 42;
	pushToBST(bst, data);

	data.data = 34;
	pushToBST(bst, data);

	data.data = 23;
	pushToBST(bst, data);

	data.data = 38;
	pushToBST(bst, data);

	data.data = INT_MAX;
	pushToBST(bst, data);

	data.data = -5;
	pushToBST(bst, data);

	data.data = -20;
	pushToBST(bst, data);

	data.data = 5;
	pushToBST(bst, data);

	data.data = 3;
	pushToBST(bst, data);


	printf("before remove\n");
	inorder(bst->pRootNode);
	printf("\n");

	testRemove(bst, 242);

	testRemove(bst, 42);	

	testRemove(bst, 13);

	testRemove(bst, 23);
	testRemove(bst, INT_MAX);

	testSearch(bst, -20);
	testSearch(bst, 3);
	testSearch(bst, 324324);
	testSearch(bst, INT_MAX);

}
