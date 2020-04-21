#pragma once
#include"CircularLinkedList.h"
#include<stdlib.h>
#include<time.h>

void main()
{
	srand((unsigned)time(NULL));

	char name[NAMELEN];

	List* list = new List;
	ListInit(list);

	for (char i = 'a'; i <= 'd'; i++)
	{
		sprintf_s(name, "%c", i);
		LInsert(list, CreateEmp(i, name), TRUE);
	}

	LData data;
	cout << "직원 전체 정보" << endl;
	LFirst(list, &data);
	ShowEmp(data);

	for (int i = 1; i < LCount(list); i++)
	{
		LNext(list, &data);
		ShowEmp(data);
	}

	system("pause");
	system("cls");

	int check = FALSE;
	int num;
	cout << "이름 검색 : ";
	cin >> name;

	cout << "날짜 입력 : ";
	cin >> num;

	LFirst(list, &data);
	if (strcmp(name, data->Name) == 0)
		check = TRUE;
	else
	{
		for (int i = 1; i < LCount(list); i++)
		{
			LNext(list, &data);
			if (strcmp(name, data->Name) == 0)
			{
				check = TRUE;
				break;
			}
		}
		
	}

	if (!check)
		cout << "찾고자 하는 직원이 없습니다.";
	else
	{
		for (int i = 0; i < num; i++)
			LNext(list, &data);

		cout << name << " 직원의 당직 근무 " << num << "일 후의 당직 근무자는 " << data->Name << " 직원 입니다." << endl;
	}

	while (LCount(list) > 0)
	{
		LFirst(list, &data);
		delete LRemove(list);
	}
}