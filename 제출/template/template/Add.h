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
	void add();
	void Print();
	Add(Type t);
	~Add();
};

