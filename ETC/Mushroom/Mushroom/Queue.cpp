#include "Queue.h"

Queue::Queue() 
{
	Node* newHead = new Node;
	Node* newTail = new Node;

	m_Head = newHead;
	m_Head->preNode = NULL;

	m_Tail = newTail;
	m_Tail->nextNode = NULL;

	m_Head->nextNode = m_Tail;
	m_Tail->preNode = m_Head;

	m_iNumOfData = 0;
}

void Queue::Push(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->preNode = m_Head;
	newNode->nextNode = m_Head->nextNode;

	m_Head->nextNode->preNode = newNode;
	m_Head->nextNode = newNode;

	m_iNumOfData++;
}

Data Queue::Pop()
{
	if (m_iNumOfData > 0)
	{
		Node* rnode = m_Tail->preNode;
		Data rData = m_Tail->preNode->data;

		m_Tail->preNode->preNode->nextNode = m_Tail;
		m_Tail->preNode = m_Tail->preNode->preNode;

		delete rnode;

		m_iNumOfData--;

		return rData;
	}
	else
		return { -1, -1 };
}

Data Queue::Peek()
{
	if (m_iNumOfData > 0)
		return m_Tail->preNode->data;
	else
		return { -1, -1 };
}

void Queue::Init()
{
	while (m_iNumOfData > 0)
		Pop();
}

Queue::~Queue()
{
	Init();
	delete m_Head, m_Tail;
}
