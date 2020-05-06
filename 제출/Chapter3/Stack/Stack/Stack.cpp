#include "Stack.h"



Stack::Stack()
{
	top = new List;
	ListInit(top);
}

int Stack::IsEmpty()
{
	LData data;
	if (LFirst(top, &data) == TRUE)
		return FALSE;
	else
		return TRUE;
}

void Stack::Push(LData data)
{
	LInsert(top, data);
}

LData Stack::Pop()
{
	if (!IsEmpty())
		return LRemove(top);
	else
		return NULL;
}

LData Stack::Peek()
{
	LData data;
	if (LFirst(top, &data) == TRUE)
		return data;
	else
		return NULL;
}

Stack::~Stack()
{
	LData data;
	while (LFirst(top, &data) == TRUE)
		LRemove(top);
	delete top;
}
