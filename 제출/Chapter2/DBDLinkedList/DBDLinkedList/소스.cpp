#pragma once
#include"DBDLinkedList.h"

void main()
{
	int data;
	List* list = new List;
	ListInit(list);

	for (int i = 1; i <= 10; i++)
		LInsert(list, i);

	LFirst(list, &data);
	cout << data << endl;

	while (LNext(list, &data))
		cout << data << endl;

	cout << "-----" << endl;

	while (LPrevious(list, &data))
		cout << data << endl;

	cout << "-----" << endl;

	while (LFirst(list, &data))
		cout << LRemove(list) << "»èÁ¦µÊ" << endl;
}