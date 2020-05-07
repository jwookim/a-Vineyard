#pragma once
#include"DBDLinkedList.h"

typedef List Deque;
void DequeInit(Deque * pdeq);
int DQIsEmpty(Deque * pdeq);
void DQAddFirst(Deque * pdeq, Data data);
void DQAddLast(Deque * pdeq, Data data);
Data DQRemoveFirst(Deque * pdeq);
Data DQRemoveLast(Deque * pdeq);
Data DQGetFirst(Deque * pdeq);
Data DQGetLast(Deque * pdeq);