#pragma once
#include"Time.h"


enum B_CATEGORY
{
	B_CATEGORY_MELEE_ENHANCE,
	B_CATEGORY_ATTACK_UP,
	B_CATEGORY_SPEED_UP,
	B_CATEGORY_HIDING,
	B_CATEGORY_SHIELD
};

enum D_CATEGORY
{
	D_CATEGORY_STUN,
	D_CATEGORY_BLIND,
	D_CATEGORY_SLOW,
	D_CATEGORY_SILENCE
};

class State
{
private:
	int m_iDuration;
	int m_iValue;
	int m_iStartTime;
public:
	bool TimeCheck();
	inline int GetValue()
	{
		return m_iValue;
	}
	void SetStartTime(int time)
	{
		m_iStartTime = time;
	}
	void SetDuration(int dur)
	{
		m_iDuration = dur;
	}
	void SetValue(int val)
	{
		m_iValue = val;
	}
};

class Debuff : public State
{
private:
	D_CATEGORY m_Category;
public:
	inline D_CATEGORY GetDebuff()
	{
		return m_Category;
	}
	void SetCategory(D_CATEGORY debuff)
	{
		m_Category = debuff;
	}
};

class Buff : public State
{
private:
	B_CATEGORY m_Category;
public:
	inline B_CATEGORY GetBuff()
	{
		return m_Category;
	}
	void SetCategory(B_CATEGORY buff)
	{
		m_Category = buff;
	}
};

class Melee : public Buff
{
private:
	Debuff* m_Effect;
public:
	inline Debuff* GetEffect()
	{
		return m_Effect;
	}
	void SetEffect(Debuff* effect)
	{
		m_Effect = effect;
	}
};