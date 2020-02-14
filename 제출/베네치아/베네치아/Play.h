#pragma once
#include"WordManager.h"
#include"MapDraw.h"
#include"Rank.h"
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
#define LVSCORE 800

class Play : public WordManager
{
private:
	string m_strName;
	int m_iScore;
	int m_iLife;
	int m_iStage;
	int m_iStunTime;
	int m_iEffectTime;
	bool m_bStun;
	EFFECT m_Effect;
	string m_strStory[LINE];
	MapDraw DrawManager;
	Rank m_Rank;
public:
	void Menu();
	void Story();
	void SetName();
	void Game();
	void Goal(int len);
	void WordCheck(EFFECT check);
	int DelayCheck(int delay);
	void EffectCheck();
	void LevelUp();
	void GameOver();
	void Save();
	void Init();
	bool InputWord();
	void DrawMap();
	void DrawAnswer();
	void ShowAll();
	void ShowLife();
	void ShowScore();
	void ShowName();
	void EraseLife();
	void EraseScore();
	void EraseName();
	void EraseAnswer();
	void ShowRank();
	Play();
	~Play();
};

