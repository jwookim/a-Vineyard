#include "Deque.h"


void DequeInit(Deque * pdeq)
{
	ListInit(pdeq);
}

int DQIsEmpty(Deque * pdeq)
{
	if (LCount(pdeq) == 0)
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

	(pdeq->numOfData)++;
}

void DQAddLast(Deque * pdeq, Data data)
{
	LInsert(pdeq, data);
}

Data DQRemoveFirst(Deque * pdeq)
{
	Data tmp;
	if (LFirst(pdeq, &tmp) == TRUE)
		return LRemove(pdeq);
	else
		return NULL;
}

Data DQRemoveLast(Deque * pdeq)
{
	Data tmp;
	if (LFirst(pdeq, &tmp) == TRUE)
	{
		while (LNext(pdeq, &tmp) == TRUE)
		{
		}
		return LRemove(pdeq);
	}
	else
		return NULL;
}

Data DQGetFirst(Deque * pdeq)
{
	Data tmp;
	if (LFirst(pdeq, &tmp) == TRUE)
		return tmp;
	else
		return NULL;
}

Data DQGetLast(Deque * pdeq)
{
	Data tmp;
	if (LFirst(pdeq, &tmp) == TRUE)
	{
		while (LNext(pdeq, &tmp) == TRUE)
		{
		}
		return tmp;
	}
	else
		return NULL;
}
