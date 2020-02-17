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
	MapDraw DrawManager;
public:
	void Show(int line);
	void Load();
	void ListDown(int num);
	void Save(string name, int level, int score);
	Rank();
	~Rank();
};

