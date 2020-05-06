#include "CircularLinkedList.h"

void ListInit(List* plist)
{
	plist->cur = NULL;
	plist->Before = NULL;
	plist->tail = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data, int check)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
		(plist->numOfData)++;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;

		if (check)
			plist->tail = newNode;

		(plist->numOfData)++;
	}
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->Before = plist->tail;
	plist->cur = plist->Before->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->Before = plist->cur;
	plist->cur = plist->Before->next;
	*pdata = plist->cur->data;

	return TRUE;
}

LData LRemove(List * plist)
{
	Node* node = plist->cur;
	LData rdata = plist->cur->data;

	if (node == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->Before;
	}

	plist->Before->next = plist->cur->next;
	plist->cur = plist->Before;

	delete node;
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}