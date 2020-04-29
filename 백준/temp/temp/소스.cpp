#include<iostream>
using namespace std;
#define PI 3.14159265358979

int main()
{
	double r;
	cin >> r;

	printf("%.6lf\n", r*r*PI);
	printf("%.6lf\n", (r*r) * 2);
	return 0;
}