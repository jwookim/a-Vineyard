#include "Character.h"

Character::Character()
{
	SetSpeed(STANDARD_SPEED);
}

void Character::TimeCheck()
{
	BuffCheck();
	DebuffCheck();
}

void Character::BuffCheck()
{
	if (m_Buff.First())
	{
		if (m_Buff.ViewNode()->TimeCheck() == false)
		{
			switch (m_Buff.ViewNode()->GetBuff())
			{
			case B_CATEGORY_ATTACK_UP:
				m_iAtk -= m_Buff.ViewNode()->GetValue();
				break;
			case B_CATEGORY_SPEED_UP:
				SetSpeed(GetSpeed() - m_Buff.ViewNode()->GetValue());
				break;
			}
			delete m_Buff.Remove();
		}

		while (m_Buff.Next())
		{
			if (m_Buff.ViewNode()->TimeCheck() == false)
			{
				switch (m_Buff.ViewNode()->GetBuff())
				{
				case B_CATEGORY_ATTACK_UP:
					m_iAtk -= m_Buff.ViewNode()->GetValue();
					break;
				case B_CATEGORY_SPEED_UP:
					SetSpeed(GetSpeed() - m_Buff.ViewNode()->GetValue());
					break;
				}
				delete m_Buff.Remove();
			}
		}
	}
}

void Character::DebuffCheck()
{
	if (m_Debuff.First())
	{
		if (m_Debuff.ViewNode()->TimeCheck() == false)
		{
			switch (m_Debuff.ViewNode()->GetDebuff())
			{
			case D_CATEGORY_SLOW:
				SetSpeed(GetSpeed() + m_Buff.ViewNode()->GetValue());
			}
			delete m_Debuff.Remove();
		}

		while (m_Debuff.Next())
		{
			if (m_Debuff.ViewNode()->TimeCheck() == false)
			{
				switch (m_Debuff.ViewNode()->GetDebuff())
				{
				case D_CATEGORY_SLOW:
					SetSpeed(GetSpeed() + m_Buff.ViewNode()->GetValue());
				}
				delete m_Debuff.Remove();
			}
		}
	}
}
