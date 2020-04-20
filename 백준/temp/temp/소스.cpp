#include<iostream>
using namespace std;

int main()
{
	int num;
	int exp = 1;

	cin >> num;

	for (int i = 1; exp < num; i++)
	{
		exp += (i * 6) - 5;
	}
}