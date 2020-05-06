#pragma once
#include"Stack.h"
#include<iostream>
using namespace std;

void main()
{
	Stack stack;

	int i;

	cin >> i;

	while (i != 0)
	{
		stack.Push(i);
		cin >> i;
	}

	cout << stack.Peek() << endl;
	cout << stack.Peek() << endl;

	while (stack.IsEmpty() != TRUE)
		cout << stack.Pop() << endl;
}