#pragma once
#include"BinarySearchTree.h"

void main()
{
	BTreeNode* Bt;
	BSTData data;

	BSTMakeAndInit(&Bt);

	cin >> data;

	while (data != 0)
	{
		BSTInsert(&Bt, data);
		cin >> data;
	}

	cout << "------" << endl;

	cin >> data;

	while (data != 0)
	{
		if (BSTSearch(Bt, data) == NULL)
			cout << "대상이 존재하지 않습니다." << endl;
		else
			cout << "탐색됨." << endl;

		cin >> data;
	}

	DeleteNode(&Bt);
}