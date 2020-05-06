#pragma once
#include"CircularLinkedList.h"

class Stack
{
private:
	List* top;
public:
	Stack();
	int IsEmpty();
	void Push(LData data);
	LData Pop();
	LData Peek();
	~Stack();
};

