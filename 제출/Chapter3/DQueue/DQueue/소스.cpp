#include"Queue.h"

void main()
{
	Queue* q = new Queue;

	QInit(q);

	for (int i = 1; i <= 5; i++)
		Qpush(q, i);

	cout << Qpeek(q) << endl;

	while (QIsEmpty(q) == FALSE)
		cout << Qpop(q) << endl;

	delete q->head, q->tail, q;
}