#pragma once
#include"Object.h"
#include"Skill.h"

enum Direct
{
	DIRECT_UP,
	DIRECT_DOWN,
	DIRECT_LEFT,
	DIRECT_RIGHT
};

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
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Attack(Character* enemy);
	void Damage(int damage);
	void Death();
};

