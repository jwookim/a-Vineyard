#pragma once
class Skill
{
private:
	int m_iCooldown;
public:
	virtual void Passive() = 0;
	virtual void Active() = 0;
};

