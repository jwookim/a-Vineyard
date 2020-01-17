#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename Type>
class Min
{
private:
	Type m_tType1;
	Type m_tType2;
public:
	void Input();
	void Calc();
	Min();
	~Min();
};

