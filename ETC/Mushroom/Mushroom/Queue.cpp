#include"Queue.h"

Position Queue<Position>::Pop()
{
	if (m_Queue.ToTail())
		return m_Queue.Remove();

	return { -1, -1 };
}

Position Queue<Position>::Peek()
{
	if (m_Queue.ToTail())
		return m_Queue.ViewNode();

	return { -1, -1 };
}