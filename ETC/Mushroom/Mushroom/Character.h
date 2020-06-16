#pragma once
#include"MovingObject.h"
#include"Skill.h"
#include"State.h"
#include"Projectile.h"
#include<list>
#include<conio.h>

#define ARROW 224
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

enum RANGE
{
	RANGE_CLOSE,
	RANGE_LONG
};


class Character : public MovingObject
{
private:
	bool m_bAlive;
	int m_iAtk;
	int m_iHealth;
	int m_iRegen;
	int m_iAtkSpeed;
	int m_iAtkTime;
	RANGE m_Range;
	Skill* m_P;
	Skill* m_Q;
	Skill* m_W;
	Skill* m_E;
	Skill* m_R;
	list<Buff*> m_Buff;
	list<Debuff*> m_Debuff;
	list<Projectile*> m_Projectile;
public:
	Character();
	void TimeCheck();
	bool AttackTimeCheck();
	virtual Projectile* AttackCheck();
	virtual void MeleeAttack(Character* enemy);
	virtual void Attack(Character* enemy);
	virtual void Attack();
	void Damage(int damage);
	void Death();
	inline int GetAtk()
	{
		return m_iAtk;
	}
	inline int GetHealth()
	{
		return m_iHealth;
	}
	inline bool GetAlive()
	{
		return m_bAlive;
	}
	void SetAtkSpeed(int speed);
	void AddBuff(Buff* buff);
	void AddDebuff(Debuff* debuff);
	void BuffCheck();
	void DebuffCheck();
	void SetP();
	void SetQ();
	void SetW();
	void SetE();
	void SetR();
	void SetAtk(int atk);
	void SetHealth(int health);
	void SetRegen(int regen);
	void SetRange(RANGE range);
};

