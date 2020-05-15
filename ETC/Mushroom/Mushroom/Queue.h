#pragma once
#include"Position.h"

typedef struct NODE
{
	Position data;
	NODE* nextNode;
}Node;

class Queue
{
private:
	Node* m_Head;
public:
	Queue();
};

