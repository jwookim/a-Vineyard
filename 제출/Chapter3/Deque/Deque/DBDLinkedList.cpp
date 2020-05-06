#include "DBDLinkedList.h"

void ListInit(List* plist)
{
	Node* newHead = new Node;
	Node* newTail = new Node;
	newHead->prev = NULL;
	newHead->next = newTail;
	newTail->prev = newHead;
	newTail->next = NULL;
	plist->head = newHead;
	plist->tail = newTail;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)	// 꼬리에 노드를 추가한다.
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = plist->tail->prev;
	newNode->prev->next = newNode;
	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head->next == plist->tail)
		return FALSE;
	
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur == NULL || plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur == NULL || plist->cur->prev == plist->head)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List* plist)		// 앞서 참조가 이뤄진 노드를 삭제한다.
{
	Node* rnode = plist->cur;
	Data rdata = plist->cur->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;
	delete rnode;

	(plist->numOfData)--;

	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}