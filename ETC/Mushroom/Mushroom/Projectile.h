#pragma once
#include"MovingObject.h"
class Projectile : public MovingObject
{
protected:
	MovingObject* m_Caster;
	int m_iDuration;
	int m_iCreatTime;
	int m_iValue;
	void(*m_Attack)(MovingObject* target);
public:
	Projectile(MovingObject* caster);
	bool MoveCheck();
	bool LifeCheck();
	void SetCaster(MovingObject* caster);
	void SetValue(int value);
	void AttackTarget(MovingObject* target);
	inline MovingObject* GetCaster()
	{
		return m_Caster;
	}
};

