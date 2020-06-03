#pragma once
#include"Object.h"
#include"Character.h"
class Trap : public Object
{
public:
	bool m_bDisposable;
private:
	inline bool GetDisPosable()
	{
		return m_bDisposable;
	}
	void SetDisPosable(bool dis);
	void Trigger(Character target);
};

