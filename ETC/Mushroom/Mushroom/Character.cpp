#include "Character.h"

Character::Character()
{
	//SetSpeed(STANDARD_SPEED);
}

void Character::MeleeAttack(Character* target)
{

}

void Character::Attack(Character* target)
{

}

void Character::Attack()
{
	if (m_Range == RANGE_LONG)
	{
		Direct dir;
		Projectile* newProj = new Projectile(dir = GetDirect());
		newProj->SetPosition(GetPosition() + dir);
		newProj->SetSpeed(300);
		newProj->SetCaster(this);
		newProj->SetColor(GetColor());
		if (dir.x = 1)
			newProj->SetShape("กๆ");
		else if (dir.x = -1)
			newProj->SetShape("ก็");
		else if (dir.y = 1)
			newProj->SetShape("ก้");
		else if (dir.y = -1)
			newProj->SetShape("ก่");
		newProj->Draw();
		m_Projectile.push_back(newProj);
	}
	else if (m_Range == RANGE_CLOSE)
		;
}

void Character::TimeCheck()
{
	BuffCheck();
	DebuffCheck();
}

Projectile* Character::AttackCheck()
{
	if (!m_Projectile.empty())
	{
		Projectile* tmp = m_Projectile.front();
		m_Projectile.pop_front();
		return tmp;
	}

	return NULL;
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


void Character::SetRange(RANGE range)
{
	m_Range = range;
}