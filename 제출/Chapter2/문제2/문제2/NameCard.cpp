#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard* namecard = new NameCard;

	for (int i = 0; i < NAME_LEN; i++)
		namecard->name[i] = name[i];

	for (int i = 0; i < PHONE_LEN; i++)
		namecard->phone[i] = phone[i];

	return namecard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	system("cls");
	cout << "이름 : " << pcard->name << endl;
	cout << "전화번호 : " << pcard->phone << endl;
	system("pause");
}

int NameCompare(NameCard * pcard, char * name)
{
	for (int i = 0; i < NAME_LEN; i++)
	{
		if (pcard->name[i] != name[i])
			return FALSE;
		if (pcard->name[i] == NULL && name[i] == NULL)
			break;
	}
	return TRUE;
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	for (int i = 0; i < PHONE_LEN; i++)
		pcard->phone[i] = phone[i];
}