#pragma once
#include"LinkedList.h"
#include<Windows.h>

void main()
{
	Node* head = NULL;
	Node* tail = NULL;

	type num = -1;

	while (num != '0')
	{
		system("cls");
		printf("저장된 데이터\n");
		LRead(head);

		printf("저장하고자 하는 문자를 입력하시오(0을 입력하면 종료) : ");
		cin >> num;

		if (num != 0)
			LInsert(&head, &tail, num);
	}

	system("cls");
	printf("저장된 데이터\n");
	LRead(head);
	system("pause");

	system("cls");
	LRemove(head, tail);
}