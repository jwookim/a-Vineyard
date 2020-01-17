#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename Type>
class Add
{
private:
	Type m_tType;
public:
	void Input();
	void add();
	void Print();
	Add();
	~Add();
};

