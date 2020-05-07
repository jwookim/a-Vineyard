#include "Stack.h"


void StackInit(Stack* pstack)
{
	DequeInit(pstack);
}

int SIsEmpty(Stack* pstack)
{
	return DQIsEmpty(pstack);
}

void SPush(Stack* pstack, Data data)
{
	DQAddFirst(pstack, data);
}

Data SPop(Stack* pstack)
{
	return DQRemoveFirst(pstack);
}

Data SPeek(Stack* pstack)
{
	return DQGetFirst(pstack);
}