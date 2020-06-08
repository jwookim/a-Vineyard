#pragma once
#include"MovingObject.h"
#include"Skill.h"
#include"State.h"
#include"List.h"
#include<conio.h>

#define ARROW 224
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

enum RANGE
{
	RANGE_MELEE,
	RANGE_LONG
};


class Character : public MovingObject
{
private:
	int m_iAtk;
	int m_iHealth;
	int m_iRegen;
	RANGE m_Range;
	Skill* m_P;
	Skill* m_Q;
	Skill* m_W;
	Skill* m_E;
	Skill* m_R;
	List<Buff*> m_Buff;
	List<Debuff*> m_Debuff;
public:
	Character();
	void TimeCheck();
	virtual void Attack(Character* enemy);
	void Damage(int damage, Buff* state = NULL);
	void Death();
	inline int GetAtk()
	{
		return m_iAtk;
	}
	inline int GetHealth()
	{
		return m_iHealth;
	}
	void SetP();
	void SetQ();
	void SetW();
	void SetE();
	void SetR();
	void SetAtk();
	void SetHealth();
	void SetRegen();
	void SetRange();
};

