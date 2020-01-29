#pragma once
#include"WordManager.h"

#define SCORE 33

class Play : public WordManager
{
private:
	string m_strName;
	int m_iScore;
	int m_iLife;
	string m_strInput;
public:
	void Menu();
	void Story();
	void Game();
	Play();
	~Play();
};

