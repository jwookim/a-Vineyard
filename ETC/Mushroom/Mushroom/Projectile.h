#pragma once
#include"MovingObject.h"
class Projectile : public MovingObject
{
private:
	MovingObject* m_Caster;
	int m_iValue;
public:
	bool MoveCheck();
	void SetCaster(MovingObject caster);
	void SetValue(int value);
	inline MovingObject* GetCaster()
	{
		return m_Caster;
	}
};

