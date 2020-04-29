#pragma once
#include"List.h"

template <typename Type>
class Stack
{
private:
	List* top; int size;
public:
	Stack();
	void push(Type a);
	void pop();
};

template <typename Type>
Stack<Type>::Stack()
{
	top = new List;
	ListInit(top);
}

template <typename T>
void Stack::push(T a) { *top = a; top++; }

template <typename Type>
void Stack::pop() { cout << *--top << endl; }

Stack::~Stack()
{
}
