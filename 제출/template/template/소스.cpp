#include <conio.h>
#include"Add.h"
#include"Max.h"
#include"Min.h"
#include"Add.cpp"
#include"Max.cpp"
#include"Min.cpp"


void main()
{
	int num1, num2, num3;
	cout << "더할 값을 입력하세요 : ";
	cin >> num1;

	Add<int> add(num1);

	cout << "더하고 싶은 만큼 <Enter> 키를 눌러주세요 (다른 키를 누르면 종료됩니다.)" << endl;

	while (getch() == 13)
	{
		add.add();

		add.Print();
	}

	cout << "(최소값) 비교할 두 수를 입력하세요 : ";
	cin >> num1 >> num2;

	Min<int> min(num1, num2);

	min.Calc();


	cout << "(최대값) 비교할 세 수를 입력하세요 : ";
	cin >> num1 >> num2 >> num3;

	Max<int> max(num1, num2, num3);

	max.Calc();
}

//컴파일을 해 볼 경우 문제가 발생한다.
//이는 템플릿 클래스가 서로 다른 소스파일에 담겨있기 때문인데,
//헤더와 소스를 파일단위로 컴파일하면서 서로 참조하고 있지 않아 문제가 발생한다.
//해결책으로는 '헤더에 템플릿 Point의 생성자와 멤버함수의 정의를 모두 넣는다' 가 한 방법이 될 수 있고,
//이것이 싫다면 main 소스 파일에 #include 문을 하나 더 추가하여 Point 템플릿 클래스의 소스(.cpp) 파일을 가져와야 한다.
//후자의 방법은 조금 이상할 수 있으나, 템플릿의 경우에는 모든 정보를 소스파일에 전달해야 하기 때문에 그렇게 해야 한다.