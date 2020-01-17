#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename Type>
class Max
{
private:
	Type m_tType1;
	Type m_tType2;
	Type m_tType3;
public:
	void Calc();
	Max(Type t1, Type t2, Type t3);
	~Max();
};

