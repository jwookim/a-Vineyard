#include "Queue.h"

void QInit(Queue* queue)
{
	DequeInit(queue);
}

int QIsEmpty(Queue * queue)
{
	return DQIsEmpty(queue);
}

void Qpush(Queue* queue, Data data)
{
	DQAddFirst(queue, data);
}

Data Qpop(Queue* queue)
{
	return DQRemoveLast(queue);
}

Data Qpeek(Queue* queue)
{
	return DQGetLast(queue);
}