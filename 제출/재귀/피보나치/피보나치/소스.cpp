#include<iostream>
#include<string>
using namespace std;

void Fibo(int n1, int n2, int Cut)
{
	if (n1 + n2 <= Cut)
	{
		if (n1 + n2 == 0)
		{
			cout << "0" << endl << "1" << endl;
			Fibo(0, 1, Cut);
		}
		else
		{
			cout << n1 + n2 << endl;
			Fibo(n2, n1 + n2, Cut);
		}
	}

	/*if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);*/
}

void main()
{
	int n;
	cout << "피보나치 수열을 멈출 값을 입력하시오 : ";
	cin >> n;

	Fibo(0, 0, n);
}