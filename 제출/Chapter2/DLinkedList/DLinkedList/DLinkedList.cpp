#include "DLinkedList.h"



void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	//plist->comp = NULL;
	plist->numOfData = 0;
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