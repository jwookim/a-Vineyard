#include<iostream>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int star(int num)
{
	cout << "***\n* *\n***";
	return 1;
}

int main()
{
	int num;

	cin >> num;

	
	cout << star(num);
	return 0;
}