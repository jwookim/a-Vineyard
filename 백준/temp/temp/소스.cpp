#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int t, d;
	int x1, y1, r1, x2, y2, r2;
	int* n;

	cin >> t;

	n = new int[t];

	for (int i = 0; i < t; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			n[i] = -1;
			continue;
		}

		d = pow(x1 - x2, 2) + pow(y1 - y2, 2);

		if (pow(r1 + r2, 2) == d || pow(r1 - r2, 2) == d)
			n[i] = 1;
		else if (pow(r1 + r2, 2) < d || pow(r1 - r2, 2) < d)
			n[i] = 2;
		else
			n[i] = 0;
	}

	for (int i = 0; i < t; i++)
		cout << n[i] << endl;

	delete[] n;

	return 0;
}