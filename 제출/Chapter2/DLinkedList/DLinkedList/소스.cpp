#pragma once
#include "DLinkedList.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define LISTSIZE 100


void main()
{
	srand((unsigned)time(NULL));

	List* list = new List;
	LData num;
	LData sum = 0;

	ListInit(list);

	for (int i = 1; i <= LISTSIZE; i++)
		LInsert<string>(list, to_string(i));

	if (LFirst<string>(list, &num))
	{
		sum += num;

		while (LNext<string>(list, &num))
			sum += num;
	}

	cout << "리스트 전체 수의 합 : " << sum << endl;

	int shuf;
	int pos;
	cout << "리스트를 섞을 횟수를 입력하시오 : ";
	cin >> shuf;


	for (int i = 0; i < shuf; i++)
	{
		for (int j = 0; j < LISTSIZE; j++)
		{
			pos = rand() % LISTSIZE;

			LFirst(list, &num);

			for (int k = 0; k < pos; k++)
				LNext<>(list, &num);

			LInsert<>(list, LRemove(list));
		}
	}

	system("cls");

	cout << "리스트 전체 데이터 출력" << endl;

	if (LFirst<string>(list, &num))
	{
		cout << num << endl;

		while (LNext<string>(list, &num))
			cout << num << endl;
	}


	/*if (LFirst(list, &num))
	{
		if (num % 2 == 0 || num % 3 == 0)
			LRemove(list);

		while (LNext(list, &num))
		{
			if (num % 2 == 0 || num % 3 == 0)
				LRemove(list);
		}
	}*/


	/*system("pause");
	system("cls");

	cout << "2와 3의 배수를 삭제한 리스트 전체 데이터 출력" << endl;*/

	/*if (LFirst(list, &num))
	{
		cout << num << endl;

		while (LNext(list, &num))
			cout << num << endl;
	}*/


	while (list->numOfData > 0)
	{
		LFirst<string>(list, &num);

		LRemove(list);
	}
	free(list->head);

	delete list;
}