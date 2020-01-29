#pragma once
#include"Add.h"
#include"Max.h"
#include"Min.h"
#include <conio.h>

void main()
{
	Add<int> add;
	Min<int> min;
	Max<int> max;

	add.Input();

	cout << "더하고 싶은 만큼 <Enter> 키를 눌러주세요 (다른 키를 누르면 종료됩니다.)" << endl;

	while (getch() != 13)
		add.add();

	add.Print();

	min.Input();
	min.Calc();

	max.Input();
	max.Calc();
}