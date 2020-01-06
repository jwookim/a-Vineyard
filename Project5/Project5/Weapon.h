#pragma once
#include<iostream>
#include<string>
using namespace std;

class Weapon
{
protected:
	string m_strName;
	string m_strType;
	int m_iAtk;
	int m_iPrice;
public:
	virtual void Attack() = 0;
	Weapon();
	~Weapon();
};

