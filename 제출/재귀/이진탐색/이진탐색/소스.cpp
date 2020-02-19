#include<iostream>
#include<string>
using namespace std;


int BSearch(int arr[], int target, int startnum, int endnum)
{
	if (startnum <= endnum)
	{
		int mid = (startnum + endnum) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			return BSearch(arr, target, startnum, mid - 1);
		else
			return BSearch(arr, target, mid + 1, endnum);
	}
	else
		return -1;
}

void main()
{
	int num;
	int size;
	int target;
	cout << "배열로 만들고 싶은 배수를 입력하시오 : ";
	cin >> num;

	cout << "배열의 크기를 입력하시오 : ";
	cin >> size;

	int* Arr = new int[size];

	for (int i = 1; i <= size; i++)
		Arr[i] = num * i;

	cout << "찾고싶은 숫자를 입력하시오 : ";
	cin >> target;

	num = BSearch(Arr, target, 0, size - 1);

	if (num != -1)
	{
		cout << "해당 숫자는 배열의 " << num << "번째 숫자입니다." << endl;
	}
	else
		cout << "해당 숫자를 찾을 수 없습니다." << endl;
}