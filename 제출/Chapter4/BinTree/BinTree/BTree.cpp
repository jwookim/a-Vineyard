#include "BTree.h"

BTreeNode* MakeBTreeNode()
{
	BTreeNode* newNode = new BTreeNode;
	int i = 1;
	newNode->data = i++;
	newNode->left = MakeBTreeNode(i++);
	newNode->right = MakeBTreeNode(i);

	return newNode;
}

BTreeNode* MakeBTreeNode(BTData data)
{
	BTreeNode* newNode = new BTreeNode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void ShowTree(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNode);
}

void ShowNode(BTreeNode* bt)
{
	cout << bt->data << endl;
}

void DeleteTree(BTreeNode* bt)
{
	PostorderTraverse(bt, DeleteNode);
}

void DeleteNode(BTreeNode* bt)
{
	ShowNode(bt);
	cout << "삭제됨" << endl;
	delete bt;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	action(bt); //노드의 방문.
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	InorderTraverse(bt->left, action);
	action(bt); //노드의 방문.
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt); //노드의 방문.
}