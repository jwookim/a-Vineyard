#include "Character.h"

Character::Character()
{
	//SetSpeed(STANDARD_SPEED);
}

void Character::Attack(Character* target)
{

}

void Character::TimeCheck()
{
	BuffCheck();
	DebuffCheck();
}

void Character::AddBuff(Buff* buff)
{
	m_Buff.push_back(buff);
	buff->SetStartTime(clock());
	switch (buff->GetBuff())
	{
	case B_CATEGORY_ATTACK_UP:
		m_iAtk += buff->GetValue();
		break;
	case B_CATEGORY_SPEED_UP:
		SetSpeed(GetSpeed() + buff->GetValue());
		break;
	}
}

void Character::AddDebuff(Debuff* debuff)
{
	m_Debuff.push_back(debuff);
	debuff->SetStartTime(clock());
	switch (debuff->GetDebuff())
	{
	case D_CATEGORY_SLOW:
		SetSpeed(GetSpeed() - debuff->GetValue());
	}
}

void Character::BuffCheck()
{
	list<Buff*>::iterator iter;
	if (!m_Buff.empty())
	{
		for (iter = m_Buff.begin(); iter != m_Buff.end(); ++iter)
		{
			if ((*iter)->TimeCheck() == false)
			{
				switch ((*iter)->GetBuff())
				{
				case B_CATEGORY_ATTACK_UP:
					m_iAtk -= (*iter)->GetValue();
					break;
				case B_CATEGORY_SPEED_UP:
					SetSpeed(GetSpeed() - (*iter)->GetValue());
					break;
				}
				delete *iter;
				m_Buff.remove(*iter);
			}
		}
	}
}

void Character::DebuffCheck()
{
	list<Debuff*>::iterator iter;
	if (!m_Debuff.empty())
	{
		for (iter = m_Debuff.begin(); iter != m_Debuff.end(); ++iter)
		{
			if ((*iter)->TimeCheck() == false)
			{
				switch ((*iter)->GetDebuff())
				{
				case D_CATEGORY_SLOW:
					SetSpeed(GetSpeed() + (*iter)->GetValue());
				}
				delete *iter;
				m_Debuff.remove(*iter);
			}
		}
	}
}
