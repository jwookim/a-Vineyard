#pragma once
#include<iostream>
#include<string>
using namespace std;

class Word
{
private:
	string m_strName;
	int m_ix;
	int m_iy;
	Word* m_NextWord;
public:
	Word();
	~Word();
};

