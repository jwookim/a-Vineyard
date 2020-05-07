#pragma once
#include"Stack.h"

void main()
{
	Stack* s = new Stack;

	StackInit(s);

	for (int i = 1; i <= 5; i++)
		SPush(s, i);

	cout << SPeek(s) << endl;

	while (SIsEmpty(s) == FALSE)
		cout << SPop(s) << endl;
}