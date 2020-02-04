#pragma once
#include"WordManager.h"
#include<fstream>
#include<time.h>
#include<conio.h>
#include<Windows.h>

#define SCORE 33
#define LINE 10

class Play : public WordManager
{
private:
	string m_strName;
	int m_iScore;
	int m_iLife;
	string m_strStory[LINE];
	string m_strInput;
public:
	void Menu();
	void Story();
	void Game();
	void Init();
	void StoryLoad();
	Play();
	~Play();
};

