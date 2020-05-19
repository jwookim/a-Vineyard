#pragma once
#include"Object.h"
#include"Skill.h"

typedef Position Direct;

class Character : public Object
{
private:
	Direct m_Direct;
	int m_iAtk;
	int m_iHealth;
	int m_iSpeed;
	Skill* m_P;
	Skill* m_Q;
	Skill* m_W;
	Skill* m_E;
	Skill* m_R;
public:
	Character();
	void Attack(Character* enemy);
	void Damage(int damage);
	void Death();
};

