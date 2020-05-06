#pragma once
#include"Deque.h"

void main()
{
	Deque* deq = new Deque;
	DequeInit(deq);

	for (int i = 1; i <= 3; i++)
		DQAddFirst(deq, i);

	cout << DQGetFirst(deq) << endl << DQGetLast(deq) << endl;

	while (DQIsEmpty(deq) == FALSE)
		cout << DQRemoveFirst(deq) << endl;

	cout << endl;

	for (int i = 1; i <= 3; i++)
		DQAddLast(deq, i);

	cout << DQGetFirst(deq) << endl << DQGetLast(deq) << endl;

	while (DQIsEmpty(deq) == FALSE)
		cout << DQRemoveLast(deq) << endl;

	delete deq->head, deq->tail, deq;
}