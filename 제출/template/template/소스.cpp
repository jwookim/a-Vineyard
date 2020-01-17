#pragma once
#include <conio.h>
#include"Add.h"
#include"Max.h"
#include"Min.h"


void main()
{
	int num1, num2, num3;
	cout << "더할 값을 입력하세요 : ";
	cin >> num1;

	Add<int> add(num1);

	cout << "더하고 싶은 만큼 <Enter> 키를 눌러주세요 (다른 키를 누르면 종료됩니다.)" << endl;

	while (getch() != 13)
		add.add();

	add.Print();

	cout << "(최소값) 비교할 두 수를 입력하세요 : ";
	cin >> num1 >> num2;

	Min<int> min(num1, num2);

	min.Calc();


	cout << "(최대값) 비교할 세 수를 입력하세요 : ";
	cin >> num1 >> num2 >> num3;

	Max<int> max(num1, num2, num3);

	max.Calc();
}