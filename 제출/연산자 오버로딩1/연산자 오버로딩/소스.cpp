#include<iostream>
using namespace std;


class Div
{
private:
	int x;
	int y;
public:
	Div()
	{
		x = 0;
		y = 0;
	}
	Div(int ix, int iy)
	{
		x = ix, y = iy;
	}
	void Print()
	{
		cout << "x = " << x << ", y = " << y << endl;
	}
	friend Div operator / (Div A, Div B);
};

Div operator / (Div A, Div B)
{
	cout << "°´Ã¼ / °´Ã¼" << endl;
	Div tmp;

	if (A.x >= B.x)
		tmp.x = A.x / B.x;
	else
		tmp.x = B.x / A.x;

	if (A.y >= B.y)
		tmp.y = A.y / B.y;
	else
		tmp.y = B.y / A.y;

	return tmp;
}

void main()
{
	Div A(10, 20);
	Div B(5, 40);
	Div C;

	A.Print();
	B.Print();

	C = A / B;

	C.Print();
}