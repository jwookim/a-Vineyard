#pragma once
#include"MovingObject.h"
#include"Skill.h"
#include"State.h"

enum RANGE
{
	RANGE_MELEE,
	RANGE_LONG
};

typedef Position Direct;

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
	State* m_State;
public:
	Character();
	void TimeCheck();
	void Attack(/*Character* enemy*/);
	void Damage(int damage);
	void Death();
};

