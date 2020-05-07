#pragma once
#include"BTree.h"

void main()
{
	BTreeNode* bt1 = MakeBTreeNode();

	ShowTree(bt1);

	cout << endl;

	DeleteTree(bt1);
}