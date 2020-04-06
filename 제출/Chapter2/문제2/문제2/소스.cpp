#pragma once
#include"CardList.h"
#include<string.h>

bool Search(List* list, LData* data, char name[])
{
	if (LFirst(list, data))
	{
		if (NameCompare(*data, name))
			return true;
		else
		{
			while (LNext(list, data))
			{
				if (NameCompare(*data, name))
					return true;
			}
		}
	}
	return false;
}

void main()
{
	CardList* Cl = new CardList;
	ListInit(Cl);

	NameCard* tmp;
	int num;
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	cout << "정보를 저장하려는 인원 수를 입력하시오 : ";
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		system("cls");
		cout << i << "번째 정보 입력" << endl;
		cout << "이름 : ";
		cin >> name;
		cout << "전화번호 : ";
		cin >> phone;

		LInsert(Cl, MakeNameCard(name, phone));
	}

	system("cls");

	cout << "찾으려하는 이름을 입력하시오 : ";
	cin >> name;

	if (Search(Cl, &tmp, name))
		ShowNameCardInfo(tmp);
	else
	{
		cout << "해당하는 이름을 찾을 수 없습니다." << endl;
		system("pause");
	}
	system("cls");

	cout << "정보를 변경할 사람의 이름을 입력하시오 : ";
	cin >> name;

	if (Search(Cl, &tmp, name))
	{
		cout << "전화번호를 입력하시오 : ";
		cin >> phone;
		ChangePhoneNum(tmp, phone);

		ShowNameCardInfo(tmp);
	}
	else
	{
		cout << "해당하는 이름을 찾을 수 없습니다." << endl;
		system("pause");
	}

	system("cls");

	cout << "삭제할 사람의 이름을 입력하시오 : ";
	cin >> name;

	if (Search(Cl, &tmp, name))
	{
		LRemove(Cl);
		cout << "데이터 삭제 완료" << endl;
		system("pause");
	}
	else
	{
		cout << "해당하는 이름을 찾을 수 없습니다." << endl;
		system("pause");
	}

	if (LFirst(Cl, &tmp))
	{
		ShowNameCardInfo(tmp);

		while (LNext(Cl, &tmp))
			ShowNameCardInfo(tmp);
	}


	while (LCount(Cl) > 0)
	{
		LFirst(Cl, &tmp);
		LRemove(Cl);
	}
}