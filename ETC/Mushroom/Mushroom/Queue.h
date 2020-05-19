#pragma once
#include"Position.h"

typedef Position Data;

typedef struct NODE
{
	Data data;
	Node* nextNode;
	Node* preNode;
}Node;

class Queue
{
private:
	Node* m_Head;
	Node* m_Tail;
	int m_iNumOfData;
public:
	Queue();
	void Push(Data data);
	Data Pop();
	Data Peek();
	void Init();
	~Queue();
};

