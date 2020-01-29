#pragma once
#include<iostream>
#include<string>
using namespace std;

#define STARTY 1
#define ENDY 50

#define STARTX 5
#define ENDX 45

enum EFFECT
{
	EFFECT_START,
	EFFECT_NORMAL = EFFECT_START,
	EFFECT_FAST,
	EFFECT_SLOW,
	EFFECT_PAUSE,
	EFFECT_CLEAR,
	EFFECT_HIDE,
	EFFECT_END = EFFECT_HIDE
};
class Word
{
private:
	string m_strName;
	int m_ix;
	int m_iy;
	bool m_bState;
	EFFECT m_Effect;
	Word* m_NextWord;
public:
	inline string GetName()
	{
		return m_strName;
	}
	inline int Getx()
	{
		return m_ix;
	}
	inline int Gety()
	{
		return m_iy;
	}
	inline Word* GetNextWord()
	{
		return m_NextWord;
	}
	void SetName(string name);
	void SetNextWord(Word* nextWord);
	void Drop();
	void Delete();
	Word();
	~Word();
};

