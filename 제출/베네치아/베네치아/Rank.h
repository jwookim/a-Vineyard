#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"MapDraw.h"
using namespace std;

struct Info
{
	string name = "";
	int level = 0;
	int score = 0;
};

class Rank
{
private:
	Info m_Info[10];
public:
	void Show();
	void Load();
	void ListDown();
	void Save(string name, int level, int score);
	Rank();
	~Rank();
};

