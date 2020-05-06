#pragma once
#include"Deque.h"

typedef Deque Queue;

void QInit(Queue* queue);
int QIsEmpty(Queue * queue);
void Qpush(Queue* queue, Data data);
Data Qpop(Queue* queue);
Data Qpeek(Queue* queue);