#pragma once
#include<iostream>
#include<string>
#include"MapDraw.h"
using namespace std;

#define GAP 5

enum EFFECT
{
	EFFECT_NULL,
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
	MapDraw DrawManager;
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
	inline bool GetState()
	{
		return m_bState;
	}
	inline EFFECT GetEffect()
	{
		return m_Effect;
	}
	void SetName(string name);
	void Live();
	void Dead();
	void Drop();
	void Draw();
	void Erase();
	void Init();
	Word();
	~Word();
};

