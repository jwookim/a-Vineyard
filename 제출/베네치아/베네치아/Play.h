#pragma once
#include"WordManager.h"
#include<fstream>
#include<time.h>
#include<conio.h>
#include<Windows.h>

#define SCORE 33
#define LIFE 9
#define LINE 10
#define DELAY 1000
#define GAP 5
#define STUN 3000
#define SCOREMAX 1000
#define LVSCORE 200

class Play : public WordManager
{
private:
	string m_strName;
	int m_iScore;
	int m_iLife;
	int m_iStage;
	int m_iStunTime;
	bool m_bStun;
	string m_strStory[LINE];
public:
	void Menu();
	void Story();
	void Game();
	void Goal(int len);
	void WordCheck(bool check);
	void Init();
	Play();
	~Play();
};

