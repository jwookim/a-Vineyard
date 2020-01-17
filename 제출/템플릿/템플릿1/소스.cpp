#include<iostream>
using namespace std;

template <typename Num>
void add(Num a)
{
	cout << a << " + 1 = " << a + 1 << endl;
}

template <typename Num>
void min(Num a, Num b)
{
	cout << "최소값 : ";
	if (a <= b)
		cout << a << endl;
	else
		cout << b << endl;
}

template <typename Num>
void max(Num a, Num b, Num c)
{
	Num tmp = a;

	if (tmp < b)
		tmp = b;
	if (tmp < c)
		tmp = c;
	cout << "최대값 : " << tmp << endl;
}

void main()
{
	int Num1, Num2, Num3;

	cout << "증가시킬 값 입력 : ";
	cin >> Num1;

	add(Num1);

	cout << "비교할 두 값 입력 : ";
	cin >> Num1 >> Num2;

	min(Num1, Num2);

	cout << "비교할 세 값 입력 : ";
	cin >> Num1 >> Num2 >> Num3;

	max(Num1, Num2, Num3);
}