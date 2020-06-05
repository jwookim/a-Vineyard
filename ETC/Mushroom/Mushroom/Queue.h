#pragma once
#include"List.h"


template<typename T>
class Queue
{
private:
	List<T> m_Queue;
public:
	void Push(T data);
	T Pop();
	T Peek();
	void Init();
};



template<typename T>
void Queue<T>::Push(T data)
{
	m_Queue.Insert(data);
}

template<typename T>
T Queue<T>::Pop()
{
	if (m_Queue.ToTail())
		return m_Queue.Remove();

	return NULL;
}



template<typename T>
T Queue<T>::Peek()
{
	if (m_Queue.ToTail())
		return m_Queue.ViewNode();

	return NULL;
}



template<typename T>
void Queue<T>::Init()
{
	while (m_Queue.GetNumOfData() > 0)
		Pop();
}

