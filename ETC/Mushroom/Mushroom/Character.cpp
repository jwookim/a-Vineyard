#include "Character.h"

Character::Character(Position pos) : MovingObject(pos)
{
	m_bAlive = true;
	//SetSpeed(STANDARD_SPEED);
}

void Character::MeleeAttack(Character* target)
{

}

bool Character::AttackTimeCheck()
{
	if (clock() >= m_iAtkTime + ((STANDARD_CLOCK * 100) / m_iAtkSpeed))
		return true;
	return false;
}

void Character::Attack(Character* target)
{
	target->Damage(m_iAtk);

	list<Buff*>::iterator iter;

	for (iter = m_Buff.begin(); iter != m_Buff.end();)
	{
		if ((*iter)->GetBuff() == B_CATEGORY_MELEE_ENHANCE)
		{
			target->Damage((*iter)->GetValue());
			if (((Melee*)*iter)->GetEffect() != NULL)
				target->AddDebuff(((Melee*)*iter)->GetEffect());

			delete *iter;
			iter = m_Buff.erase(iter);
		}
		else
			iter++;
	}
}

void Character::Attack()
{
	if (m_Range == RANGE_LONG)
	{
		if (AttackTimeCheck())
		{
			Direct dir = GetDirect();
			Melee_p* newProj = new Melee_p(this);
			m_Projectile.push_back(newProj);
			m_iAtkTime = clock();
		}
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
		for (iter = m_Buff.begin(); iter != m_Buff.end();)
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
				iter = m_Buff.erase(iter);
			}
			else
				iter++;
		}
	}
}

void Character::DebuffCheck()
{
	list<Debuff*>::iterator iter;
	if (!m_Debuff.empty())
	{
		for (iter = m_Debuff.begin(); iter != m_Debuff.end();)
		{
			if ((*iter)->TimeCheck() == false)
			{
				switch ((*iter)->GetDebuff())
				{
				case D_CATEGORY_SLOW:
					SetSpeed(GetSpeed() + (*iter)->GetValue());
				}
				delete *iter;
				iter = m_Debuff.erase(iter);
			}
			else
				iter++;
		}
	}
}

void Character::Damage(int damage)
{
	m_iHealth -= damage;

	if (m_iHealth <= 0)
		Death();
}

void Character::Death()
{
	SetColor(GRAY);
	m_bAlive = false;

	Draw();
}

void Character::SetAtk(int atk)
{
	m_iAtk = atk;
}

void Character::SetHealth(int health)
{
	m_iHealth = health;
}

void Character::SetRegen(int regen)
{
	m_iRegen = regen;
}

void Character::SetRange(RANGE range)
{
	m_Range = range;
}

void Character::SetAtkSpeed(int speed)
{
	m_iAtkSpeed = speed;
}