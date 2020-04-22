#include<iostream>
using namespace std;

int calc(int k, int n)
{
	if (k == 0)
		return n;
	else
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += calc(k - 1, i);
		return sum;
	}
}

int main()
{
	int t;
	cin >> t;
	int* k = new int[t];
	int* n = new int[t];

	for (int i = 0; i < t; i++)
		cin >> k[i] >> n[i];

	for (int i = 0; i < t; i++)
		cout << calc(k[i], n[i]) << endl;
	delete[] k, n;
}