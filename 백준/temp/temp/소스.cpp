#include<iostream>
using namespace std;

int main()
{
	int x[4], y[4];

	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	int check;

	for (int i = 0; i < 3; i++)
	{
		check = 0;
		for (int j = i + 1; j < 3 && check == 0; j++)
		{
			if (x[i] == x[j])
				check++;
		}

		if (check == 0)
		{
			x[3] = x[i];
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		check = 0;
		for (int j = i + 1; j < 3 && check == 0; j++)
		{
			if (y[i] == y[j])
				check++;
		}

		if (check == 0)
		{
			y[3] = y[i];
			break;
		}
	}
	
	cout << x[3] << " " << y[3];

	return 0;
}