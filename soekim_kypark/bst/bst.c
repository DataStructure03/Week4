#include "bst.h"

#define LEFT 0
#define RIGHT 1

int pushToBST(BinSearchTree* bst, BSTNode toPush)
{
	if (!bst)
		return FALSE;

	BSTNode* parent = bst->pRootNode;
	while (TRUE)
	{
		if (toPush.data == parent->data)
			return FALSE;

		if (toPush.data < parent->data)
		{
			if (!parent->pLeftChild)
			{
				insertLeftChildNodeBT(parent, toPush);
				break;
			}
			else
				parent = parent->pLeftChild;
		}
		else if (toPush.data > parent->data)
		{
			if (!parent->pRightChild)
			{
				insertRightChildNodeBT(parent, toPush);
				break;
			}
			else
				parent = parent->pRightChild;
		}
	}

	return TRUE;
}
//BinTreeNode* getParentOfMaxLeft(BinTreeNode* parent)
//{
//	for (BSTNode* max = parent->pLeftChild
//		;max->pRightChild
//		;parent = max, max = parent->pRightChild);
//
//	return parent;
//}
//
//void removeLeftChild(BinTreeNode* parent)
//{
//	BSTNode* target = parent->pLeftChild;
//	BSTNode* parentOfSubstitute;
//	BSTNode* substitute;
//
//
//	if (!target)
//	{
//		free(target);
//		parent->pLeftChild = NULL;
//		return;
//	}
//
//	if (target->pLeftChild)
//	{
//		parentOfSubstitute = getParentOfMaxLeft(target);
//		substitute = parentOfSubstitute->pRightChild;
//
//		target->data = substitute->data;
//		removeLeftChild(substitute);
//		return;
//	}
//	else if (target->pRightChild)
//	{
//		parentOfSubstitute = getParentOfMinRight(target);
//		substitute = parentOfSubstitute->pLeftChild;
//
//		target->data = substitute->data;
//		removeRightChild(substitute);
//	}
//	else
//	{
//		free(target);
//		parent->pLeftChild = NULL;
//	}
//}
//
//void removeRightChild(BinTreeNode* parent)
//{
//	BSTNode* target = parent->pRightChild;
//	BSTNode* parentOfSubstitute;
//	BSTNode* substitute;
//
//	if (!target)
//	{
//		free(target);
//		parent->pRightChild = NULL;
//		return;
//	}
//
//	if (target->pLeftChild)
//	{
//		parentOfSubstitute = getParentOfMaxLeft(target);
//		substitute = parentOfSubstitute->pRightChild;
//
//		target->data = substitute->data;
//		removeLeftChild(substitute);
//		return;
//	}
//	else if (target->pRightChild)
//	{
//		parentOfSubstitute = getParentOfMinRight(target);
//		substitute = parentOfSubstitute->pLeftChild;
//
//		target->data = substitute->data;
//		removeRightChild(substitute);
//	}
//}
//
//int removeFromBST(BinSearchTree* bst, BSTNodeData key)
//{
//	if (!bst || !bst->pRootNode)
//		return FALSE;
//
//	BSTNode dummy;
//	dummy.pLeftChild = NULL;
//	dummy.pRightChild = bst->pRootNode;
//	dummy.data = bst->pRootNode->data - 1;
//
//	BSTNode* parentOfKey = getParentOfKey(&dummy, key);
//	if (!parentOfKey)
//		return FALSE;
//
//	if (parentOfKey->pLeftChild
//		&& parentOfKey->pLeftChild->data == key)
//		removeLeftChild(parentOfKey);
//	else if (parentOfKey->pRightChild
//		&& parentOfKey->pRightChild->data == key)
//		removeRightChild(parentOfKey);
//
//	bst->pRootNode = dummy.pRightChild;
//
//	return TRUE;
//}

BSTNode* getParentOfSubstitute(BSTNode* parent) // substitute node is minNode of right subtree
{
	for (BSTNode* substitute = parent->pRightChild
		;substitute && substitute->pLeftChild
		;parent = substitute, substitute = parent->pLeftChild);

	return parent;
}

BinTreeNode* getParentOfKey(BSTNode* parentOfKey, BSTNodeData targetData)
{
	BSTNode* target;

	while (TRUE) // find parent parent of target parent to remove
	{
		if (targetData > parentOfKey->data)
			target = parentOfKey->pRightChild;
		else
			target = parentOfKey->pLeftChild;

		if (!target)
			return NULL;
		if (target->data == targetData)
			break;

		parentOfKey = target;
	}

	return parentOfKey;
}

int removeFromBST(BinSearchTree* bst, BSTNodeData key)
{
	BSTNode dummy;
	dummy.data = bst->pRootNode->data - 1;
	dummy.pRightChild = bst->pRootNode;
	dummy.pLeftChild = NULL;

	BSTNode* parentOfKey = getParentOfKey(&dummy, key);
	if (!parentOfKey)
		return FALSE;
	BSTNode* keyNode;
	BSTNode** wayToKey;

	if (key > parentOfKey->data)
	{
		keyNode = parentOfKey->pRightChild;
		wayToKey = &parentOfKey->pRightChild;
	}
	else
	{
		keyNode = parentOfKey->pLeftChild;
		wayToKey = &parentOfKey->pLeftChild;
	}

	if (!keyNode->pLeftChild)
	{
		*wayToKey = keyNode->pRightChild;
		free(keyNode);
	}
	else if (!keyNode->pRightChild)
	{
		*wayToKey = keyNode->pLeftChild;
		free(keyNode);
	}
	else
	{
		BSTNode* parentOfSubstitute = getParentOfSubstitute(keyNode);
		BSTNode* substitute = (parentOfSubstitute == keyNode) ?
			parentOfSubstitute->pRightChild :
			parentOfSubstitute->pLeftChild;

		if (parentOfSubstitute != keyNode)
		{
			parentOfSubstitute->pLeftChild = substitute->pRightChild;
			substitute->pRightChild = keyNode->pRightChild;
		}
		substitute->pLeftChild = keyNode->pLeftChild;
		*wayToKey = substitute;

		free(keyNode);
	}

	bst->pRootNode = dummy.pRightChild;
	return TRUE;
}


BSTNode* searchBST(BinSearchTree* bst, BSTNodeData key)
{
	if (!bst || !bst->pRootNode)
		return NULL;

	BSTNode* result = bst->pRootNode;
	while (result)
	{
		if (result->data == key)
			break;
		else if (key > result->data)
			result = result->pRightChild;
		else
			result = result->pLeftChild;
	}

	return result;
}