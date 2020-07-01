#include "Projectile.h"

Projectile::Projectile(MovingObject* caster) : MovingObject(caster->GetPosition() + caster->GetDirect())
{
	m_Caster = caster;
	m_Direct = m_Caster->GetDirect();
	SetMoveTime(clock());
	m_iCreatTime = clock();
}


void Projectile::SetCaster(MovingObject* caster)
{
	m_Caster = caster;
}

bool Projectile::MoveCheck()
{
	if (MoveTimeCheck())
	{
		Move(GetDirect());
		return true;
	}
	return false;
}

bool Projectile::LifeCheck()
{
	if (m_iCreatTime + m_iDuration < clock())
		return false;
	
	return true;
}


void Projectile::AttackTarget(MovingObject* target)
{
	m_Attack(target);
}