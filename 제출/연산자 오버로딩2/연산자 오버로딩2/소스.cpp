#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Study
{
private:
	int m_iDay;
	int m_iHour;
	int m_iMinute;
public:
	Study()
	{
		m_iHour = 0;
		m_iMinute = 0;
		m_iDay = 1;
	}
	Study(int hour, int minute)
	{
		m_iHour = hour;
		m_iMinute = minute;
		while (m_iMinute >= 60)
		{
			m_iHour++;
			m_iMinute -= 60;
		}
		m_iDay = 1;
	}
	void ShowTime()
	{
		cout << " 총 공부 시간 : " << m_iHour << " : " << m_iMinute << endl;
		cout << "=====공부 시간 관리 프로그램(" << m_iDay << "Day)=====" << endl;
	}
	Study operator + (Study today);
};

Study Study::operator+(Study today)
{
	today.m_iHour += this->m_iHour;
	today.m_iMinute += this->m_iMinute;
	today.m_iDay += this->m_iDay;
	while (today.m_iMinute >= 60)
	{
		today.m_iHour++;
		today.m_iMinute -= 60;
	}
	return today;
}

void main()
{
	Study total;
	Study* today;
	int Select = 0;
	int hour;
	int minute;

	while (1)
	{
		system("cls");
		total.ShowTime();
		cout << "		1.시간 등록" << endl;
		cout << "		2.종료" << endl;
		cout << "		입력 : ";
		cin >> Select;

		switch (Select)
		{
		case 1:
			cout << "시간 : ";
			cin >> hour;
			cout << "분 : ";
			cin >> minute;
			today = new Study(hour, minute);
			total = total + *today;
			delete today;
			break;
		case 2:
			return;
		}
	}
}