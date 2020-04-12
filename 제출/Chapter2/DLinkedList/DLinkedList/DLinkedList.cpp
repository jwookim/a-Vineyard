#include "DLinkedList.h"



void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	//plist->comp = NULL;
	plist->numOfData = 0;
}

template <typename Type>
void LInsert(List* plist, Type data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;

	plist->head->next = newNode;

	(plist->numOfData)++;
}

template <typename Type>
int LFirst(List* plist, Type* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

template <typename Type>
int LNext(List* plist, Type* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = plist->cur->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	(plist->numOfData)--;

	free(rpos);
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}