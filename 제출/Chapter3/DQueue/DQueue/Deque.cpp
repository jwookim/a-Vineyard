#include "Deque.h"


void DequeInit(Deque * pdeq)
{
	Node* newNode = new Node;
	newNode->prev = NULL;
	pdeq->head = newNode;
	newNode = NULL;

	newNode = new Node;
	newNode->next = NULL;
	pdeq->tail = newNode;

	pdeq->head->next = pdeq->tail;
	pdeq->tail->prev = pdeq->head;
}

int DQIsEmpty(Deque * pdeq)
{
	if (pdeq->head->next == pdeq->tail)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = pdeq->head;
	newNode->next = pdeq->head->next;

	pdeq->head->next->prev = newNode;
	pdeq->head->next = newNode;
}

void DQAddLast(Deque * pdeq, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = pdeq->tail->prev;
	newNode->next = pdeq->tail;

	pdeq->tail->prev->next = newNode;
	pdeq->tail->prev = newNode;
}

Data DQRemoveFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq) == FALSE)
	{
		Data rdata = pdeq->head->next->data;
		Node* rnode = pdeq->head->next;

		pdeq->head->next->next->prev = pdeq->head;
		pdeq->head->next = pdeq->head->next->next;
		delete rnode;

		return rdata;
	}
	else
		return NULL;
}

Data DQRemoveLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq) == FALSE)
	{
		Data rdata = pdeq->tail->prev->data;
		Node* rnode = pdeq->tail->prev;

		pdeq->tail->prev->prev->next = pdeq->tail;
		pdeq->tail->prev = pdeq->tail->prev->prev;
		delete rnode;

		return rdata;
	}
	else
		return NULL;
}

Data DQGetFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq) == FALSE)
		return pdeq->head->next->data;
	else
		return NULL;
}

Data DQGetLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq) == FALSE)
		return pdeq->tail->prev->data;
	else
		return NULL;
}
